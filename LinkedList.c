#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct list
{
    int data;
    struct list *next;
};
struct list *start=NULL,*node=NULL;
void create()
{
    char ch;
    start=(struct list*)malloc(sizeof(struct list));
    printf("Enter node data::");
    scanf("%d",&start->data);
    start->next=NULL;
    printf("Wants to create more nodes?(y/n)::");
    fflush(0);
    scanf("%c",&ch);
    node=start;
    while(ch!='n')
    {
        node->next=(struct list*)malloc(sizeof(struct list));
        node=node->next;
        printf("Enter node data::");
        scanf("%d",&node->data);
        node->next=NULL;
        printf("Wants to create more nodes?(y/n)::");
        fflush(0);
        scanf("%c",&ch);
    }
}
void display()
{
    if(start==NULL)
    {
        printf("Linked list is empty");
    }
    else
    {
        node=start;
        while(node!=NULL)
        {
            printf("\n%d",node->data);
            node=node->next;
        }
    }
}
void insert_begining_singly_ll()
{
    struct list *new_node=NULL;
    new_node=(struct list*)malloc(sizeof(struct list));
    printf("Enter new node data::");
    scanf("%d",&new_node->data);
    new_node->next=start;
    start=new_node;
}
void insert_end_singly_ll()
{
    struct list *new_node=NULL;
    new_node=(struct list*)malloc(sizeof(struct list));
    printf("Enter new node data::");
    scanf("%d",&new_node->data);
    node=start;
    while(node->next!=NULL)
    {
        node=node->next;
    }
    node->next=new_node;
    new_node->next=NULL;
}
void insert_after_desirednode_singly_ll()
{
    struct list *new_node=NULL;
    int data;
    printf("Enter desired node data::");
    scanf("%d",&data);
    node=start;
    while(node!=NULL)
    {
        if(data==(node->data))
        {
            new_node=(struct list*)malloc(sizeof(struct list));
            printf("Enter new node data::");
            scanf("%d",&new_node->data);
            new_node->next=node->next;
            node->next=new_node;
            break;
        }
        else
        {
            node=node->next;
        }
    }
}
void insert_after_desiredposition_singly_ll()
{
    struct list *new_node=NULL;
    int i=1,pos;
    printf("Enter desired position::");
    scanf("%d",&pos);
    node=start;
    while(node!=NULL)
    {
        if(pos==i)
        {
            new_node=(struct list*)malloc(sizeof(struct list));
            printf("Enter new node data::");
            scanf("%d",&new_node->data);
            new_node->next=node->next;
            node->next=new_node;
            break;
        }
        else
        {
            node=node->next;
            i++;
        }
    }
}
void delete_first_singly_ll()
{
    node=start;
    start=node->next;
    free(node);
}
void delete_last_singly_ll()
{
    node=start;
    while(node->next->next!=NULL)
    {
        node=node->next;
    }
    free(node->next);
    node->next=NULL;
}
void delete_desired_node_singly_ll()
{
    struct list *prev=NULL/*,*tmp=NULL*/;
    int data;
    printf("Enter desired node data::");
    scanf("%d",&data);
    prev=start;
    node=start->next;
    while(node!=NULL)
    {
        if(data==node->data)
        {
            prev->next=node->next;
            free(node);
            node=prev->next;
        }
        else
        {
            node=node->next;
            prev=prev->next;
        }
    }
    /*
    tmp=start;
    while(tmp!=NULL&&tmp->data==data)
    {
        start=tmp->next;
        free(tmp);
        tmp=start;
    }
    tmp=start;
    while(tmp!=NULL)
    {
        while(tmp!=NULL&&tmp->data!=data)
        {
            prev=tmp;
            tmp=tmp->next;
        }
        if(tmp==NULL)
        {
            break;
        }
        prev->next=tmp->next;
        free(tmp);
        tmp=prev->next;
    }*/
}
void delete_before_desired_position_singly_ll()
{
    struct list *prev=NULL;
    int i=1,pos;
    printf("Enter the desired node position before which you want to
    delete::");
    scanf("%d",&pos);
    prev=start;
    node=start->next;
    if(pos==2)
    {
        delete_first_singly_ll();
    }
    else
    {
        while(node!=NULL)
        {
            if(i==(pos-2))
            {
                prev->next=node->next;
                free(node);
                break;
            }
            else
            {
                node=node->next;
                prev=prev->next;
                i++;
            }
        }
    }
}
void delete_after_desired_position_singly_ll()
{
    struct list *prev=NULL;
    int i=1,pos;
    printf("Enter desired position after which node is to be deleted::");
    scanf("%d",&pos);
    prev=start;
    node=start->next;
    while(node!=NULL)
    {
        if(i==pos)
        {
            prev->next=node->next;
            free(node);
            break;
        }
        else
        {
            node=node->next;
            prev=prev->next;
            i++;
        }
    }
}
void delete_desired_position_singly_ll()
{
    struct list *prev=NULL;
    int i=1,pos;
    printf("Enter the desired node position at which you want to delete::");
    scanf("%d",&pos);
    prev=start;
    node=start->next;
    while(node!=NULL)
    {
        if(i==(pos-1))
        {
            prev->next=node->next;
            free(node);
            break;
        }
        else
        {
            node=node->next;
            prev=prev->next;
            i++;
        }
    }
}
void ascendingSort()
{
    struct list *node1=NULL;
    int tmp;
    for(node=start;node!=NULL;node=node->next)
    {
        for(node1=node->next;node1!=NULL;node1=node1->next)
        {
            if(node->data>node1->data)
            {
                tmp=node->data;
                node->data=node1->data;
                node1->data=tmp;
            }
        }
    }
}
int maximum()
{
    int max=0;
    for(node=start;node!=NULL;node=node->next)
    {
        if(node->data>max)
        {
            max=node->data;
        }
    }
    return max;
}
void main()
{
    int ch,flag=0;
    clrscr();
    while(1)
    {
        clrscr();
        printf("\n**********Singly Linked list**********\n\n");
        printf("\n1.Create a linked list\n2.Display");
        printf("\n3.Insert new node at begining of linked list");
        printf("\n4.Insert new node at end of linked list");
        printf("\n5.Insert new node after desired node data");
        printf("\n6.Insert new node after desired position");
        printf("\n7.Delete first node of linked list");
        printf("\n8.Delete last node of linked list");
        printf("\n9.Delete desired node data");
        printf("\n10.Delete node before desired position");
        printf("\n11.Delete node after desired position");
        printf("\n12.Delete node at desired position");
        printf("\n13.Recreate");
        printf("\n14.Ascending order");
        printf("\n15.Find maximum number from list");
        printf("\n16.exit");
        printf("\nEnter your choice::");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                if(flag==0)
                {
                    flag=1;
                    create();
                }
                else
                {
                    printf("\nLinked list is already created
                    if you want then press 13");
                }
                getch();
                break;
            case 2:
                display();
                getch();
                break;
            case 3:
                insert_begining_singly_ll();
                getch();
                break;
            case 4:
                insert_end_singly_ll();
                getch();
                break;
            case 5:
                insert_after_desirednode_singly_ll();
                getch();
                break;
            case 6:
                insert_after_desiredposition_singly_ll();
                getch();
                break;
            case 7:
                delete_first_singly_ll();
                getch();
                break;
            case 8:
                delete_last_singly_ll();
                getch();
                break;
            case 9:
                delete_desired_node_singly_ll();
                getch();
                break;
            case 10:
                delete_before_desired_position_singly_ll();
                getch();
                break;
            case 11:
                delete_after_desired_position_singly_ll();
                getch();
                break;
            case 12:
                delete_desired_position_singly_ll();
                getch();
                break;
            case 13:
                create();
                getch();
                break;
            case 14:
                ascendingSort();
                getch();
                break;
            case 15:
                printf("Maximum number is %d",maximum());
                getch();
                break;
            case 16:
                exit(0);
            default:
                printf("Invalid choice");
                getch();
                break;
        }
    }
}
