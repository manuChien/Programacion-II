#include <stdio.h>
#include <stdlib.h>
#include "fracciones.h"

struct _fraction{
    int num;
    int den;
}fraction;

// crear una fracción
fraction* fraction_new (int num, int den)
{
    if(den==0)
    {
        printf("The den logged is not valid.\n");
        return NULL;
    }
    fraction *newFraction = malloc(sizeof(fraction));
    if(newFraction==NULL)
    {
        printf("An error occurred while creating the new fraction.\n");
        return NULL;
    }

    if(den<0)
    {
        num = -num;
        den = -den;
    }

    newFraction->num = num;
    newFraction->den = den;

    return newFraction;
}

//destruir una fracción
void fraction_destroy (fraction* f)
{
    if(f==NULL)
    {
        printf("The fraction requested for deleting is not valid.\n");
        return;
    }

    f->num = 0;
    f->den = 0;
    free(f);
}

//imprimir una fracción
void fraction_print (fraction* f)
{
    if(f==NULL)
    {
        printf("The fraction requested for printing is not valid.\n");
        return;
    }

    printf("%d / %d",f->num,f->den);
}

//obtener numerador
int fraction_get_num (fraction* f)
{
    if(f==NULL)
    {
        printf("The fraction requested for getting num is not valid.\n");
        return 0;
    }

    return f->num;
}

//obtener denominador
int fraction_get_den (fraction* f)
{
    if(f==NULL)
    {
        printf("The fraction requested for getting den is not valid.\n");
        return 0;
    }

    return f->den;
}

//sumar 2 fracciones
fraction* fraction_add (fraction* f1, fraction* f2)
{
    if(f1==NULL || f2==NULL || f1->den==0 || f2->den==0)
    {
        printf("The fractions requested for adding are not valid.\n");
        return NULL;
    }

    fraction *answer = fraction_new(1,1);

    answer->num = f1->num * f2->den + f2->num * f1->den;
    answer->den = f1->den * f2->den;

    fraction_simplify(answer);

    return answer;
}

//restar 2 fracciones
fraction* fraction_sub (fraction* f1, fraction* f2)
{
    if(f1==NULL || f2==NULL || f1->den==0 || f2->den==0)
    {
        printf("The fractions requested for substracting are not valid.\n");
        return NULL;
    }

    fraction *answer = fraction_new(1,1);

    answer->num = f1->num * f2->den - f2->num * f1->den;
    answer->den = f1->den * f2->den;

    fraction_simplify(answer);

    return answer;
}

//multiplicar 2 fracciones
fraction* fraction_mul (fraction* f1, fraction* f2)
{
    if(f1==NULL || f2==NULL || f1->den==0 || f2->den==0)
    {
        printf("The fractions requested for multiplicating are not valid.\n");
        return NULL;
    }

    fraction *answer = fraction_new(1,1);

    answer->num = f1->num * f2->num;
    answer->den = f1->den * f2->den;

    fraction_simplify(answer);

    return answer;
}

//dividir 2 fracciones
fraction* fraction_div (fraction* f1, fraction* f2)
{
    if(f1==NULL || f2==NULL || f1->den==0 || f2->den==0 || f2->num==0)
    {
        printf("The fractions requested for dividing are not valid.\n");
        return NULL;
    }

    fraction *answer = fraction_new(1,1);

    answer->num = f1->num * f2->den;
    answer->den = f1->den * f2->num;

    if(answer->den < 0)
    {
        answer->den = -(answer->den);
        answer->num = -(answer->num);
    }

    fraction_simplify(answer);

    return answer;
}

//simplificar una fracción
void fraction_simplify (fraction* f)
{
    if(f==NULL || f->den==0)
    {
        printf("The fractions requested for adding are not valid.\n");
        return;
    }

    int maxCommonDiv;
    int num = f->num;
    int den = f->den;
    if(num<0) num=-num;
    if(den<0) den=-den;
    if(num >= den)
    {
        maxCommonDiv = mcd(num,den);
    } else if(num < den)
    {
        maxCommonDiv = mcd(den,num);
    }
    f->num = f->num / maxCommonDiv;
    f->den = f->den / maxCommonDiv;
}

//comparar 2 fracciones
int fraction_cmp (fraction* f1, fraction* f2)
{
    fraction *fraccion = fraction_sub(f1,f2);
    int signo = fraccion->num;

    fraction_destroy(fraccion);
    return signo;
}
