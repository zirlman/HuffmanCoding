#include "Lab02-01.h"
#include <ctype.h>

void push(STACK** tos, const char info)
{
	STACK* novi = (STACK *)calloc(1, sizeof(STACK));
	novi->info = info;
	novi->next = NULL;
	if (*tos == NULL)
		*tos = novi;
	else {
		novi->next = *tos;
		*tos = novi;
	}
}
void pop(STACK ** tos, char* info)
{
	if (*tos == NULL) {
		printf("Stek je prazan.\n");
		return;
	}
	else {
		STACK* temp = (*tos)->next;
		*info = (*tos)->info;
		free(*tos), *tos = NULL;
		*tos = temp;
	}
}
char top(STACK *tos)
{
	if (tos == NULL) {
		//printf("Stek je prazan.\n");
		//return;
	}
	else {
		//	for (; tos; tos = tos->next);
		//*info = tos->info;
		return tos->info;
	}
}

int closedParentheses(const char c)
{
	if (c == '}' || c == ']' || c == ')')
		return 1;
	else
		return 0;;
}
int openedParentheses(const char c)
{
	if (c == '{' || c == '[' || c == '(')
		return 1;
	else
		return 0;
}

void match(const char* str)
{
	int n = strlen(str);
	char c;
	STACK* tos = 0;
	for (int i = 0; i < n; ++i)
		if (openedParentheses(str[i]))
			push(&tos, str[i]);
		else
			if (closedParentheses(str[i]))
			{
				if (tos == NULL)
				{
					printf("nema zagrada.\n");
					return;
				}
				pop(&tos, &c);
				if (c == '{' && str[i] != '}') { printf("neispravan, nedostaje }.\n"); return; }
				if (c == '[' && str[i] != ']') { printf("neispravan, nedostaje ].\n"); return; }
				if (c == '(' && str[i] != ')') { printf("neispravan, nedostaje ).\n"); return; }
			}

	if (tos)
	{
		pop(&tos, &c);
		if (c == '{') { printf("neispravan, nedostaje }.\n"); return; }
		if (c == '[') { printf("neispravan, nedostaje ].\n"); return; }
		if (c == '(') { printf("neispravan, nedostaje ).\n"); return; }
	}
	printf("ipravan.\n");
}

void postfix(const char* str)
{
	STACK* tos = 0;
	int len = strlen(str);
	char print=0;
	for (int i = 0; i < len; ++i)
	{
		if (isalpha(str[i]))
			printf("%c", str[i]);
		else
		{
			int u = ulazniPrioritet(str[i]);
			if (tos == NULL)
				push(&tos, str[i]);
			else {
				while (u <= stekPrioritet(top(tos)))
				{
					if (print != '(' && print != ')')
						printf("%c", print);
				}
				if (str[i] != ')')
					push(&tos, str[i]);
			}
		}
	}
	while (tos != NULL)
	{
		pop(&tos, &print);
		if (print != '(' && print != ')')
			printf("%c", print);
	}
}

int ulazniPrioritet(char c)
{
	if (c == '+' || c == '-') return 2;
	else if (c == '*' || c == '/') return 3;
	else if (c == '^') return 5;
	else if (c == '(') return 6;
	else if (c == ')') return 1;
	else return 0;
}

int stekPrioritet(char c)
{
	if (c == '+' || c == '-') return 2;
	else if (c == '*' || c == '/') return 3;
	else if (c == '^') return 4;
	else if (c == '(') return 1;
	else if (c == ')') return -1;
	else return -10;
}