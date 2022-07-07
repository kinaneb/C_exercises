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
 */

#define N 255
char libre = 'L';
unsigned char taille = N-2;

unsigned char memoire[N]; // all tabel cells will be initialized to zero

/* --> declaration de fonction */
void init();
void* search_free_blocks(int x);
void *my_alloc(int x);
void my_free(void *m);
/* <-- fin declaration de fonction */

int main(void)
{
  /* my test
   *
   */
  init();
  /*
  memoire[0]='O';
  memoire[1]=10;
  memoire[12]='L';
  memoire[13]=10;
  memoire[14]='_';
  memoire[24]='L';
  memoire[25]=10;
  memoire[36]='L';
  memoire[37]=150;
  */
  void *c =my_alloc(50);
  //void *c2 = search_free_blocks(1);
  /*
  void *c3 = search_free_blocks(2);
  void *c4 = search_free_blocks(200);
  void *c5 = search_free_blocks(25);
  void *c6 = search_free_blocks(2);
  */
  char *cc = c;
  if (cc==NULL){
    printf("not allocated \n");
  }
  printf("1\n");
  void *c1 =my_alloc(55);
  printf("2\n");
  void *c2 =my_alloc(55);
  printf("3\n");
  my_free(c2);
  printf("4\n");
  void *c3 =my_alloc(56);
  printf("5\n");
  void *c4 =my_alloc(58);
  return 0;
}







/* --> definition de fonction */
void init()
{
  memoire[0] = libre; 
  memoire[1] = taille;
}
/* 2.3  search_free_blocks */
void* search_free_blocks(int x)
{
  
 
  if(x > taille)
    {
      return NULL;
    }
  int i = 0;
  while(i<N)
    {
      if(memoire[i] == 'O')
	{
	  i += (memoire[i+1]+2);
	}
      if(memoire[i] == 'L'){
	if(memoire[i+1] >= x)
	  {
	    return (memoire+i+2);
	  }
	if(memoire[i+memoire[i+1]+2] == 'O')
	  {
	    return NULL;
	  }
	else if(memoire[i+memoire[i+1]+2] == 'L')
	  {
	   memoire[i+1] += ( memoire[i + memoire[i+1] + 3] + 2);
	    
	  }
	if(N-2 < i+x)
	  {
	    return NULL;
	  }
      }
    }
  return NULL;
}
/* 2.4 my_alloc */
void *my_alloc(int x)
{
  unsigned char *m = search_free_blocks(x);
  m[-2] = 'O';
  if(m[-1] > x+2)
    {
      m[x] = 'L';
      m[x+1] = m[-1]-(x+2);
      m[-1] = x;
    }
  return m;
}
/* 2.5 my_free */
void my_free(void *m)
{
  unsigned char *c = m;
  c[-2]= 'L';
}
/* <-- fin definition de fonction */
