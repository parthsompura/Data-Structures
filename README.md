# Data Structures
Stack, Queue, Linked List & Binary Search Tree
This code helps you to understand the different Data structures. The data structures depicted in this code are:

1. Stack
2. Queue
3. Linked List
4. Binary Search Tree

### Sourcerer

### Code Requirements
The example code is in C ([version 3.2](https://archive.codeplex.com/?p=turboc) or higher will work).

### Description
In computer science, a data structure is a data organization, management, and storage format that enables efficient access and modification. More precisely, a data structure is a collection of data values, the relationships among them, and the functions or operations that can be applied to the data.

For more information, [see](https://en.wikipedia.org/wiki/Data_structure)

## Stack
![stack](stack.gif)
```c
switch(ch)
        {
            case 1:
                printf("Enter the element to be pushed::");
                scanf("%d",&value);
                push(value);
                getch();
                break;
            case 2:
                value=pop();
                printf("The poped element is::%d",value);
                getch();
                break;
            case 3:
                printf("Enter the element to be searched::");
                scanf("%d",&value);
                peep(value);
                getch();
                break;
            case 4:
                printf("Enter the element to be updated::");
                scanf("%d",&value);
                printf("Enter new value::");
                scanf("%d",&new_ele);
                change(value,new_ele);
                getch();
                break;
            case 5:
                display();
                getch();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice");
                getch();
                break;
        }
```        
## Queue
![queue](queue.gif)
```c
switch(ch)
        {
            case 1:
                printf("Enter the element to be inserted::");
                scanf("%d",&value);
                insert(value);
                getch();
                break;
            case 2:
                value=remove1();
                printf("The removed element is::%d",value);
                getch();
                break;
            case 3:
                printf("Enter the element to be searched::");
                scanf("%d",&value);
                search(value);
                getch();
                break;
            case 4:
                printf("Enter the element to be updated::");
                scanf("%d",&value);
                printf("Enter new value::");
                scanf("%d",&new_ele);
                update(value,new_ele);
                getch();
                break;
            case 5:
                display();
                getch();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice");
                getch();
                break;
        }
```
## Linked List
![linked_list1](linked_list1.gif)
![linked_list2](linked_list2.gif)
![linked_list3](linked_list3.gif)
![linked_list4](linked_list4.gif)
