#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define size 5
int stack[size];
int top=-1;
void push(int data)
{
    if(top==(size-1))
    {
        printf("stack overflow");
    }
    else
    {
        top++;
        stack[top]=data;
    }
}
int pop()
{
    int value;
    if(top==-1)
    {
        printf("stack underflow");
    }
    else
    {
        value=stack[top];
        top--;
    }
    return value;
}
void peep(int search_ele)
{
    int i,flag=0;
    if(top==-1)
    {
        printf("stack underflow");
    }
    else
    {
        for(i=top;i>=0;i--)
        {
            if(search_ele==stack[i])
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
void change(int update_ele,int new_ele)
{
    int i;
    if(top==-1)
    {
        printf("stack underflow");
    }
    else
    {
        for(i=top;i>=0;i--)
        {
            if(update_ele==stack[i])
            {
                stack[i]=new_ele;
            }
        }
    }
}
void display()
{
    int i;
    if(top==-1)
    {
        printf("stack underflow");
    }
    else
    {
        for(i=top;i>=0;i--)
        {
            printf("\n%d",stack[i]);
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
        printf("\n\n**********STACK DATA STRUCTURE**********\n");

        printf("\n1.PUSH\n2.POP\n3.PEEP\n4.CHANGE\n5.DISPLAY\n6.EXIT\n");
        printf("Enter your choice::");
        scanf("%d",&ch);
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
    }
}
