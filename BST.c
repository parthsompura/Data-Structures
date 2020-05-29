#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct bst
{
    struct bst *left;
    int data;
    struct bst *right;
};
struct bst *root=NULL,*new_node=NULL;
void insert(struct bst *root,struct bst *new_node)
{
    if(new_node->data<root->data)
    {
        if(root->left==NULL)
        {
            root->left=new_node;
        }
        else
        {
            insert(root->left,new_node);
        }
    }
    else
    {
        if(root->right==NULL)
        {
            root->right=new_node;
        }
        else
        {
            insert(root->right,new_node);
        }
    }
}
void create()
{
    int ch;
    do
    {
        new_node=(struct bst*)malloc(sizeof(struct bst));
        printf("Enter new node data:");
        scanf("%d",&new_node->data);
        new_node->left=NULL;
        new_node->right=NULL;
        if(root==NULL)
        {
            root=new_node;
        }
        else
        {
            insert(root,new_node);
        }
        printf("Wants to create more nodes?(1 for yes/2 for no):");
        scanf("%d",&ch);
    }while(ch==1);
}
void preorder(struct bst *tmp)
{
    if(tmp!=NULL)
    {
        printf("%3d",tmp->data);
        preorder(tmp->left);
        preorder(tmp->right);
    }
}
void inorder(struct bst *tmp)
{
    if(tmp!=NULL)
    {
        inorder(tmp->left);
        printf("%3d",tmp->data);
        inorder(tmp->right);
    }
}
void postorder(struct bst *tmp)
{
    if(tmp!=NULL)
    {
        postorder(tmp->left);
        postorder(tmp->right);
        printf("%3d",tmp->data);
    }
}
/*int search(int data,struct bst *tmp)
{
    if(data==tmp->data)
    {
        // printf("Search Successful");
        return 1;
    }
    else if(data<tmp->data)
    {
        search(data,tmp->left);
    }
    else
    {
        search(data,tmp->right);
    }
    return -1;
}*/
void main()
{
    int ch,data,index;
    clrscr();
    while(1)
    {
        clrscr();
        printf("\n1.Create a BST");
        printf("\n2.Preorder");
        printf("\n3.Inorder");
        printf("\n4.Postorder");
        // printf("\n5.Search");
        printf("\n5.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                create();
                getch();
                break;
            case 2:
                preorder(root);
                getch();
                break;
            case 3:
                inorder(root);
                getch();
                break;
            case 4:
                postorder(root);
                getch();
                break;
        /*  case 5:
                printf("Enter elements to be searched:");
                scanf("%d",&data);
                index=search(data,root);
                if(index==1)
                {
                    printf("Search successful");
                }
                else
                {
                    printf("Search unsuccessful");
                }
                getch();
                break; */
            case 5:
                exit(0);
            default:
                printf("Invalid choice");
                getch();
                break;
        }
    }
}
