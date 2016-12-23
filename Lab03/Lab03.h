#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 7


typedef struct vektor
{
	char letter;
	double value;
}VECTOR;
typedef struct node
{
	VECTOR info;
	struct node* left;
	struct node* right;
}NODE;
typedef struct queue {
	NODE* node;
	struct queue* next;
}QUEUE;

int isLeaf(NODE* root);
NODE* buildHuffmanTree(VECTOR*, int);
void printCode(FILE*, NODE*, char*);
void printArr(FILE*, char*, int);

void add(QUEUE**, NODE *);
NODE* del(QUEUE**);
void readQ(QUEUE *);

int checkSum(VECTOR*, int);
void sort(char[][52]);