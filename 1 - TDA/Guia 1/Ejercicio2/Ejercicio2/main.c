#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "charset.h"

int main()
{
    char *arrayStrings[33] = {0};

    arrayStrings[0] = "sapos";
    arrayStrings[1] = "trapo";
    arrayStrings[2] = "plato";

    printf("%s",string_commonLetters(arrayStrings));

    return 0;
}
