#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define size 5
int queue[size];
int rear=-1,front=-1;
void insert(int data)
{
    if(rear==(size-1)&&front==0)
    {
        printf("queue overflow");
    }
    else if(rear==-1&&front==-1)
    {
        rear=0;
        front=0;
        queue[rear]=data;
    }
    else
    {
        rear++;
        queue[rear]=data;
    }
}
int remove1()
{
    int value;
    if(rear==-1&&front==-1)
    {
        printf("queue underflow");
    }
    else if(rear==front)
    {
        value=queue[front];
        front=-1;
        rear=-1;
    }
    else
    {
        value=queue[front];
        front++;
    }
    return value;
}
void search(int search_ele)
{
    int i,flag=0;
    if(rear==-1&&front==-1)
    {
        printf("queue underflow");
    }
    else
    {
        for(i=front;i<=rear;i++)
        {
            if(search_ele==queue[i])
            {
                flag=1;
                break;
            }
        }
    }
    if(flag==1)
    {
        printf("search successful");
    }
    else
    {
        printf("search unsuccessful");
    }
}
void update(int update_ele,int new_ele)
{
    int i;
    if(rear==-1&&front==-1)
    {
        printf("queue underflow");
    }
    else
    {
        for(i=front;i<=rear;i++)
        {
            if(update_ele==queue[i])
            {
                queue[i]=new_ele;
            }
        }
    }
}
void display()
{
    int i;
    if(rear==-1&&front==-1)
    {
        printf("queue underflow");
    }
    else
    {
        for(i=front;i<=rear;i++)
        {
            printf("\n%d",queue[i]);
        }
    }
}
void main()
{
    int ch,value,new_ele;
    clrscr();
    while(1)
    {
        clrscr();
        printf("\n\n**********QUEUE DATA STRUCTURE**********\n");

        printf("\n1.INSERT\n2.REMOVE\n3.SEARCH\n4.UPDATE\n5.DISPLAY\n6.EXIT\n");
        printf("Enter your choice::");
        scanf("%d",&ch);
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
    }
}
