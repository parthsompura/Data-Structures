from random import randint

class HashTable(object):

    def __init__(self):
        self.max_length = 8
        self.max_load_factor = 0.50
        self.length = 0
        self.table = [None] * self.max_length

    def __len__(self):
        return self.length

    def __setitem__(self, key, value):
        self.length += 1
        hashed_key = self._hash(key)
        h = 1
        while self.table[hashed_key] is not None:
            if self.table[hashed_key][0] == key:
                self.length -= 1
                break
            hashed_key = self._increment_key(hashed_key, h)
            h += 1
        tuple = (key, value)
        self.table[hashed_key] = tuple
        if self.length / float(self.max_length) >= self.max_load_factor:
            self._resize()

    def __getitem__(self, key):
        index = self._find_item(key)
        return self.table[index][1]

    def __delitem__(self, key):
        index = self._find_item(key)
        self.table[index] = None

    def _hash(self, key):
        # TODO more robust
        return hash(key) % self.max_length

    def _increment_key(self, key, h):
        return (key + h * h) % self.max_length

    def _find_item(self, key):
        hashed_key = self._hash(key)
        h = 1
        if self.table[hashed_key] is None:
            raise KeyError
        if self.table[hashed_key][0] != key:
            original_key = hashed_key
            while self.table[hashed_key][0] != key:
                hashed_key = self._increment_key(hashed_key, h)
                h += 1
                if self.table[hashed_key] is None:
                    raise KeyError
                if hashed_key == original_key:
                    raise KeyError
        return hashed_key

    def _resize(self):
        self.max_length *= 2
        self.length = 0
        old_table = self.table
        self.table = [None] * self.max_length
        for tuple in old_table:
            if tuple is not None:
                self[tuple[0]] = tuple[1]

    def __statistics__(self):
         #alpha = 0.50
        self.length = 0
        for tuple in self.table:
            if tuple is not None:
                self.length += 1
        #print(self.length, self.max_length)

        alpha = self.length / float(self.max_length)
        s_n = (1 + 1 / float(1 - alpha))/2
        u_n = (1 + 1 / float((1 - alpha)**2))/2
        m, n = self.max_length, self.length
        collisions = n - m * (1 - ((m-1)/m) ** n)
        print("\n****************Quadratic Probing*******************")
        print("Load factor:", self.max_load_factor)
        print("# elements or operations:", self.length)
        print("Key ranging from 0 to", self.max_length)
        print("Alpha:", alpha, "\n# of Successful searches:", s_n, "\n# of Unsuccessful searches:", u_n, "\nExpected # of collisions:", collisions)

    def print(self):
            print(self.table)


ht = HashTable()

for i in range(1000):
    ht.__setitem__(i,randint(i, 5 * i))


ht.print()

ht.__statistics__()
