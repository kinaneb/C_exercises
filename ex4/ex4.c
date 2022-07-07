/* ****************************************************** */
/* BSHARA Kinan                                           */
/* TP: 4                                                  */
/* ex: 2                                                  */
/* ****************************************************** */

#include<stdio.h>
#include <stdlib.h>
/*
 * un fichie.c
 * dans le main test de prof :
 * appel init();
 * mercrodi soir
 * debut - prochaine celle libre
 * fin = debut - file vide
 * (debut +1  fin)%capacite - file plaine
 */
/*
 * tp5 il faut ecrir pluseur de tests verfier l'efficaté 
 * (example de tai 10 ** 6)
 * et la foctionnalité 
*/

//file_t suivants :
struct file_s {
  size_t debut, fin, capacite;
  int *elements;
};
typedef struct file_s file_t;
/*
 * ex1 avec realloc dynam
 */

/* --> declaration de fonction */
file_t *alloue_file(size_t capacite); 
void libere_file(file_t *file);

/* <-- fin declaration de fonction */

int main(void)
{
	/* my test
	 *
	 */
  int a[] ={1,2,3,4};
  int *b= a;
  file_t t;
  t = *alloue_file(5);
  
  printf("%d\n",b[0] );		
  printf("%lu\n",sizeof(*b[0]) );
    
  
  return 0;
}



file_t *alloue_file(size_t capacite)
{
  if (capacite==0)
    {return NULL;}
  file_t f;
  f.capacite = capacite;
  f.debut = 0;
  f.fin = 0;
  //f.elements;
  //printf("%zu\n", sizeof(int));
  f.elements = malloc((f.capacite -1)*sizeof(int));
    if(f.elements != NULL)
      {
	return &f;
      }
    else return NULL;
}



/* --> definition de fonction */
void libere_file(file_t *file);
/* 3.2.1 Impression */

/* 3.2.3 Construction */

/* <-- fin definition de fonction */
