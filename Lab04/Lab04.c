#include "Lab04.h"

NODE* newNode(TIP info)
{
	NODE* temp = (NODE *)calloc(1, sizeof(NODE));
	temp->info = info;
	temp->left = temp->right = NULL;

	return temp;
}

void insertElement(NODE** proot, TIP info)
{
	if (*proot != NULL)
		if (info <= (*proot)->info)
			insertElement(&(*proot)->left, info);
		else
			insertElement(&(*proot)->right, info);
	else
	{
		*proot = newNode(info);
	}
}

void writeInorder(NODE* root)
{
	if (root != NULL)
	{
		writeInorder(root->left);
		printf("%d ", root->info); // Promijeniti ispis tipa u zavisnosti info sadrzaja
		writeInorder(root->right);
	}

}

void writePreorder(NODE* root)
{
	if (root != NULL)
	{
		printf("%d ", root->info); // Promijeniti ispis tipa u zavisnosti info sadrzaja
		writePreorder(root->left);
		writePreorder(root->right);
	}
}

void printAll(NODE* root)
{
	printf("Tree elements: ");
	writeInorder(root);
}

int isBalanced(NODE* root)
{
	if (root == NULL)
		return 1;

	int lh, rh;

	lh = height(root->left);
	rh = height(root->right);


	if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
		return 1;

	return 0;
}

int maximum(int a, int b)
{
	return (a >= b) ? a : b;
}
int height(NODE* root)
{
	if (root == NULL)
		return 0;
	return 1 + maximum(height(root->left), height(root->right));
}


void menu()
{
	printf(
		"\n\n::::::::::::::::::::::::::::::::::::::::::::::::::::\n"
		"::::::::::::::::::::::::::::::::::::::::::::::::::::\n"
		"::                                                ::\n"
		"::                                                ::\n"
		"::        MENU:                                   ::\n"
		"::           1. Insert Element                    ::\n"
		"::           2. Write inorder                     ::\n"
		"::           3. Write preorder                    ::\n"
		"::           4. Print all                         ::\n"
		"::           5. Balanced tree?                    ::\n"
		"::           0. Exit                              ::\n"
		"::                                                ::\n"
		"::                                                ::\n"
		"::::::::::::::::::::::::::::::::::::::::::::::::::::\n"
		"::::::::::::::::::::::::::::::::::::::::::::::::::::\n"
	);
}
