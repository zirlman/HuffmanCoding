#include <stdio.h>
#include "Lab02-01.h"
#define _CRT_SECURE_NO_WARNINGS

void main()
{
	printf("(a+b)*c-d/[(e-f)+g = ");
	match("(a+b)*c-d/[(e-f)+g");
	printf("(a+b)*c-d/[(e-f)+g] = ");
	match("(a+b)*c-d/[(e-f)+g]");

	//postfix("A+B*(C-D)+(E-F)*G/H");
	getchar();
	getchar();
}