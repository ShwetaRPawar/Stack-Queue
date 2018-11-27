#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct stack
{
	int data;
	struct stack *next;
}
STACK;

STACK *temp=NULL;
void display(STACK *head);

int isEmpty(STACK *head)
{
	if(head==NULL)
	return 1;
	else return 0;
}

void push(STACK **head,int num)
{
	STACK *nn=NULL;
	nn=(STACK *)malloc(sizeof(STACK));
	nn->data=num;
	if(nn==NULL)
	{
		printf("\n nn is empty");
		exit(0);
	}

	else
	{
		nn->next=*head;
		*head=nn;
	}
}

int pop(STACK **head)
{
	if(!isEmpty(*head))
	{
		temp=*head;
		int value=temp->data;
		(*head)=(*head)->next;
		free(temp);
		return value;
	}
	printf("\n list is empty");
}


//reverse
void reverse(STACK **head)
{
	STACK *head1=NULL;
	if(!isEmpty(*head))
	{
		int value=pop(&(*head));
		//printf("..%d",value);
		push(&head1,value);
		reverse(&(*head));
	}
	display(head1);
}

//display
void display(STACK *head)
{
	temp=head;
	while(temp!=NULL)
	{
		printf("\n%d",temp->data);
		temp=temp->next;
	}
	
}

int main()
{
	STACK *head=NULL;
	push(&head,14);
	push(&head,13);
	push(&head,12);
	push(&head,11);
	display(head);
	reverse(&head);
	//display(head1);
	return 0;
}
