#include "Lab03.h"



int isLeaf(NODE* root)
{
	return !(root->left) && !(root->right);
}

// Upisuje putanju do slova u fajl
void printArr(FILE* fp, char* arr, int n)
{
	for (int i = 0; i < n; ++i)
		fprintf(fp, "%c", arr[i]);
	fprintf(fp, "\n");
}
void printCode(FILE* fp, NODE* root, char* arr)
{
	static int j;
	if (root->left)
	{
		arr[j++] = '0';
		printCode(fp, root->left, arr);
	}
	if (root->right)
	{
		arr[j++] = '1';
		printCode(fp, root->right, arr);
	}
	if (isLeaf(root))
	{
		arr[j] = '\0';
		fprintf(fp, "%c", root->info.letter);
		printArr(fp, arr, j);
	}
	j--;

}

// Pseudo kod sa iz Tomaseviceve knjige za Hofmanov kod
NODE* buildHuffmanTree(VECTOR* vec, int n)
{
	QUEUE* priQueue = 0;
	NODE* z;
	for (int i = 0; i < n; ++i)
	{
		z = (NODE *)calloc(1, sizeof(NODE));
		z->info.value = vec[i].value;
		z->info.letter = vec[i].letter;
		add(&priQueue, z);
	}
	for (int i = 0; i < n - 1; ++i)
	{
		z = (NODE *)calloc(1, sizeof(NODE));
		NODE* x = del(&priQueue);
		NODE* y = del(&priQueue);
		z->info.value = x->info.value + y->info.value;
		z->left = x;
		z->right = y;
		add(&priQueue, z);
	}
	z = del(&priQueue);
	return z;
}

void add(QUEUE** phead, NODE* z)
{
	QUEUE* temp = (QUEUE *)calloc(1, sizeof(QUEUE));
	temp->node = z;
	temp->next = NULL;
	if (*phead == NULL)
		*phead = temp;
	else {
		if (temp->node->info.value <= (*phead)->node->info.value)
			// onaj sa manjom vr. prioriteta ili manjim vremenom ide na pocetak
		{
			temp->next = *phead;
			*phead = temp;
			return;
		}
		QUEUE* help = *phead;
		for (; help->next && (help->next->node->info.value <= temp->node->info.value); help = help->next);
		if (help->next == NULL)
		{
			help->next = temp;
			return;
		}
		temp->next = help->next;
		help->next = temp;
	}
}
NODE* del(QUEUE** phead)
{
	if (*phead == NULL)
	{
		return NULL;
	}
	else
	{
		NODE* result = (*phead)->node;
		QUEUE* temp = (*phead)->next;
		free(*phead); *phead = NULL;
		*phead = temp;
		return result;
	}
}

// Pomocna funkcija koja ispisuje prioritetni red
void readQ(QUEUE* head)
{
	while (head)
	{
		printf("%c (%3.2lf)\n", head->node->info.letter, head->node->info.value);
		head = head->next;
	}
}

int checkSum(VECTOR* vec, int n)
{
	double sum = 0;
	for (int i = 0; i < n; ++i)
		sum += (vec[i].value);
	return sum > 99;
}

void sort(char codes[][52])
{
	int min;
	for (int i = 0; i < MAX - 1; ++i)
	{
		min = i;
		for (int j = i + 1; j < MAX; ++j)
			if (codes[min][0] > codes[j][0])
				min = j;
		if (min != i)
		{
			char temp[52];
			strcpy(temp, codes[i]);
			strcpy(codes[i], codes[min]);
			strcpy(codes[min], temp);
		}
	}
}