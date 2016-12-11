#include "Lab01.h"

void main() {
	LISTA* head = 0, *tail = 0;
	OSOBA o = { "Marko","Markovic","Mile","150899610097",1.78,82.5,20 };
	OSOBA o2 = { "Petar","Petrovic","Nikola","0101997100055",1.85,90,22 };
	OSOBA o3 = { "Nikola","Nikolic","Petar","1010997100040",1.80,92,27 };
	OSOBA p;
	int izbor, c;
	do {
		meni();
		printf("Vas izbor: "), scanf("%d", &izbor);
		switch (izbor)
		{
		case 1: /*addPerson(&p);*/ insertFront(&head, &tail, o); break;
		case 2: /*addPerson(&p);*/ insertBack(&head, &tail, o2);  break;
		case 3: removeFront(&head); break;
		case 4: removeBack(&head, &tail); break;
		case 5: printf("Pozicija: "), scanf("%d", &c), insertAt(&head, &tail, o3, c);  break;
		case 6: printf("Pozicija: "), scanf("%d", &c), removeAt(&head, &tail, c);  break;
		case 7: o = front(head); writePerson(o); break;
		case 8: o = back(head); writePerson(o); break;
		case 9: sortByWeigth(head);  break;
		case 10: olderThan20(head); break;
		case 0:   break;//exit(1);
		default: printf("Neispravan unos.\n"); break;
		}
	} while (izbor);
	search(head, o);
	/*
	insertFront(&head, &tail, o);
	insertAt(&head, &tail, o2,1);
	removeAt(&head,&tail,2);
	*/
	deleteList(&head);

	getch();
}