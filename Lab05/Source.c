#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lab05.h"
#include <ctype.h>

void main()
{
	srand(time(NULL));
	int myNumber, toGuess = rand() % 50;
	char help;
	char name[16];
	printf("Name: ");
	scanf("%s", name);

	int len = strlen(name);
	int* attempts = (int*)calloc(len, sizeof(int));
	for (int i = 0; i < len; ++i)
	{
		printf("Enter number: "); scanf("%d", &myNumber);
		if (myNumber == toGuess)
		{
			printf("Congratulations!\n");
			break;
		}
		attempts[i] = myNumber;
		printf("Help Y/N ? "); scanf(" %c", &help);
		help = tolower(help);
		if (help == 'y')
			if (myNumber > toGuess)
				printf("LOWER\n");
			else
				printf("HIGHER\n");
	}
	printf("The number is %d", toGuess);

	bubbleSort(attempts, len);
	if (attempts[0] != 0);
	{
		printf("\n\nBubble sort: ");
		for (int i = 0; i < len; ++i)
			if (attempts[i] != 0)
				printf("%d ", attempts[i]);

		selectionSort(attempts, len);
		printf("\nSelection sort: ");
		for (int i = 0; i < len; ++i)
			if (attempts[i] != 0)
				printf("%d ", attempts[i]);
		printf("\n");
	}

	/*int arr[] = { 1,3,5,1,3,2,1 };
	for (int i = 0; i < 7; ++i)
		printf("%d ", arr[i]);
	printf("\nmin: %d\nmax: %d\n", minimum(arr, 7), maximum(arr, 7));
	printf("4.th min: %d", find(arr, 0, 6, 4));*/
	getchar();
	getchar();
}