#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct student
{
	char usn[15];
	char name[25];
	char branch[25];
	int sem;
	long int phone_no;
	struct student*link;
};
typedef struct student STUD;
STUD*read_data()
{
	STUD*temp;
	temp=(STUD*)malloc(sizeof(STUD));
	printf("enter the students details:\n");
	printf("enter usn:\n");
	scanf("%s",temp->usn);
	printf("enter name\n");
	scanf("%s",temp->name);
	printf("enter branch\n");
	scanf("%s",temp->branch);
	printf("enter semester\n");
	scanf("%d",&temp->sem);
	printf("enter phone no.\n");
	scanf("%lu",&temp->phone_no);
	temp->link=NULL;
	return temp;
}
STUD*insert_front(STUD*first)
{
	STUD*temp;
	temp=read_data();
	temp->link=first;
	return temp;
}
STUD*insert_end(STUD*first)
{
	STUD*temp,*prev;
	temp=read_data();
	if(first==NULL)
	return temp;
	prev=first;
	while(prev->link!=NULL)
	prev=prev->link;
	prev->link=temp;
	return first;
}
STUD*delete_front(STUD*first)
{
	STUD*cur;
	if(first==NULL)
	{
		printf("list is empty\n");
		return first;
	}
	cur=first;
	first=first->link;
	free(cur);
	return first;
}
STUD*delete_end(STUD*first)
{
	STUD*prev,*cur;
	if(first==NULL)
	{
		printf("list is empty\n");
		return first;
	}
	prev=NULL;
	cur=first;
	while(cur->link!=NULL)
	{
		prev=cur;
		cur=cur->link;
	}
	prev->link=NULL;
	free(cur);
	return first;
}
void display(STUD*first)
{
	STUD*temp;
	int count=0;
	if(first==NULL)
	{
		printf("list is empty\n");
		return;
	}
	printf("usn\tname\tbranch\tsem\tphone_no\n");
	temp=first;
	while(temp!=NULL)
	{
		printf("%s\t%s\t%s\t%d\t%lu\n",temp->usn,temp->name,temp->branch,temp->sem,temp->phone_no);
		temp=temp->link;
		count++;
	}
	printf("the no.of nodes in SLL=%d\n",count);
}
void main()
{
	int ch,i,n;
	STUD*first=NULL;
	printf("creation of SLL of students\n");
	printf("enter the no.of students\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	first=insert_front(first);
	printf("SLL created successfully\n");
	display(first);
	while(1)
	{
		printf("1.display\t2.insert.end\t3.delete.end\t4.insert.front\t5.delete.front\t6.exit\n");
		printf("enter the choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: display(first);
			break;
			case 2: first=insert_end(first);
			printf("node inserted at the end\n");
			break;
			case 3: first=delete_end(first);
			printf("node deleted at the end\n");
			break;
			case 4: first=insert_front(first);
			printf("node inserted at front\n");
			break;
			case 5: first=delete_front(first);
			printf("node deleted at front\n");
			break;
			case 6:	printf("thank you");
				exit(0);
			break;
			default:printf("invalid choice\n");
		}
	}
}