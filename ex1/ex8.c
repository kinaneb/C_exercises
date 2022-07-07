/* BSHARA Kinan */

/*  Input/output library */
#include <stdio.h>


/** function somme using for loop */
int somme(int tab[], int taille)
{
	int somme = 0;
	for(int i = 0; i < taille; i++)
	{
		somme += tab[i];
	}
	return somme;
}

/** function somme using while loop */
int somme_while(int tab[], int taille)
{
	int somme = 0;
	while(taille)
	{
		somme += tab[--taille];
	}
	return somme;
}

/** function somme using do while loop */
int somme_do_while(int tab[], int taille)
{
	int somme = 0;
	do
	{
		somme += tab[--taille];
	}while(taille);
	return somme;
}

/**functon initialise the table inside the function
 * in c the function deal with copy of the variable (local variable)
 * so impossible to change the table tab .
 * soulutions : 
 *		a) pass the pointer of tab as a parameter
 *		b) change the return value of the function to "int *" and make somthing like tab = initialise(tab, ...); */
void initialise(int tab[], int taille, int val)
{
	for (int i = 0; i < taille; i++)
	{
		tab[i] = val;
	}
}

/** can't change the value of parameter so this auxiliary function which print the sum result on the terminal */
void initialise_aux(int tab[], int taille, int val)
{
	for (int i = 0; i < taille; i++)
	{
		tab[i] = val;
	}
	printf("%d\n", somme(tab, taille));
}

/* main function */
int main(void) 
{
	int tab[100];
	int taille = 100;
	int val = 1;
	initialise_aux(tab, taille, val);

	/** main function return */
	return 0;
}
