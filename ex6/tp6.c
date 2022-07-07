/* ****************************************************** */
/* BSHARA Kinan                                           */
/* tp: 5                                                  */
/*                                                        */
/* ****************************************************** */


/*
 consignes:
 un ABR représenter un ensemble et contient chaque élément (entier) au plus une fois
 A rundre Mercrudi a la fin de la siance      avec Arbre 10**6
 1 _ ajoute      complixuté a propotionbelle à la proufondeur de l'arbre
 8 _ supprme
 12_ isBalanced  lineérre dans le nb due noeuds de l'arbre
 
 
 chek ou my_check ??????? ????? ???????
 free(tab)
 Thread 1: signal SIGABRT
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

/* --> définition de fonction */

struct node {
    int val;
    struct node * left;
    struct node * right;
};
typedef struct node node;

/* <-- fin définition de fonction */

node *newNode(int n);
node *ajout(int val, node *T);
short recherche(int val, node *T);
void affiche(node *T);
int maximum(node *T);
int minimum(node *T);
node *randomABR(int n, int m);
void swap(int *a, int *b);
int *randomPerm(int *n, int i);
short check(node *T);
short my_check(node *T);
node *supprime(int val, node *T);
void clean(node *T);

/* --> declaration de fonction */
void printTab(int *tab, int i)
{
    printf("\n ");
    for(; i > 0; i--)
    {
        printf("%d ,",tab[i]);
    }
    printf("\n ");
}

/* <-- fin declaration de fonction */

int main(void) {
    node *t= malloc(sizeof(node));;
    //    t->right = newNode(5)->left = newNode(7);
    //    printArb(t);
    //    short chek ;
    //
    //    chek = check(t);
    //    printf(" check = %hd ",chek );
    //    printf("\n");
    //    chek = my_check(t);
    //    printf(" my_check = %hd ",chek );
    //    printf("\n");
    //short c;
    //clock_t start_t, end_t, total_t;
    //start_t = clock();
    t=randomABR(9, 10);
    //printf("Starting of the program, start_t = %ld\n", start_t);
    //    for(int i = 0; i < 1000; i++){
    //        t=randomABR(1000000, 7);
    //        //printArb(t);
    //        c = my_check(t);
    //        if(c == 0)
    //        {
    //            printf("\n");
    //            printf(" check = 0 , i = %d ", i);
    //            printf("\n");
    //        }
    //    }
    
    //printArb(t);
    //c = check(t);
    //end_t = clock();
    //printf("End of the big loop, end_t = %ld\n", end_t);
    //total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    //printf("Total time taken by CPU: %lu\n", total_t  );
    
    affiche(t);
    t = supprime(6, t);
    //free(t);
    printf("\n end \n");
    //printf("\n end \n");
    affiche(t);
    
    //free(t);
    
    
    return 0;
}

/* --> definition de fonction */

/* ex: 1.1  */
struct node *newNode(int n)
{
    node *x;
    x = malloc(sizeof(node));
    if(x != NULL){
        x->val = n;
        x->left= NULL;
        x->right= NULL;
        return x;
    }
    
    printf("new node malloc failure: \n");
    return NULL;
}

/* ex: 1.2 */

node *ajout(int val, node *T)
{
    //node *r = T;
    
    if(T == NULL)
    {
        return T = newNode(val);
    }
    if(T->val == val)
    {
        return T;
    }
    if (val > T->val)
    {
        T->right = ajout(val, T->right);
    }
    if(val < T->val)
    {
        T->left = ajout(val, T->left);
    }
    return T;
}

/* ex: 1.3 */
short recherche(int val, node *T)
{
    if(T == NULL)
    {
        return 0;
    }
    if(T->val == val)
    {
        return 1;
    }
    if (val > T->val)
    {
        return recherche(val, T->right);
    }
    if (val < T->val)
    {
        return recherche(val, T->left);
    }
    return 0;
}
/* ex 1.4 */
int maximum(node *T)
{
    if(T == NULL)
    {
        printf("Arbre est vide \n");
        return INT_MAX;
    }
    if(T->right == NULL)
    {
        return T->val;
    }
    else
    {
        return maximum(T->right);
    }
}
int minimum(node *T)
{
    if(T == NULL)
    {
        printf("Arbre est vide \n");
        return INT_MIN;
    }
    if(T->left == NULL)
    {
        return T->val;
    }
    else
    {
        return maximum(T->left);
    }
}
/* ex: 1.5 */

void swap (int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}
int *randomPerm(int *n, int i)
{
    srand((int)(time(NULL)));
    int r;
    
    for (; i > 0; i--){
        r= rand() % i;
        if (i != r)
        {
            swap(&n[i], &n[r]);
        }
    }
    return n;
}


node *randomABR(int m, int n)
{
    if((m < 0)||(n > m+1))
    {
        // un ABR représenter un ensemble et contient chaque élément (entier) au plus une fois alors n < m+1
        printf("\n m = 0 or n > m+1 ???\n");
        return NULL;
    }
    int *tab = NULL;
    tab = malloc(m*sizeof(int));
    if(tab == NULL){
        printf("Error malloc failure \n");
        return NULL;
    }
    for(int i = 0; i <= m; i++)
    {
        tab[i] = i;
    }
    tab = randomPerm(tab, m);
    node *r = newNode(tab[n--]);
    
    for(; n > 0; n--)
    {
        r = ajout(tab[n], r);
    }
    
    free(tab);
    return r;
}


/* 1.6 */
short check(node *T)
{
    if(T == NULL)
    {
        return 0;
    }
    if(T->left)
    {
        if(maximum(T->left) > T->val)
        {
            return 0;
        }
        return check(T->left);
    }
    if(T->right)
    {
        if(minimum(T->right) < T->val)
        {
            return 0;
        }
        return check(T->right);
    }
    return 1;
}
/* without using min and max */
short my_check(node *T)
{
    if(T == NULL)
    {
        return 0;
    }
    if(T->left != NULL)
    {
        if(T->left->val > T->val)
        {
            return 0;
        }
        return check(T->left);
    }
    if(T->right != NULL)
    {
        if(T->right->val < T->val)
        {
            return 0;
        }
        return check(T->right);
    }
    return 1;
}

/* 1.7 */
void affiche(node *T)
{
    if(T == NULL)
    {
        return;
    }
    affiche(T->left);
    printf("%d ",T->val);
    affiche(T->right);
}

/* 1.8 */
int supprime_min(node *T)
{
    if(T->left)
    {
        return supprime_min(T->left);
    }
    int v = T->val;
    printf(" sB \n");
    affiche(T);
    node *tmp = T->right;
    free(T->right);
    T = tmp;
    
    printf(" sA \n");
    affiche(T);
    return v;
}

node *supprime(int val, node *T)
{
    if(T == NULL)
    {
        return T;
    }
    if(val > T->val)
    {
        T->right = supprime(val, T->right);
        return T;
    }
    if(val < T->val)
    {
        T->left = supprime(val, T->left);
        return T;
    }
    if (T->left == NULL) {
        node *tmp = T->right;
        free(T);
        return tmp;
    }
    else if (T->right == NULL) {
        node *tmp = T->left;
        free(T);
        return tmp;
    }
    else
    {
        T->val = supprime_min(T->right);
        return T;
    }
}

/* 1.9 */
void clean(node *T)
{
    if(T)
    {
        if(T->left)
        {
            clean(T->left);
            T->left = NULL;
            
        }
        if(T->right)
        {
            clean(T->right);
            T->right = NULL;
        }
    }
    if(T == NULL)
    {
        free(T);
        
    }
    
}


/* --> fin definition de fonction */
