/* ****************************************************** */
/* BSHARA Kinan                                           */
/* TP 2                                                   */
/* ex: 3.2                                                */
/* ****************************************************** */

#include<stdio.h>
#include <stdlib.h>

void imprime_diag(int m, int n, int a[m][n]);

int main(void)
{
  /* my test */
  /*
  int tab1[5][5] = {{0,1,2,3,4},
		   {1,2,3,4,5},
		   {2,3,4,5,6},
		   {3,4,5,6,7},
		   {4,5,6,7,8}};
  imprime_diag(5,5,tab1);
  
  int tab2[4][5] = {{0,1,2,3,4},
		   {1,2,3,4,5},
		   {2,3,4,5,6},
		    //{3,4,5,6,7},
		   {4,5,6,7,8}};
  imprime_diag(4,5,tab2);

  int tab3[5][4] = {{0,1,2,3},
		   {1,2,3,4},
		   {2,3,4,5},
		   {3,4,5,6},
		   {4,5,6,7}};
  imprime_diag(5,4,tab3);
  */
}

/* 
   int m, int n, int tab[m][n]
   tab[i][j] = (i+j)
  i->0 1 2 3 4
j
1    0|1|2|3|4
2    1|2|3|4|5
3    2|3|4|5|6
4    3|4|5|6|7
5    4|5|6|7|8
   the idea is to print all tab[i][j] while (i+j =0), 
   *                                       then( =1),
   *                                           ( =2),...
   *                                           ( =m+n)  
*/
void imprime_diag(int m, int n, int a[m][n])
{
  int x = m+n-2; /* maximum sum of i,j a[i][j] in the
		  *table */
  for(int mx = 0; mx<=x; mx++) /* starting with sum(i,j)=0
				* end at sum(i,j)=x*/
    {
      for(int i = 0; i<m; i++)
	{
	  for(int j = 0; j<n; j++)
	    {
	      if( (i+j)-mx == 0 )
		/* print a[i][j] when i+j = mx 
		 *(from 0 to x ) so print all a[i][j]
		 * when i+j = 0 then all when = 1,
		 * then all when = 2 ....*/
		{
		  printf("%d ,",a[i][j]);
		}
	    }
	}
    }
  printf("\n");
}
