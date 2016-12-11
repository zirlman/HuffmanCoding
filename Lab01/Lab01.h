#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct osoba {
	char ime[21];
	char prezime[21];
	char otac[21];
	char jmbg[14];
	double visina, tezina;
	int godinaStarosti;
}OSOBA;
typedef struct lista {
	OSOBA info;
	struct lista* next;
	struct lista* prev;
}LISTA;

void meni();

void insertFront(LISTA**, LISTA**, OSOBA);
void insertBack(LISTA**, LISTA**, OSOBA);
void removeFront(LISTA**);
void removeBack(LISTA**, LISTA**);
void insertAt(LISTA**, LISTA**, OSOBA, int);
void removeAt(LISTA**, LISTA**, int);
OSOBA front(LISTA*);
OSOBA back(LISTA*);

void addPerson(OSOBA *);
void writePerson(OSOBA);
void writeList(LISTA*);
void sortByWeigth(LISTA*);
void olderThan20(LISTA *);

LISTA* makeNode(OSOBA);
int checkYear(const int*);
int validityOfJmbg(const char*);
int checkGodine(int);
double checkHeight(double);
double checkWeight(double);
int compare(const void *, const void *);
void deleteList(LISTA **);

void search(LISTA *, OSOBA);