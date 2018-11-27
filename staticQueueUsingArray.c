#include<stdio.h>
#include<malloc.h>
//static int len=0;

int is_full(int len)
{
	if(len>=20)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}

void push(int *a,int *len,int num)
{
	int len1=is_full(*len);
	if(len1==-1)
	{
		printf("stack is full");
	}
	else
	{
		//printf("%d\n",*len);
		a[*len]=num;
		(*len)++;
	}
}


void print(int *a,int len)
{
	for(int i=0;i<len;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
}

int is_empty(int len)
{
	if(len<1)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}


void pop(int *a,int *len)
{
	int len1=is_empty(*len);
	if(len1==-1)
		{
			printf("stack is empty\n");
			return;
		}
	else
		{
	
			a[*len]=0;
			(*len)--;
		}

}


void main()
{
	int *a;
	a=(int *)malloc(sizeof(int)*20);
	int len=0;
	//int len=sizeof(a)/sizeof(a[0]);
	//print(a,len);
	push(a,&len,10);	
	//printf("%d\n",len);
	push(a,&len,20);
	//printf("%d\n",len);
	print(a,len);

	push(a,&len,30);
	print(a,len);

	pop(a,&len);
	print(a,len);

	pop(a,&len);
	print(a,len);

	pop(a,&len);



}
