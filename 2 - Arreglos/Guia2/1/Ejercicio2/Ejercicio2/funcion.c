#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

void vectorRandom(vector *v)
{
    if(v==NULL) return;

    int randomNum;
    for(int i=0; i<100; i++)
    {
        randomNum = rand();
        vector_add(v,randomNum);
    }
}
void print(VECTOR_ELEMENT x)
{
    printf("%d",x);
}
