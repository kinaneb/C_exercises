
/* ****************************************************** */
/* BSHARA Kinan                                           */
/* tp: 8                                                  */
/* ****************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>



/* -->declaration des types et structures */
typedef enum { PLUS = '+', MINUS = '-', MULT = '*', DIV = '/'} ops;

struct node
{
    char *etiquette;
    struct node *left;
    struct node *right;
};
typedef struct node node;
/* <-- fin declaration des types et structures */

/* --> declaration de fonction */
void normalise( char * s);
short Subckeck(char *s,int *pos);
short check(char *s);
short isOps(char c);
short ismultiDig(char *s, int *pos);
void remSpcae(char *s, int *pos);
node *newNode(char *c);
node *arborescence(char *s);
node *intermediaire(char *s, int *pos);
char *myTokenize(char *s, int *pos, int i);
char *conversion(char *s);
void printArbre(node *n);
void convEnter(node *n, char *s);
long evaluation(char * s);
/* <-- fin declaration de fonction */

int main(int argc, const char * argv[]) {

    FILE *fp; // file type pointer
    char s[1024]; // my buffer
    int i = 1;
    if (argc > 1)
    {
      fp = fopen(argv[1], "r"); // open in read only mode file named as string in first argument of argv
      if (fp == NULL) // fail of opening file
      {
          perror("error opening the file.\n");
          exit(EXIT_FAILURE);
      }
      while (fgets(s, 1024, fp) != NULL) // file text not ended
      {
        memset(&s[strlen(s)-1],'\0',  1); // set end of string s
        printf(" test: %d, le sequence est: %s\n",i, s);
        if(check(s))
        {
          char *d = conversion(s);
          printf(" test: %d, infix expression: %s\n",i, d);
          long l = evaluation(s);
          printf(" test: %d, expression evaluation: %lu\n\n",i , l);
        }
        else
        {
          printf(" test: %d, error not good expression !\n", i);
        }
        i++;
        printf(" *** *** *** *** **** *** *** *** *** *** ***\n");
      }
      fclose(fp); // close file
    }
    return 0;
}

/* --> definition de fonction */
/* ex: 3.5 normalise */
void normalise( char * s)
{
    int i = 0;
    short tolerance =0;/*si on tolere l'espace*/
    int pos = 0;/*on ecrit ici dans pos*/
    while(s[i]!='\0'){
        if(!isblank(s[i])||tolerance==1){
            if(pos!=0 && s[i] == ')' && s[pos-1] == ' '){
                pos--;
            }
            s[pos]=s[i];
            printf(" ** %s\n", s);
            pos++;
            if(isblank(s[i])||s[i]=='(')
            {
                tolerance =0;
            }
            else{
                tolerance = 1;
            }
        }
        i++;
    }
    if(s[pos-1]==' ')
        pos--;
    s[pos]='\0';
}

/* test if 'c' is a operation */
short isOps(char c)
{
    switch(c) {
        case PLUS:
        case MINUS:
        case MULT:
        case DIV:
            return 1;
        default:
            return 0;

    };

}

/* read a sequence of digit starting from *pos
 * if it is a digit and return 1 else return 0*/
short ismultiDig(char *s, int *pos)
{
    if(isdigit(s[*pos]))
    {
        while(isdigit(s[*pos]))
        {
            (*pos)++;
        }
        return 1;
    }
    return 0;
}

/* remove a sequence spaces starting from *pos */
void remSpcae(char *s, int *pos)
{
    int i = *pos;
    if (isblank(s[i]))
    {
        while(isblank(s[++i]))
        {}
        if(*pos < i)
        {
            size_t n = strlen(s);
            memmove(s+*pos, s+i, n-(i-*pos) );
            memset(s+(n-(i-*pos)), '\0', 1);
        }
    }
}

/* ex: 3.6 Subckeck */
short Subckeck(char *s,int *pos)
{
    if(isblank(s[*pos]))
    {
      remSpcae(s, pos);
    }
    if(s[*pos]!='(')
    {
      return 0;
    }
    else
    {
      (*pos)++;
      if(isblank(s[*pos]))
      {
          remSpcae(s, pos);
      }
      if(!isOps(s[*pos]))
      {
          return 0;
      }
      else
      {
        (*pos)++;
        if(isblank(s[*pos]))
        {
          (*pos)++;
          remSpcae(s, pos);
        }
        if(!(ismultiDig(s, pos) || Subckeck(s,pos)))
        {
          return 0;
        }
        else
        {
          if(isblank(s[*pos]))
          {
            (*pos)++;
            remSpcae(s, pos);
          }
          if(!(ismultiDig(s, pos) || Subckeck(s, pos)))
          {
            return 0;
          }
          else
          {
            if(isblank(s[*pos]))
            {
              (*pos)++;
              remSpcae(s, pos);
            }
            if(s[*pos] !=')')
            {
              return 0;
            }
            else
            {
              (*pos)++;
              if(isblank(s[*pos]))
              {
                (*pos)++;
                remSpcae(s, pos);
              }
              if(s[*pos]=='\0' && isblank(s[*pos-1]))
              {
                (*pos)--;
                remSpcae(s, pos);
              }
              return 1;
            }
          }
        }
      }
    }
}

