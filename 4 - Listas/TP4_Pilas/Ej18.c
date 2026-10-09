#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>

int esPalindroma(char* s)
{
    if(!s) return 0;

    Dstack* tempStack = Dstack_new();
    if(!tempStack) return 0;

    for(int i=0; s[i]!='\0'; i++)
    {
        if(s[i]!=' ')
        {
            Dpush(tempStack,s[i]);
        }
    }

    int noCoincide = 0;
    for(int i=0; s[i]!='\0' && noCoincide==0; i++)
    {
        if(s[i]!=' ')
        {
            if(Dpop(tempStack)!=s[i])
            {
                noCoincide++;
            }
        }
    }

    Dstack_free(tempStack);

    if(noCoincide==0)
    {
        return 1;
    } else
    {
        return 0;
    }
}
