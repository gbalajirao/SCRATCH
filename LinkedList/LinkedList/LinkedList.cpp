// LinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"

void BuildList(struct node ** head);
void DisplayNode(struct node*);
struct node 
{
	int data;
	struct node* Next;
};

int _tmain(int argc, _TCHAR* argv[])
{
	printf("Sample list");
	struct node * head = NULL;
	BuildList(&head);
	DisplayNode(head);


	int a;
	scanf_s("adasd",&a);
	return 0;
}

void BuildList(struct node ** head)
{
	struct node* current = NULL;
	struct node* temp = NULL;
	for(int i =0;i<10;i++)
	{
		temp = (struct node*)malloc(sizeof(struct node));
		temp->data = i;
		if(*head ==NULL)
		{
			*head = temp;
			current = temp;
		}
		else
		{
			current->Next = temp;
			current = temp;
			current->Next = NULL;
		}
	}
}

void DisplayNode(struct node * head)
{
	struct node* current = head;
	printf("\n Linked List :  ");
	while(current!=NULL)
	{
		printf("%d",current->data);
		current = current->Next;
		if(current!=NULL)
			printf(" -> ");
	}
	printf(" -> ");
	printf("NULL");
}




