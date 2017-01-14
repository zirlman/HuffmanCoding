#include "Lab04.h"
#define _CRT_SECURE_NO_WARNINGS

void main()
{
	NODE* root = 0;
	int choice, flag = 1;
	int balanced;
	TIP element;

	while (flag)
	{
		menu();
		printf("Your choice? ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter element: ");
			scanf("%d", &element);
			insertElement(&root, element);
			system("CLS");
			printAll(root);
			break;
		case 2:
			system("CLS");
			printf("Inorder traversal: ");
			writeInorder(root);
			break;
		case 3:
			system("CLS");
			printf("Preorder traversal: ");
			writePreorder(root);
			break;
		case 4:
			system("CLS");
			printf("Postorder traversal: ");
			printAll(root);
			break;
		case 5:
			balanced = isBalanced(root);
			system("CLS");
			printf("Tree is %sbalanced!", balanced ? "" : "not ");
			break;
		case 0:
			flag = 0;
			break;
		default:
			system("CLS");
			printf("Invalid choice!");
			break;
		}
	}
}