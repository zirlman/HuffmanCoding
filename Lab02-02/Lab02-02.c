#include "Lab02-02.h"


int checkArrTime(const int n)
{
	return n < 1 || n > 30 ? 30 : n;
}
int checkPri(const int c)
{
	return c < 1 || c>4 ? 4 : c;
}

void add(QUEUE **phead, const int a, const int b, const int c)
{
	QUEUE* temp = (QUEUE *)calloc(1, sizeof(QUEUE));
	temp->info.arrived = checkArrTime(a);
	temp->info.time = checkArrTime(b);
	temp->info.priority = checkPri(c);
	temp->next = NULL;
	if (*phead == NULL)
		*phead = temp;
	else {
		if (temp->info.priority < (*phead)->info.priority ||
			(temp->info.priority == (*phead)->info.priority && temp->info.arrived <= (*phead)->info.arrived))
			// onaj sa manjom vr. prioriteta ili manjim vremenom ide na pocetak
		{
			temp->next = *phead;
			*phead = temp;
			return;
		}
		QUEUE* help = *phead;
		for (; help->next && ((help->next->info.priority < temp->info.priority)
			|| (help->next->info.priority == temp->info.priority && help->next->info.arrived <= temp->info.arrived)); help = help->next);
		if (help->next == NULL)
		{
			help->next = temp;
			return;
		}
		temp->next = help->next;
		help->next = temp;
	}
}

void del(QUEUE** phead, PACIJENT* p)
{
	if (*phead == NULL)
	{
		printf("Red je prazan.\n");
		return;
	}
	else
	{
		*p = (*phead)->info;
		QUEUE* temp = (*phead)->next;
		free(*phead); *phead = NULL;
		*phead = temp;
	}
}




void pisi(QUEUE *head)
{
	while (head)
	{
		printf("%2d %2d %2d\n", head->info.arrived, head->info.time, head->info.priority);
		head = head->next;
	}
}

void brisi(QUEUE **phead)
{
	while (*phead)
	{
		QUEUE* temp = (*phead)->next;
		free(*phead);
		*phead = temp;
	}
	*phead = 0;
}