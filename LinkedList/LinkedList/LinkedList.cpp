// LinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"
#include "time.h"
#include <cstdlib>
#include <Windows.h>

void BuildList(struct node ** );
void DisplayNode(struct node*);
void RecursiveReverse(struct node ** );
struct node* Reverse(struct node ** ,struct node * );
void SortedInsert(struct node **,struct node * );
struct node 
{
	int data;
	struct node* Next;
};

int _tmain(int argc, _TCHAR* argv[])
{
	printf("Sample list");
	struct node * head = NULL;

	// Build linked list with random numbers
	BuildList(&head);
	DisplayNode(head);

	// Reverse the linked list
	RecursiveReverse(&head);
	DisplayNode(head);

	//Sorted Insert into a new list
	DisplayNode(head);

	int a;
	scanf_s("adasd",&a);
	return 0;
}


void SortedInsert(struct node ** head,struct node * current)
{

}

void RecursiveReverse(struct node ** head)
{
	if(*head!=NULL)
	{
		struct node * tail = Reverse(head,*head);
		tail->Next=NULL;
	}
}

struct node* Reverse(struct node ** head,struct node * current)
{
	struct node* temp;
	if(current->Next == NULL)
		*head = current;
	else
	{
		temp = Reverse(head,current->Next);
		temp->Next = current;
	}

	return current;
}


void BuildList(struct node ** head)
{
	struct node* current = NULL;
	struct node* temp = NULL;
	time_t seconds;
	printf("\n");
	for(int i =0;i<10;i++)
	{
		Sleep(1000);
		time(&seconds);
		srand((unsigned int)seconds);
		temp = (struct node*)malloc(sizeof(struct node));
		temp->data = rand() % 15;
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
		printf("=");
	}
	printf("\n");
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




