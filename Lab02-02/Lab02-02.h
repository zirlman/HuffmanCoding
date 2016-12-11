#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct pacijent {
	int arrived;
	int time;
	int priority;
}PACIJENT;
typedef struct queue {
	PACIJENT info;
	struct queue* next;
}QUEUE;

int checkArrTime(const int);
int checkPri(const int);
void add(QUEUE **, const int, const int, const int);
void del(QUEUE**, PACIJENT *);

void pisi(QUEUE *);
void brisi(QUEUE**);