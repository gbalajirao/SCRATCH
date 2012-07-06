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
	int* a = (int*)malloc(sizeof(int)*10);
	PrintPath(head,a ,0);

	int i;
	scanf_s("Hit enter %d",&i);
	return 0;
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

