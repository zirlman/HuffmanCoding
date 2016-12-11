#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack {
	char info;
	struct stack* next;
}STACK;

void push(STACK**, const char);
void pop(STACK**, char*);
//void top(STACK*, char*);
char top(STACK*);

void match(const char*);
int openedParentheses(const char);
int closedParentheses(const char);

void postfix(const char*);
int ulazniPrioritet(char);
int stekPrioritet(char);