/* ex: 3.6 check */
short check(char *s)
{
  int pos = 0;
  return (Subckeck(s, &pos) && s[pos] =='\0');
}

/* create new Node */
node *newNode(char *c)
{
  node *x;
  x = malloc(sizeof(node));
  if(x)
  {
    x->etiquette = c;
    x->left= NULL;
    x->right= NULL;
    return x;
  }
  printf("new node malloc failure: \n");
  return NULL;
}

/* ex: 3.7 arborescence */
node *arborescence(char *s)
{
  int pos = 0;
  return (intermediaire(s, &pos));
}
node *intermediaire(char *s, int *pos)
{
  while(isblank(s[*pos]))
  {
    (*pos)++;
  }
  if(s[*pos] == '(')
  {
    (*pos)++;
    if(isOps(s[*pos]))
    {
      node *r = newNode(myTokenize(s, pos, 1));
      (*pos)++;
      while(isblank(s[*pos]))
      {(*pos)++;}
      r->left = intermediaire(s, pos);
      while(isblank(s[*pos]) || (s[*pos] == ')'))
      {(*pos)++;}
      r->right = intermediaire(s, pos);
      return r;
    }
    }
    while(isblank(s[*pos]))
    {
      (*pos)++;
    }
    if(isdigit(s[*pos]))
    {
      int i = 0;
      while(isdigit(s[i+*pos]))
      {
          ++i;
      }
      char *t = myTokenize(s, pos, i);
      if(!(atol(t)>INT_MAX))
      {
        node *r = newNode(t);
        if(i > 0)
        {
          while(i--){(*pos)++;}
        }
        return r;
      }
      else

      {
        printf(" error sequence is bigger than int\n");
        s[(*pos)+1] = 'z';
      }
    }
    return NULL;
}

/* retrun i chars as string starting from *pos */
char *myTokenize(char *s, int *pos, int i){
    char *myS = calloc(sizeof(char),(i+1));
    if(myS){
        strncpy(myS, &s[(*pos)], i);
        memset(&myS[i], '\0', 1);
        //printf("error myTokenize %s\n", myS);
        return myS;
    }
    printf("myTokenize malloc failure: \n");
    return NULL;
}

/* print Arbre */
void printArbre(node *n)
{
    if(!n)
    {
        return;
    }
    if(n->left){
        printf("( ");
    }

    printArbre(n->left);
    printf("%s ",n->etiquette);
    printArbre(n->right);
    if(n->right){printf(")");}

}

/* ex: 3.8 convEnter concatenate (infix) all nodes labels of tree n */
void convEnter(node *n, char *s)
{
    if(!n)
    {
        return;
    }
    if(n->left){
        strcat(s, "(");
    }
    convEnter(n->left, s);
    strcat(s, n->etiquette);
    convEnter(n->right, s);
    if(n->right)
    {
        strcat(s, ")");
    }
}

/* 3.8 conversion create tree from s sequence and return
 * the concatenating (infix) of its nodes labels as string */
char *conversion(char *s)
{
    if(!check(s))
    {
      printf("conversion !check(s) failure: \n");
      return NULL;
    }
    size_t n = strlen(s)+5;
    char *envS = calloc(n, sizeof(char));
    if(!envS)
    {
      printf("conversion malloc failure: \n");
      return envS;
    }
    convEnter(arborescence(s), envS);
    memset(&envS[n], '\0', 1);
    return envS;
}

/* ex: 9 evalEnter evaluate the results of n tree nodes at l */
long evalEnter(node *n, long *l)
{
    if(!n)
    {
        return 0;
    }
    if(n->left && n->right){
        switch(n->etiquette[0]) {
            case PLUS:
                return evalEnter(n->left, l) + evalEnter(n->right, l);
                break;
            case MINUS:
                return evalEnter(n->left, l) - evalEnter(n->right, l);
                break;
            case MULT:
                return evalEnter(n->left, l) * evalEnter(n->right, l);
                break;
            case DIV:
                return evalEnter(n->left, l) / evalEnter(n->right, l);
                break;
            default:
                return 0;
        };
    }
    if(n->left){
        switch(n->etiquette[0]) {
            case PLUS:
                return evalEnter(n->left, l) + *l;
                break;
            case MINUS:
                return evalEnter(n->left, l) - *l;
                break;
            case MULT:
                return evalEnter(n->left, l) * *l;
                break;
            case DIV:
                return evalEnter(n->left, l) / *l;
                break;
            default:
                return 0;
        };
    }
    if(n->right)
    {
        switch(n->etiquette[0]) {
            case PLUS:
                return *l + evalEnter(n->right, l);
                break;
            case MINUS:
                return *l - evalEnter(n->right, l);
                break;
            case MULT:
                return *l * evalEnter(n->right, l);
                break;
            case DIV:
                return *l / evalEnter(n->right, l);
                break;
            default:
                return 0;
        };
    }
    if(!(n->right) && !(n->left))
    {
        return atoi(n->etiquette);
    }
    return *l;
}
/* ex: 3.9 evaluation */
long evaluation(char * s)
{
  if(!check(s))
  {
    printf("conversion !check(s) failure: \n");
    return 0;
  }
  long l = 0;
  return evalEnter(arborescence(s), &l);
}
