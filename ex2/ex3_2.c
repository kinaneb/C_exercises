/* ****************************************************** */
/* BSHARA Kinan                                           */
/* TP 2                                                   */
/* ex: 3.2                                                */
/* ****************************************************** */

#include<stdio.h>
#include <stdlib.h>

struct rat{int num; int den;};

/* --> declaration de fonction */
void imp_rat(struct rat r);
short eq(struct rat r, struct rat s);
short leq(struct rat r, struct rat s);
struct rat build(int n, int d);
struct rat sum(struct rat r, struct rat s);
struct rat op(struct rat r);
struct rat mul(struct rat r, struct rat s);
struct rat inv(struct rat r);
/* <-- fin declaration de fonction */

int main(void)
{
  /* my tests */
  /*
  struct rat ssr;
  ssr = build(-5,7);
  struct rat ss ={ 6, 5};
  struct rat rr ={ 2, 25};
  imp_rat(ssr);
  imp_rat(sum(ss,rr));
  imp_rat(mul(ss,rr));
  imp_rat(op(ss));
  imp_rat(inv(ss));
  imp_rat(sum(op(ssr),ssr));
  imp_rat(mul(inv(ssr),ssr));
  printf("rat : %d\n", eq(rr,ss));
  printf("rat : %d\n", leq(rr,ss));
  */
  return 0;
}

/* --> definition de fonction */

/* 3.2.1 Impression */
void imp_rat(struct rat r)
{
  printf("rat : %d / %d\n", r.num , r.den);
}

/* 3.2.2 Comparaison */
short eq(struct rat r, struct rat s)
{
  if((r.num == s.num) && (r.den == s.den))
    {
      return 1;
    }
  else
    {
      return 0;
    }
}

short leq(struct rat r, struct rat s)
{
  if(r.den == s.den)
    {
      if(r.num>s.num)
	{
	  return 0;
	}
      else
	{
	  return 1;
	}
    }
  else
    {
      if(r.num*s.den < s.num*r.den)
	{
	  return 1;
	}
      else
	{
	  return 0;
	}
    }
}

/* 3.2.3 Construction */

int pgcd(int a, int b)
{
  int r;
  while (b != 0)
    {
      r = a%b;
      a = b;
      b = r;
    }
  return a;
}
struct rat build(int n, int d)
{
  struct rat newRat;
  if(d>0)
    {
      int p;
      p = abs(pgcd(n,d));
      if(p != 1)
	{
	  n /= p;
	  d /= p;
	}
      newRat.num = n;
      newRat.den = d;
      return newRat;
    }
  printf("den doit toujours étre un entier positif");
  newRat.num = 0;
  newRat.den = 0;
  return newRat;
}

/* 3.2.4 Operations arithmetiques: */

/* Operations arithmetiques: somme */
struct rat sum(struct rat r, struct rat s)
{
  if(r.den == s.den)
    {
      return build((r.num + s.num), r.den);
    }
  else
    {
      return build(((r.num*s.den)+(s.num*r.den)), (r.den*s.den));
    }
}

/* Operations arithmetiques: l'inverse additive */
struct rat op(struct rat r)
{

  return build((-1*r.num), r.den);
}

/* Operations arithmetiques: multiplication */
struct rat mul(struct rat r, struct rat s)
{
  return build((r.num*s.num), (r.den*s.den));
}

/* Operations arithmetiques: inverse multiplicative */
struct rat inv(struct rat r)
{
  if(r.num>0)
    {
      return build(r.den, r.num);
    }
  else if(r.num<0)
    {
      return build((-1*r.den), (-1*r.num));
    }
  else
    {
      return r;
    }
}

/* <-- fin definition de fonction */
