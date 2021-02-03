#include<stdio.h>
#include<stdlib.h>
#define max 5
int stack[max],top=-1;
void push()
{
        int ele;
        if(top<max-1)
        {
                printf("\nenter the value to be inserted");
                scanf("%d",&ele);
                stack[++top]=ele;
        }
        else
        printf("\nstack overflow");
}
void pop()
{
int ele;
if(top<0)
printf("\nstack underflow");
else
{
ele=stack[top--];
printf("\n%d is deleted",ele);
}
}
void disp()
{
        int ele,len=top;
        printf("the stack is ");
        while(len>=0)
        {
                ele=stack[len--];
                printf(" %d\n",ele);
        }
}
void palindrome()
{
        int i=0,len=top,flag=0;
        int stack1[max];
        while(len!=-1)
        {
                stack1[i]=stack[len--];
                i++;
        }
        for(i=0;i<top;i++)
        {
                if(stack1[i]!=stack[i])
                {
                flag=1;
                break;
                }
                }
        if(flag==0)
        printf(" stack is palindrome\n");
        else
        printf("stack is not a palindrome\n");
}
void main()
{
int ch;
while(1)
{
printf("enter 1 to push\nenter 2 to pop\nenter 3 to check palindrome\nenter 4 to display\nenter 5 to exit\n");
scanf("%d",&ch);
switch(ch)
{
case 1 : push();
                        break;
case 2 : pop();
                        break;
case 3 : palindrome();
                        break;
case 4 : disp();
                        break;
case 5 : exit(0);
default:printf("wrong choice");
}
}
}