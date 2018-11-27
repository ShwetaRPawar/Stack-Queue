#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct sq
{
	int data;
	struct sq *next,*prv;
}SQ;

void insertlast(SQ **head,int num);
SQ *temp=NULL;
//isempty
int isEmpty(SQ *head)
{
	if(head==NULL)
	return 1;
	else
	return 0;
}
//insertlast
void insertlast(SQ **head,int num)
{
	SQ *nn=NULL;
	nn=(SQ *)malloc(sizeof(SQ));
	nn->next=NULL;
	nn->prv=NULL;

	if((*head)==NULL)
	{
		nn->data=num;
		*head=nn;
		temp=*head;
		temp->next=NULL;
		temp->prv=NULL;
	}
	else
	{
		nn->data=num;
		temp->next=nn;
		nn->prv=temp;
		temp=nn;
		temp->next=NULL;
	}
}

//push
void push(SQ **head,int num)
{
	insertlast(&(*head),num);
}

//enqueue
void enqueue(SQ **head,int num)
{
	insertlast(&(*head),num);
}
//pop
int pop(SQ **head)
{

	if(!isEmpty(*head))
	{
		SQ *temp1=temp;
		temp=temp->prv;
		temp->next=NULL;
		return temp1->data;
		free(temp1);

	}
	printf("\n list s empty");
}

//dequeue
int dqueue(SQ **head)
{
	SQ *temp1=*head;
	*head=(*head)->next;
	(*head)->prv=NULL;
	return temp1->data;
	free(temp1);
}
//display
void display(SQ *head)
{
	SQ *temp=NULL;
	temp=head;
	printf("\nstack:");
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
}

void main()
{

	SQ *head=NULL;
	SQ *head2=NULL;
	push(&head,7);
	push(&head,8);
	/*push(&head,3);
	push(&head,4);
	push(&head,5);
	push(&head,6);
	printf("\n%d",n);*/
	display(head);
	int n=pop(&head);
	display(head);

	//enqueue(&head2,11);
	enqueue(&head2,12);
	enqueue(&head2,13);
	//enqueue(&head2,14);
	//enqueue(&head2,15);
	display(head2);

	int m=dqueue(&head2);
	//printf("\n%d",m);

	//m=dqueue(&head2);
	//printf("\n%d",m);
	display(head2);

}

