#include<stdio.h>
#include<stdlib.h>
struct node
{
char ssn[10],name[10],dept[15],desig[15];
long int phno;
float sal;
struct node *llink;
struct node *rlink;
};
typedef struct node *NODE;
NODE temp, FIRST=NULL, END=NULL;
NODE getnode()
{
NODE x;
x=(NODE)malloc(sizeof(struct node));
return x;
}
void read()
{
//float sal; int phno;
temp=getnode();
temp->llink=NULL;
temp->rlink=NULL;
printf("Enter SSN");
scanf("%s",temp->ssn);
printf("Enter NAME");
scanf("%s",temp->name);
printf("Enter dept:");
scanf("%s",temp->dept);
printf("Enter designation:");
scanf("%s",temp->desig);
printf("Enter phno");
scanf("%ld",&temp->phno);
printf("Enter salary");
scanf("%f",&temp->sal);
}
void Insertionend( )
{
printf("enter the deatils of the new employee\n");
read();
if(FIRST==NULL)
{ 
FIRST=temp;
END=temp;
}
else
{
END->rlink=temp;
temp->llink=END;
END=temp;
}
return ;
}
void Create_DLL()
{
int n,i=0;
printf("enter the number of Employees \n");
scanf("%d",&n);
while(i!=n)
{
i++;
Insertionend( );
} 
printf("Creation of DLL for %d is done",i);
}
void display_count()
{
NODE temp1=FIRST;
int count=1;
printf("the employee details \n");
if(temp1==NULL) 
{
printf("the employee detail is NULL and count is 0");
}
else
{
printf("\nSSN\tName\tDept\tDesgn\tSal\tPhNo");
while(temp1!=END)
{
count++;
printf("\n%s\t%s\t%s\t%s\t%ld\t%f",temp1->ssn,temp1->name,temp1->dept,temp1->desig,temp1->phno,temp1->sal);
temp1=temp1->rlink;
}
printf("\n%s\t%s\t%s\t%s\t%ld\t%f\n",temp1->ssn,temp1->name,temp1->dept,temp1->desig,temp1->phno,temp1->sal);
printf("the Employee count is %d\n",count);
}
return;
}
void Insertionfront( )
{
printf("enetr the details of the employee\n");
read();
if(FIRST==NULL)
{
FIRST=temp ;
END=temp;
}
else
{
temp->rlink=FIRST;
FIRST->llink=temp;
FIRST=temp;
}
}
/******************* Deletion *******************/
void Deletionfront( )
{
NODE temp2 ;
if(FIRST==NULL)
{
printf("List is empty\n");
}
else if(FIRST==END)
{
temp2=FIRST;
FIRST=NULL;
END=NULL;
}
else
{
temp2=FIRST;
FIRST =FIRST->rlink;
FIRST->llink=NULL;
}
printf("Record with %s SSN is deleted\n", temp2->ssn);
free(temp2);
return;
}
void Deletionend()
{
NODE temp2 = END;
if(temp2==NULL)
{
printf("List is empty\n");
} 
else if(FIRST==END)
{
printf("Record with %s SSN is deleted\n", temp2->ssn);
FIRST=NULL;
END=NULL;
}
else
{
printf("Record with %s SSN is deleted\n", temp2->ssn);
END=END->llink;
END->rlink=NULL;
free(temp2);
}
return ;
}
void main()
{
int choice;
while(1)
{
printf("\n1.create DLL..\n2.Display SLL..\n3.Insertion at front..\n4.Insertion at end..\n5.deletion at front..\n6.deletion at end..\n7.Exit...");
printf("\nEnter Your Choice: ");
scanf("%d",&choice);
switch(choice)
{
case 1: Create_DLL(); 
	break;
case 2: display_count(); 
	break;
case 3: Insertionfront(); 
	break;
case 4: Insertionend(); 
	break;
case 5: Deletionfront(); 
	break;
case 6: Deletionend(); 
	break;
case 7: exit(0);
default: printf("\n\n\n\tEnter proper Choice....");
}
}
}