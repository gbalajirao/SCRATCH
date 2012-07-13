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
struct BTree 
{
	int data;
	struct BTree* Left;
	struct BTree* Right;
};

int _tmain(int argc, _TCHAR* argv[])
{
	struct BTree* head = NULL;
	BuildTree(&head);
	printf_s("\n \n  Root Element is - %d \n \n ",head->data);

	int* a = (int*)malloc(sizeof(int)*10);
	PrintPath(head,a ,0);

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

