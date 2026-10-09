#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>

int perteneceAlConjunto(char* s, char c)
{
    if(!s) return 0;

    int pertenece = 0;
    int len = strlen(s);
    for(int i=0; i<len; i++)
    {
        if(c==s[i])
        {
            pertenece = 1;
        }
    }

    return pertenece;
}

int operacionBalanceada(char* s)
{
    if(!s) return -1;

    int len = strlen(s);
    Dstack* agrupadores = Dstack_new();
    if(!agrupadores) return -1;
    // En caso de que se encuentre desbalanceo levanto flag
    int flag = 0;
    char aperturas[] = "([{";
    char cierres[] = ")]}";

    int i=0;
    while(i<len && flag==0)
    {
        if(perteneceAlConjunto(aperturas,s[i]))
        {
            Dpush(agrupadores,s[i]);
        }
        else if(perteneceAlConjunto(cierres,s[i]))
        {
            if((s[i] == ')' && Dtop(agrupadores) == '(') ||
                    (s[i] == ']' && Dtop(agrupadores) == '[') ||
                    (s[i] == '}' && Dtop(agrupadores) == '{'))
            {
                Dpop(agrupadores);
            }
            else
            {
                flag++;
            }
        }
        i++;
    }

    if(Dstack_isempty(agrupadores) && flag==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
