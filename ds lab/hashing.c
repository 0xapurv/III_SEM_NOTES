#include <stdio.h>
#define m 20
int HT[10];
int hash(int key)
{
return key%m;
}
void linear_probe(int hk,int key)
{
int i,flag=0;
for (i=hk+1;i<m;i++)
{
if (HT[i]==999)
{
HT[i]=key;
flag=1;
break;
}
}
for(i=0;i<hk&&flag==0;i++)
{
if (HT[i]==999)
{
HT[i]=key;
flag=1;
break;
}
}
if (!flag)
printf("HASH Table is Full!!!\n");
}
void main()
{
FILE *fp;
int N,i,key,hk;
char name[10000];
for (i=0;i<m;i++)
HT[i]=999;
fp=fopen("emp.txt","r");
while(fscanf(fp,"%d%s",&key,name)!=EOF)
{
hk=hash(key);
if (HT[hk]==999)
HT[hk]=key;
else
{
printf("Collision for key %d:\n",key);
printf("Collision solved by Linear Probing\n\n");
linear_probe(hk,key);
}
}
printf("-------------------------------\n");
printf("HASH TABLE\n");
printf("-------------------------------\n");
printf("Address\tKeys\n");
for (i=0;i<m;i++)
printf("%d\t%d\n",i,HT[i]);
}