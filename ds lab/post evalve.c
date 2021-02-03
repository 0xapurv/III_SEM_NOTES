#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAX 50

int stack[MAX];
char post[MAX];
int top=-1;

void pushstack(int tmp);
void calculator(char c);
void main()
{
int i;
printf("Insert  a postfix notation:\n");
scanf("%s",post);
for(i=0;i<strlen(post);i++)
{
if(post[i]>='0'&& post[i]<='9')
{
pushstack(i);
}
if(post[i]=='+'||post[i]=='-'||post[i]=='*'||post[i]=='/'||post[i]=='^')
{
calculator(post[i]);
}
}
printf(" Result=%d\n",stack[top]);
}

void pushstack(int tmp)
{
top++;
stack[top]=(int)(post[tmp]-48);
}

void calculator(char c)
{
int a,b,ans;
b=stack[top];
stack[top]='\0';
top--;
a=stack[top];
stack[top]='\0';
top--;

switch(c)
{
case'+':
ans=a+b;
break;
case'-':
ans=a-b;
break;
case'*':
ans=a*b;
break;
case'/':
ans=a/b;
break;
case'^':
ans=pow(a,b);
break;
default:ans=0;
}
top++;
stack[top]=ans;
}
