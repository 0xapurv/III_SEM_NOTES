#include<stdio.h>
#include<stdlib.h>
int *a,n;
int create()
{
int i;
printf("enter size of array");
scanf("%d",&n);
a = (int *)malloc(n * sizeof(int));
if(a==0)
{
printf("array size is not alloted");
}
else
{
printf("memory allocated successfully");
for(i=0;i<n;i++)
{
printf("enter element");
scanf("%d",&a[i]);
}

}
return(0);}
void insertion()
{
int b,i,pos;
printf("enter position for operation");
scanf("%d",&pos);
if(pos>n||pos<0)
{
printf("error");
return;
}
for(i=n-1;i>=pos-1;i--)
{
a[i+1]=a[i];
}
n++;
printf("enter element\n");
scanf("%d",&b);
a[pos-1]=b;
printf("insertion is successful\n");
}
void deletion()
{
int b,i,pos;
printf("enter position for operation");
scanf("%d",&pos);
b=a[pos-1];
for(i=pos-1;i<n;i++)
a[i]=a[i+1];
n--;
printf("%d is deleted\n",b);
printf("deletion is successful\n");
for(i=0;i<n;i++)
printf("%d ",a[i]);
}
void print()
{
int i;
printf("the array is ");
for(i=0;i<n;i++)
printf("%d ",a[i]);
}
void end()
{
free(a);
printf("memory is dealloted");
exit(0);
}
void main()
{
int n,i,ch;
while(1)
{
printf("enter 1 for creating array\n enter 2 to insert element\n enter 3 to delete element\n enter 4 to print array\n enter 5 to exit");
scanf("%d",&ch);


switch(ch)
{
case 1:{
create();
break;}
case 2:{
insertion();
break;
}
case 3:{
deletion();
break;}
case 4:{
print();
break;}
case 5:{
end();
break;
}
default:printf("error");
}}}