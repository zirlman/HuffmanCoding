#include "Lab01.h"
#include <string.h>
#include <ctype.h>

int counter = 0;

void insertFront(LISTA **phead, LISTA** ptail, OSOBA o)
{
	LISTA *temp = makeNode(o);

	if (*phead == NULL) {
		*phead = *ptail = temp;
	}
	else {
		temp->next = *phead;
		(*phead)->prev = temp;
		*phead = temp;
	}
	counter++;
}
void insertBack(LISTA **phead, LISTA** ptail, OSOBA o)
{
	LISTA* temp = makeNode(o);

	if (*phead == NULL) {
		*phead = *ptail = temp;
	}
	else {
		(*ptail)->next = temp;
		temp->prev = *ptail;
		*ptail = temp;
	}
	counter++;

}

void removeFront(LISTA **phead)
{
	if (*phead == NULL) { printf("Lista je prazna."); return; }
	LISTA* temp = (*phead)->next;
	if (temp == NULL) { deleteList(phead); return; }
	temp->prev = NULL;
	(*phead)->next = NULL;
	free(*phead);
	*phead = temp;
	counter--;
}
void removeBack(LISTA** phead, LISTA** ptail)
{
	if (*ptail == NULL) { printf("Lista je prazna."); return; }
	LISTA* temp = (*ptail)->prev;
	if (temp == NULL) { deleteList(phead); return; }
	temp->next = NULL;
	(*ptail)->prev = NULL;
	free(*ptail);
	*ptail = temp;
	counter--;
}

void insertAt(LISTA** phead, LISTA** ptail, OSOBA o, int i)
{
	if (*phead == NULL) { printf("Lista je prazna."); return; }
	int c = 1;
	LISTA* temp = *phead;
	LISTA* novi = makeNode(o);
	if (i > counter) { printf("Dodavanje na trazenu poziciju nije moguce.\nDodavanje na kraj liste....\n"); insertBack(phead, ptail, o); return; }
	while (c++ < i) temp = temp->next;
	if (temp == *phead) { insertFront(phead, ptail, o); return; }
	if (temp == *ptail) { insertBack(phead, ptail, o); return; }
	novi->next = temp->next;
	novi->prev = temp;
	temp->next->prev = novi;
	temp->next = novi;
	counter++;
}
void removeAt(LISTA **phead, LISTA** ptail, int i)
{
	if (*phead == NULL) { printf("Lista je prazna."); return; }
	LISTA*temp = *phead;
	int c = 1;
	if (i > counter) { printf("Trazena pozicija je prazna."); return; }
	if (counter == 1) { deleteList(phead); return; }
	while (c++ < i - 1) temp = temp->next;
	if (temp == *phead) { removeFront(phead); return; }
	if (temp == *ptail) { removeBack(phead, ptail); return; }

	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;

	temp->next = temp->prev = NULL;
	free(temp);
	counter--;
}

OSOBA front(LISTA *head)
{
	return head->info;
}

OSOBA back(LISTA *head)
{
	while (head->next) head = head->next;
	return head->info;
}

void addPerson(OSOBA *head)
{
	do {
		printf("=============================\nUNESITE PODATKE :\n(ime,prezime,ime oca,jmbg,visina,tezina,starost)\n-----------------------------\n");
		scanf("%s", head->ime);
		scanf("%s", head->prezime);
		scanf("%s", head->otac);
		scanf("%s", head->jmbg);
		scanf("%lf", &head->visina);
		scanf("%lf", &head->tezina);
		scanf("%d", &head->godinaStarosti);
		printf("=============================\n");

	} while (!validityOfJmbg(head->jmbg));
	head->godinaStarosti = checkGodine(head->godinaStarosti);
	head->visina = checkHeight(head->visina);
	head->tezina = checkWeight(head->tezina);
}
void writePerson(OSOBA head)
{
	printf("-----------------------------\n");
	printf("Ime: %s\n", head.ime);
	printf("Prezime: %s\n", head.prezime);
	printf("Ime oca: %s\n", head.otac);
	printf("JMBG: %s\n", head.jmbg);
	printf("Visina: %3.2lf\n", head.visina);
	printf("Tezina: %3.2lf\n", head.tezina);
	printf("Godina starosti: %2d\n", head.godinaStarosti);
}
void writeList(LISTA *head)
{
	printf("=============================\nISPIS:\n");
	while (head) {
		printf("-----------------------------\n");
		printf("Ime: %s\n", head->info.ime);
		printf("Prezime: %s\n", head->info.prezime);
		printf("Ime oca: %s\n", head->info.otac);
		printf("JMBG: %s\n", head->info.jmbg);
		printf("Visina: %3.2lf\n", head->info.visina);
		printf("Tezina: %3.2lf\n", head->info.tezina);
		printf("Godina starosti: %2d\n", head->info.godinaStarosti);
		head = head->next;
	}
	printf("=============================\n");

}

