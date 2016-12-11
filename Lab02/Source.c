#include <stdio.h>
#include "Lab02-01.h"

void main()
{
	/*printf("(a+b)*c-d/[(e-f)+g = ");
	match("(a+b)*c-d/[(e-f)+g");
	printf("(a+b)*c-d/[(e-f)+g] = ");
	match("(a+b)*c-d/[(e-f)+g]");*/

	postfix("A+B*(C-D)+(E-F)*G/H");
	getch();
}