/* ****************************************************** */
/* BSHARA Kinan                                           */
/* TP 3                                                   */
/* ex: 2                                                  */
/* ****************************************************** */

#include<stdio.h>
#include <stdlib.h>

int a, b;
int *adra, *adrb;

/* --> declaration de fonction */
void echange(int *adra, int *adrb);
int read_int(int *adr);
/* <-- fin declaration de fonction */
/* 2.15 */
int faux_read_int(int *adr){
  return scanf("%d",adr);
}

int main(void)
{
  /* 2.11 tests */
  printf("********Test ex: 2.11\n");
  int a1 = 5, b1 = 4, a2 = -5, b2 = -4;
  printf("a1 = %d, b1 = %d, echange(&a1, &b1)\n", a1, b1);
  echange(&a1, &b1);
  printf("a1 = %d, b1 = %d \n", a1, b1);
  printf("a2 = %d, b1 = %d, echange(&a2, &b1)\n", a2, b1);
  echange(&a2, &b1);
  printf("a2 = %d, b1 = %d \n", a2, b1);
  printf("a2 = %d, b2 = %d, echange(&a2, &b2)\n", a2, b2);
  echange(&a2, &b2);
  printf("a2 = %d, b2 = %d \n", a2, b2);
  /* 2.12 tests */
  printf("\n\n*******Test ex: 2.12\n");
  int n, m;
  printf("entrez entier n SVP: ");
  scanf("%d", &n);
  printf("entrez entier m SVP: ");
  scanf("%d", &m);
  printf("entier placée dans l'adresse &n = %d, \
dans &m = %d, \n", n, m);
  printf("& est pour que la function lire les pointeurs *n\
 et *m et mettre les valeurs scanner de dans");
  printf("**********Test getchar():");
  // pour vidée le input buffer apres scanf()    
  while (getchar() != '\n');
  
  char c = getchar();
  printf("char c: %c", c);
  

  /* 2.13 */
  printf("**********Test 2.13 \n");
  while (c != '\n'){
    printf("Le caractere ’%c’ est en fait le nombre %d\n",c,c);
    c = getchar();
  }
  printf("un caractère est représenté en machine comme un \
nombre de ASCII table (man ascii)\n");
  
  /* 2.14 */
  printf("**********Test 2.14 \n");
  printf("l’expression (’5’-’0’) = 5 car ’5’=53 et ’0’= 48 \n" );
  
  /* 2.15 */
  printf("entrez entier pour read_int SVP:");
  int n1, n2;
  n2 = read_int(&n1);
  //printf("entrez faux entier SVP:%d ,%d", faux_read_int(&n), n);
  
  printf("read_int: %d ,%d", n1 , n2);
  
  return 0;
}

/* --> definition de fonction */

/* 2.11 echange */
void echange(int *adra, int *adrb)
{
  *adrb = *adrb + *adra;
  *adra = *adrb - *adra;
  *adrb = *adrb - *adra;
}

/* 2.12 scanf */
/*
 * & est pour que la function lire les pointeurs *n et *m et mettre les valeurs scanner de dans
*/
/* 2.15 read_int */
int read_int(int *adr)
{
  *adr = 0;
  char c = getchar();
  while(c != '\n')
    {
      if(c == 45 || c == 43)
	{
	  c = getchar();
	  if(47<c && c<58)
	    {
	      return 0;
	    }
	}
      while(47<c && c<58)
	{
	  *adr += (c - 48);
	  c = getchar();
	  if(c<48 || c>57)
	    {
	      return 1;
	    }
	  *adr *= 10;
	}
      c = getchar();
    }
  return 0;
}


/* <-- Fin definition de fonction */
