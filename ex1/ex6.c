/* BSHARA Kinan */

/*  Input/output library */
#include <stdio.h>


/* main function */
int main(void) {

	int nb;
	printf("entre nb SVP\n");
	scanf("%d", &nb);
	/* negative variable to deal with the case nb<=0 */
	int neg = 0;

	if (nb <= 0)
	{
		/* neg = 1 if nb<0 (negative) or nb=0 */
		neg = 1;
	}
	/* if nb<=0 or nb>1000, nb strictly between 0 and 1000 (0<nb>1000) */
	if (neg || nb >= 1000){
		if(neg)
		{
			/* to save the sign of nb, if nb=0 -1*0=0 */
			nb = -1*nb;
		}
		/* x variable to keep the value of inverse nb  */
		int x = 0;

		/** while nb>0 multiply x by 10 to have place of one digit to right 
		 * then we add the result of nb modulo 10 to get last digit to the right
		 * at the end we divide nb by 10 to remove last digit to the right from nb 
		 * after adding it to x */
		while(nb>0){
			x *= 10;
			x += nb % 10;
			nb /= 10;
		}
		if(neg)
		{
			/* to resign nb, if nb=0 -1*0=0 */
			x = -1*x;
		}
		printf("%d\n", x);
	}

	/** else: 0<nb>1000 print */
	else
	{
		printf("%d est bien entre 0 et 1000, merci !!!\n", nb);
	}

	/** main function return */
	return 0;
}