int compare(const void *a, const void *b)
{
	if ((((OSOBA*)a)->tezina - ((OSOBA*)b)->tezina) < 0)
		return 1;
	else if ((((OSOBA*)a)->tezina - ((OSOBA*)b)->tezina) > 0)
		return -1;
	return 0;
}
void sortByWeigth(LISTA* head)
{
	if (head == 0) { printf("Prazna lista.\n"); return; }
	else
	{
		int i = 0;
		for (LISTA *help = head; help; help = help->next, i++);
		OSOBA *arr = (OSOBA*)calloc(i, sizeof(OSOBA));
		for (int n = 0; head; n++, head = head->next)
			arr[n] = head->info;
		qsort(arr, i, sizeof(OSOBA), compare);
		for (int n = 0; n < i; n++)
			writePerson(arr[n]);
		free(arr);
	}
}
void olderThan20(LISTA *head)
{
	if (head == NULL) { printf("Lista je prazna."); return; }
	while (head) {
		if (checkYear(&head->info.godinaStarosti))
			writePerson(head->info);
		head = head->next;
	}
}
int checkYear(const int* s)
{
	return *s > 20 ? 1 : 0;
}
int validityOfJmbg(const char* arr)
{
	if (strlen(arr) != 13)
		return 0;
	else
	{
		for (int i = 0; i < 13; i++)
			if (!isdigit(arr[i]))
				return 0;
	}
	if (arr[0] != '0' && arr[0] != '1' && arr[0] != '2' && arr[0] != '3')
		return 0;
	else if (arr[0] == '3' && (arr[1] != '1' && arr[1] != '0'))
		return 0;
	else if ((arr[0] == '3' && arr[1] == '1') && ((arr[2] == '0' && (arr[3] != '3' && arr[3] != '5' && arr[3] != '7'&& arr[3] != '8')) || (arr[2] == '1' && (arr[3] != '0' && arr[3] != '2'))))
		return 0;
	else if ((arr[0] == '3' && (arr[1] == '1' || arr[1] == '0')) && (arr[2] == '0' && arr[3] == '2'))
		return 0;
	else if (arr[9] != '0' && arr[9] != '5')
		return 0;
	return 1;
}
int checkGodine(int g)
{
	if (g < 0 || g>120)
		return 18;
	return g;
}
double checkHeight(double a)
{
	if (a<0 || a>2.5)
		return 1.6;
	else
		return a;
}
double checkWeight(double a)
{
	if (a < 0 || a>300)
		return 70;
	return a;
}

LISTA* makeNode(OSOBA o)
{
	LISTA* novi = (LISTA *)calloc(1, sizeof(LISTA));
	novi->next = novi->prev = NULL;
	novi->info = o;
	return novi;
}
void deleteList(LISTA **phead)
{
	while (*phead) {
		LISTA* temp = (*phead)->next;
		free(*phead);
		*phead = temp;
	}
	*phead = NULL;
}

void meni()
{
	printf(
		"\n   ________________________________\n"
		" / \                                \\.\n"
		"|   |                               |.\n"
		"\\ __|                               |.\n"
		"    |                               |.\n"
		"    |   Meni:                       |.\n"
		"    |    [1]  Dodaj na pocetak      |.\n"
		"    |    [2]  Dodaj na kraj         |.\n"
		"    |    [3]  Obrisi sa pocetka     |.\n"
		"    |    [4]  Obrisi sa kraja       |.\n"
		"    |    [5]  Dodaj na proizv. lok. |.\n"
		"    |    [6]  Obrisi sa proizv. lok.|.\n"
		"    |    [7]  Vrati sa pocetka      |.\n"
		"    |    [8]  Vrati sa kraja        |.\n"
		"    |    [9]  Ispis po tezini       |.\n"
		"    |    [10] Ispis (>20 godina)    |.\n"
		"    |    [0] Izlaz                  |.\n"
		"    |   ____________________________|___\n"
		"    |  /                               /.\n"
		"    \\_/_______________________________/.\n\n");
}
void search(LISTA *head, OSOBA o)
{
	while (head) {
		if (head->info.jmbg[0] == '0' && head->info.jmbg[1] == '1'&&head->info.jmbg[2] == '0' && head->info.jmbg[3] == '1') { writePerson(head->info); return; }
		head = head->next;
	}
	printf("Trazena osoba ne postoji u listi.\n");
}
