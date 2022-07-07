
/* ****************************************************** */
/* BSHARA Kinan                                           */
/* tp: 4                                                  */
/* ex: 1                                                */
/* ****************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

 struct node
{
    int val;
    struct node * next;
} ;
typedef struct node node;

struct part
{
    struct node *lg;
    struct node *pivot;
    struct node *ld;
    
};
typedef struct part part;

/* --> declaration de fonction */

struct node *newNode(int n);
struct node *genlist(int n);
void prlist(struct node * l);
short verifsort(struct node * l, int n);
struct node *lastN(node *l);
struct part partition (struct node *l);


/* <-- fin declaration de fonction */


int main(void) {
    node *n;
    n = genlist(9);
     printf("\n");
    prlist(n);
    printf("\n");
    partition(n);
    //free(n);
    return 0;
}


/* --> definition de fonction */

/* ex: 1 newNode() */
struct node *newNode(int n)
{
    node *x;
    x = malloc(sizeof(node));
    x->val = n;
    x->next= NULL;
    if(x == NULL){
        perror("new node malloc failure: ");
        EXIT_FAILURE;
    }
    return x;
}

/* ex: 2 genlist */
struct node *genlist(int n)
{
    node *tet;
    time_t t;
    srand((int) time(&t));
    tet = newNode(n ? (rand() % n) : 0);
    if(n>0)
    {
        tet->next = genlist(n-1);
    }
    return tet;
}
/* ex: 2.2 prlist */
void prlist(struct node * l)
{
    
    if(l->next == NULL)
    {
        return ;
    }
        
        printf("%d ",l->val);
        prlist(l->next);
        
    

}

/* ex: 3 verifsort */
short verifsort(struct node * l, int n)
{
    if(l->next != NULL)
    {
        if(l->val == n)
        {
            verifsort(l->next, n-1);
        }
        return 0;
    }
    return 1;
}
/* ex: 4 verifsort */

struct node *lastN(node *l)
{
    if(l->next != NULL)
    {
        return lastN(l->next);
    }
    return l;
   
}



struct part partition (struct node *l)
{
    part p;
    node *tem = l;
    p.pivot = newNode(l->val);
    l = l->next;
    
    while(l->next != NULL)
    {
        if(p.pivot->val >= l->val)
        {
            if(p.lg != NULL)
            {
                lastN(p.lg)->next = newNode(l->val);
                l = l->next;
            }else{
                
                p.lg = newNode(l->val);
                l = l->next;
            }
            
            
        }
        if(p.pivot->val < l->val)
        {
            if(p.ld != NULL)
            {
            lastN(p.ld)->next = newNode(l->val);
            l = l->next;
            }else{
                p.ld = newNode(l->val);
            }
        }
    }
    free(tem);
    prlist(p.ld);
    printf("ld \n");
    prlist(p.lg);
    printf("lg \n");
    printf("pivot = %d \n",p.pivot->val);
    printf("piv \n");
    return p;
}

/* <-- fin definition de fonction */
