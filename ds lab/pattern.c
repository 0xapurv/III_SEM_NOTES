#include<stdio.h> 
#include<stdlib.h>
int my_strlen(char str[])
{ 
    	int i=0; 
    	while(str[i]!='\0') 
        	i++; 
    	return i; 
} 
void my_strcpy(char a[],char b[])
{ 
    	int i=0; 
    	while(b[i]!='\0')
     	{ 
        	a[i]=b[i]; 
        	i++;
        }
    	a[i]='\0';
     } 
void my_strncpy(char a[],char b[], int n) 
{ 
    	int i;
    	for(i=0;i<n;i++) 
        	a[i]=b[i]; 
    	a[i]='\0'; 
}
void strcpy2(char a[],char b[],int n)
{
    	int i;
  	i=my_strlen(a);
   	while(b[n]!='\0')
   	{
        	a[i]=b[n];
        	i++;
       		n++;
        
   	}
    	a[i]='\0';
}
void my_strcat(char str1[],char str2[])
{ 
    	int i=0,j=0; 
    	while(str1[i]!='\0') 
        	i++;  
    	while(str2[j]!='\0') 
    	{ 
        	str1[i]=str2[j]; 
        	i++; 
        	j++; 
        } 
    	str1[i]='\0'; 
} 
void main() 
{ 
    	char str[100],pat[100],repstr[100],temp[100]; 
    	int m,i,j,len,flag,k; 
    	printf("enter the main string\n"); 
	gets(str); 
    	printf("enter the pattern string\n"); 
	gets(pat);
	m=my_strlen(pat); 
    	k=my_strlen(str); 
    	if(m>k)
    	{
        	if(k==0)
            	{
                	printf("invalid main string");
                	exit(0);
            	}
        	printf("length of main string is small than pattern string\n");
            	exit (0);
    	}
	else if(m==0)
        {
            printf("invalid pattern string");
            exit(0);
        }
    	else
    	{	
    		printf("enter the replace string\n"); 
		gets(repstr);
		flag=0; 
    		i=0; 
    		while(str[i]!='\0') 
    		{ 
        		for(j=0;j<m;j++) 
        		{ 
            			if(str[i+j]!=pat[j]) 
            				break; 
            		} 
       			if(j==m) 
                	{ 
                    		flag++; 
				my_strncpy(temp,str,i); 
				my_strcat(temp,repstr); 
                    		i=i+m; 
           			strcpy2(temp,str,i);
            			len=my_strlen(temp); 
				my_strcpy(str,temp); 
                    		i=m;
                    	} 
                	else  
                    		i=i+1; 
                } 
            	if(flag==0) 
            		printf("pattern not found\n"); 
		else 
            	{ 
                	printf("pattern found %d times in main string\n",flag); 
                	printf("The resultant string after replacing is ");
            		for(i=0;str[i]!='\0';i++)
             			printf("%c",str[i]);
                }
        }
}