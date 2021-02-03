#include<stdio.h>
#include<stdlib.h>
#define size 5
char q[size];
int front=-1,rear=-1;
void insert();
void delete();
void display();
void main()
{
	int ch;
	while(1)
	{
		printf("\n 1.Insert\n 2.Delete\n 3.Display\n 4.Exit\n");
		printf(" Enter your choice\n");
		scanf(" %d",&ch);
		switch(ch)
		{
			case 1:insert();
			break;
			case 2:delete();
			break;
			case 3:display();
			break;
			case 4:exit(0);
			default:printf("invalid choice");
		}
	}
}
void insert()
{
	char item;
	printf("enter the element to be inserted to the queue\n");
	scanf(" %c",&item);
	if(front==(rear+1)%size)
		printf("\n Queue is overflow!\n");
	else
	{
		if(front==-1)
			front=rear=0;
		else
			rear=(rear+1)%size;
	q[rear]=item;
	printf("insertion succesful");
	}
}
void display()
{
int i;
if(front==-1)
printf("queue is empty\n");
else
{
for(i=front;i!=rear;i=(i+1)%size)
printf("q[%d]= %c\n",i,q[i]);
printf("q[%d]= %c\n",i,q[i]);
}
}
void delete()
{
char del_item=0;
if(front==-1)
printf("queue is empty!");
else
{
del_item=q[front];
printf("\n element deleted from the queue is %c at pos=%d\n",del_item,front);
if(front==rear)
front=rear=-1;
else
front=(front+1)%size;
}
}
