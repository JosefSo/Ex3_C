#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "my_func.h"


char *reverse(char *str)
{
    char *p1, *p2;
    if (!str || !*str)
        return str;
    for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
    {
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
    }
    return str;
}

char *atbsh(char *word)
{
    char *atbash = (char *)malloc(strlen(word) * sizeof(char));
    strcpy(atbash, word);
    int i = 0;
    char c = 0;
    while ((c = *(atbash + i)) != '\0')
        if (isalpha(c) > 0)
            *(atbash + i++) = isupper(c) ? 91 - (c - 64) : 123 - (c - 96);
        else
            i++;
    return atbash;
}


void Atbash(char *txt, char *word)
{
    //convert word to atbash
    char *atbash = atbsh(word);
    //new allocate to revers atbash
    char *reverse_atbash = (char *)malloc(strlen(atbash) * sizeof(char));
    //copy atbash word
    strcpy(reverse_atbash, atbash);
    //reverse atbash word to the new var allocate
    reverse_atbash = reverse(reverse_atbash);
    int lenght = strlen(atbash);
    int i = 0, j = 0;
    int flag = 0;
    while (*(txt + i) != '\0')
    {
        while (lenght - j)
        {
            if (*(txt + i + j) == *(atbash + j) || *(txt + i + j) == *(reverse_atbash + j))
            {
                j++;
                continue;
            }
            break;
        }
        if (lenght - j == 0)
        {
            int k = i;
            if (flag > 0)
                printf("%c", '~');
            while (k < i + j)
                printf("%c", *(txt + k++));
            flag++;
        }
        j = 0;
        i++;
    }
    printf("\n");
    free(atbash);
    free(reverse_atbash);
}

        

 

