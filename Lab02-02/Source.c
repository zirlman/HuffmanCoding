#include "Lab02-02.h"
#include <time.h>
#include <string.h>
#include <Windows.h>

void main() {
	int n;
	clock_t staroVrijeme, novoVrijeme;
	time_t mytime;
	mytime = time(NULL);
	srand((unsigned)time(&mytime));

	do
	{
		printf("Broj pacijenata: ");
		scanf("%d", &n);
	} while (n < 0 || n>8);

	QUEUE* queue = 0;
	PACIJENT pom;

	for (int i = 0; i < n; ++i)
		add(&queue, rand() % 30 + 1, rand() % 30 + 1, rand() % 4 + 1);
	pisi(queue);
	printf("Unos pacijenata zavrsen.\n");
	char start[10];

	do
	{
		printf("Unesite START za obradu pacijenata. ");
		scanf("%s", start);
	} while (strcmp("START", start) && strcmp("st", start));

	for (int i = 0; i < n; ++i)
	{
		del(&queue, &pom);
		printf("Pacijent redni broj %2d je na pregledu! Pregled poceo u vrijeme %2d i trajace %2ds!\n", i + 1, pom.arrived, pom.time);
		staroVrijeme = clock();
		do
		{
			novoVrijeme = clock();
		} while ((novoVrijeme - staroVrijeme) / (double)CLOCKS_PER_SEC < pom.time);
	}

	char q;
	do
	{
		printf("KRAJ SIMULACIJE,UNESITE Q ZA IZLAZ ");
		scanf("\n%c", &q);
	} while (q != 'Q' && q!='q');

	brisi(&queue);
	exit(0);
}