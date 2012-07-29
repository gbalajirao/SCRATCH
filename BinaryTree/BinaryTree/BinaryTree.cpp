// BinaryTree.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "malloc.h"
#include "time.h"
#include <cstdlib>
#include <Windows.h>

void BuildTree(struct BTree ** );
void InsertNode(struct BTree** ,struct BTree* );
void PrintPath(struct BTree* , int* ,int );
void PrintLeafPath(int*,int);
int FetchNthElement(struct BTree* ,int );
void GetNthNode(struct BTree * , int ,int*,int* );
void InOrderTraversal(struct BTree*);
void PrintLevelOrder(struct BTree*);
int GetHeight(struct BTree*);
struct BTree 
{
	int data;
	struct BTree* Left;
	struct BTree* Right;
};

struct Node 
{
	struct BTree* treenode;
	struct Node* next;
};

struct Queue
{
	struct Node* tail;
	struct Node* head;

public:
	Queue()
	{
		head=NULL;
		tail=NULL;
	}

	void Enqueue(struct BTree* sample)
	{
		if(sample!=NULL)
		{
			struct Node* node = (struct Node*)malloc(sizeof(struct Node));
			node->treenode = sample;
			if(head==NULL)
			{
				head=node;
				tail=node;
			}
			else
			{
				node->next = head;
				head=node;
			}
		}
	}

	struct BTree* DeQueue()
	{
		if(head==NULL) return NULL;
		struct BTree* data;
		struct Node* current = head;
		data = tail->treenode;
		if(head!=tail)
		{
			while(current->next != tail)
			{
				current = current->next;
			}
			free(tail);
			tail = current;
		}
		else
		{
			free(tail);
			tail=NULL;
			head=NULL;
		}
		return data;
	}

	bool IsEmpty()
	{
		return (head==NULL);
	}

};


int _tmain(int argc, _TCHAR* argv[])
{
	struct BTree* head = NULL;
	BuildTree(&head);
	printf_s("\n \n  Root Element is - %d \n \n ",head->data);

	int* a = (int*)malloc(sizeof(int)*10);
	PrintPath(head,a ,0);

	// Print Level Order
	PrintLevelOrder(head);

	// Sorted list
	printf("\n \n Sorted list is \n");
	InOrderTraversal(head);

	// Get 3rd largest item
	printf_s("\n \n The 3rd largest number in tree is -  %d \n",  FetchNthElement(head,3));
	int i;
	scanf_s("Hit enter %d",&i);
	return 0;
}

int FetchNthElement(struct BTree* head,int Nth)
{
	if(head==NULL) return 0;
	int value = MAXINT;
	int current=0;
	GetNthNode(head,Nth,&current,&value);
	return value;
}

void InOrderTraversal(struct BTree*  head)
{
	if(head!=NULL)
	{
		InOrderTraversal(head->Left);
		printf_s(" %d ",head->data);
		InOrderTraversal(head->Right);
	}
}

void PrintLevelOrder(struct BTree* head)
{
	printf_s("\n Level Order : \n");
	int height = GetHeight(head);
	if(head!=NULL)
	{
		Queue* myQueue = (Queue*)malloc(sizeof(Queue));
		Queue* childQueue = (Queue*)malloc(sizeof(Queue));
		myQueue->head=NULL;
		myQueue->tail=NULL;
		childQueue->head=NULL;
		childQueue->tail=NULL;
		myQueue->Enqueue(head);
		struct BTree dummy;
		int space=1;
		for (int i = 1; i < height; i++)
		{
			space *= 2;
		}
		for (int i = 0; i < space; i++)
		{
			printf_s(" ");
		}
		while(!myQueue->IsEmpty() || !childQueue->IsEmpty())
		{
			if(!myQueue->IsEmpty())
			{
				struct BTree*  treenode = myQueue->DeQueue();
				if(treenode == &dummy)
					printf_s("  ");
				else
				{
					printf_s("%d ",treenode->data);
					if(treenode->Left == NULL)
						childQueue->Enqueue(&dummy);
					else
						childQueue->Enqueue(treenode->Left);
					if(treenode->Right == NULL)
						childQueue->Enqueue(&dummy);
					else
						childQueue->Enqueue(treenode->Right);
				}
			}
			else
			{
				printf_s("\n");
				height--;
				int space=1;
				for (int i = 1; i < height; i++)
				{
					space *= 2;
				}
				for (int i = 0; i < space; i++)
				{
					printf_s(" ");
				}
				while(!childQueue->IsEmpty())
					myQueue->Enqueue( childQueue->DeQueue());
			}
		}
	}

	printf_s("\n");
}

int GetHeight(struct BTree* head)
{
	if(head==NULL) return 0;
	int lHeight = GetHeight(head->Left);
	int rHeight = GetHeight(head->Right);
	return (lHeight > rHeight)?lHeight + 1:rHeight + 1;
}


void GetNthNode(struct BTree * head, int Nth,int* current,int* value)
{
	if(head->Right!=NULL && *value==MAXINT)
	{
		GetNthNode(head->Right,Nth,current,value);
	}

	if(*value==MAXINT)
	{
		(*current)++;
		//printf_s("\n Walking into %d  -- current %d  Nth %d  value %d \n",head->data,*current,Nth,*value);
		if(Nth == *current )  
		{
			*value = head->data;
		}
	}

	if(head->Left!=NULL&&*value==MAXINT)
	{
		GetNthNode(head->Left,Nth,current,value);
	}
}


void BuildTree(struct BTree** head)
{
	struct BTree* current = NULL;
	struct BTree* temp = NULL;
	time_t seconds;
	printf("\n");
	for(int i =0;i<10;i++)
	{
		Sleep(1000);
		time(&seconds);
		srand((unsigned int)seconds);
		temp = (struct BTree*)malloc(sizeof(struct BTree));
		temp->data = rand() % 15;
		temp->Right = NULL;
		temp->Left= NULL;
		InsertNode(head,temp);
		printf("=");
	}
	printf("\n");
}
void PrintPath(struct BTree* head, int* path,int pathlen)
{
	if(head!=NULL)
	{
		int* temp = path;
		for(int i=0;i<pathlen;i++,temp++);
		*temp = head->data;
		pathlen++;

		if(head->Left == NULL && head->Right==NULL)
		{
			PrintLeafPath(path,pathlen);
		}
		else
		{
			PrintPath(head->Right,path,pathlen);
			PrintPath(head->Left,path,pathlen);
		}
	}
}

void PrintLeafPath(int* path,int pathlen)
{
	printf("\n");
	for(int i=0;i<pathlen;i++)
	{
		printf(" %d -> ",*path);
		path++;
	}
	printf(" End");
}

void InsertNode(struct BTree** head,struct BTree* node)
{
	if(*head==NULL)
		*head=node;
	else
	{
		if((*head)->data>node->data)
		{
			InsertNode(&((*head)->Left),node);
		}
		else
		{
			InsertNode(&((*head)->Right),node);
		}
	}
}

