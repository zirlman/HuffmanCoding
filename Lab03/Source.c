#include "Lab03.h"
#include <ctype.h>
// MAX predstavlja broj karaktera koji se ucitavaju

void main()
{
	NODE* tree;
	VECTOR alphabet[MAX];
	char ch;
	int i = 0;
	char arr[100];
	char msg[50];
	char codes[26][52];


	FILE* fp;
	if ((fp = fopen("Alphabet.txt", "r")) == NULL)
	{
		printf("Error while document opening..\n");
		return;
	}
	//-------------------------------------------------
	//Ucitavanje karaktera i vjerovatnoce pojavljivanja
	//-------------------------------------------------
	while ((ch = getc(fp)) != '\n')
		if (ch != ' ')
			alphabet[i++].letter = ch;
	for (i = 0; i < MAX; ++i)
		fscanf(fp, "%lf", &alphabet[i].value);
	fclose(fp);

	if (!checkSum(alphabet, MAX))
		return;
	//-------------------------------------------------
	//Pravljenje Hofmanovog stabla
	//-------------------------------------------------
	tree = buildHuffmanTree(alphabet, MAX);

	//-------------------------------------------------
	//Upis koda u fajl,jer smo u mogucnosti
	//-------------------------------------------------
	if ((fp = fopen("AlphabetCode.txt", "w")) == NULL)
	{
		printf("Error while document opening..\n");
		return;
	}
	printCode(fp, tree, arr);
	fclose(fp);

	//-------------------------------------------------
	//Citanje koda iz fajla koji sadrzi kodove
	//Prvi karakter matrice je slovo dok je ostatak njegov kod
	//Nakon sto se svi kodovi unesu matrica se sortira jer na taj nacin izbjegavamo pretrazivanje matrice
	/* Na primjer:
				Z001
				C000
				B01
	Nakon sortiranja
				B01
				C000
				Z001*/
	//-------------------------------------------------
	if ((fp = fopen("AlphabetCode.txt", "r")) == NULL)
	{
		printf("Error while document opening..\n");
		return;
	}
	i = 0;
	while (fscanf(fp, "%s", codes[i++]) == 1);
	fclose(fp);

	sort(codes);


	printf("Enter message you want to code: ");
	scanf("%s", msg);

	//-------------------------------------------------
	//Svaki karakter unesenog stringa se uzima pojedinacno i trazi se njegova pozicija u matrici "codes"
	//-------------------------------------------------
	for (int m = 0; m < strlen(msg); ++m)
	{
		if (isalpha(msg[m]))
		{
			printf("%c: ", codes[msg[m] - 'A'][0]);
			for (int n = 1; codes[msg[m] - 'A'][n]; ++n)
				printf("%c", codes[msg[m] - 'A'][n]);
			printf("\n");
		}
	}

	getchar();
	getchar();
}