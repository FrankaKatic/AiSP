/*5.	Napisati program koji generira dvije vezane liste na naèin da u svaku upiše
po 10 sluèajno generiranih brojeva u opsegu od 0 do 20. ispisati obje liste na ekran.
Iz ove dvije liste kreirati treæu koja sadrži samo one vrijednosti koje se ponavljaju
u obje liste i upisati je u datoteku.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct _brojevi;
typedef struct _brojevi brojevi;
typedef brojevi* position;

struct _brojevi {

	int broj;

	position next;
};

int main()
{
	srand((unsigned int)(time));

	brojevi head1;
	brojevi head2;
	brojevi head3;

	head1.next = NULL;
	head2.next = NULL;
	head3.next = NULL;

	int result;
	result = GenerirajBroj(&head1);
	printf("prva lista:\n");
	result = IspisListe(&head1);

	result = GenerirajBroj(&head2);
	printf("\ndruga lista:\n");
	result = IspisListe(&head2);

	result = TraziDuple(&head1, &head2, &head3);
	printf("\novo su dupli\n");
	result = IspisListe(&head3);

	result = UnosUDat(&head3);


	return 0;
}

int GenerirajBroj(position head)
{
	int x;
	int i;
	int result;

	for (i = 0; i < 11;i++)
	{
		x = (rand() % 20);
		result = UnosUListu(head, x);
	}
	return 0;
}

int UnosUListu(position head, int broj)
{
	position temp;
	temp = (position)malloc(sizeof(brojevi));

	if (temp == NULL)
	{
		printf("nije se alociralo");
		return -1;
	}

	temp->broj = broj;

	while (head->next != NULL)
	{
		head = head->next;
	}

	temp->next = NULL;
	head->next = temp;

	return 0;
}

int TraziDuple(position head1, position head2, position head3)
{
	head1 = head1->next;
	head2 = head2->next;
	position a = head2;

	while (head1 != NULL)
	{
		head2 = a;
		while (head2 != NULL)
		{
			if (head2->broj == head1->broj)
			{
				int result = UnosUListu(head3, head1->broj);
				if (result == -1)
				{
					printf("nije se upisalo");
					return -1;
				}

			}
			head2 = head2->next;
		}
		head1 = head1->next;
	}

	return 0;
}

int IspisListe(position head)
{
	head = head->next;

	while (head!= NULL)
	{
		printf(" %d ", head->broj);

		head = head->next;
	}
	return 0;
}


int UnosUDat(position head)
{
	FILE* file = NULL;
	file = fopen("dupli.txt", "w");

	if (file == NULL)
	{
		printf("nije se otvorila");
		return -1;
	}
	head = head->next;
	while (head != NULL)
	{
		fprintf(file, "%d\n", head->broj);
		head = head->next;
	}

	fclose(file);
	return 0;
}





























