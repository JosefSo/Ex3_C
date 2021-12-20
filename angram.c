#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "my_func.h"


int val(char* word){

    int i = 0;

    while(word[i])
    {
        i++;
    }
    return i;
}


void reduce(char* word,int p){
    int i = 0;
    int j = 0;
    char n[WORD];
    strcpy(n,word);

    while(word[j])
    {
        if(i==p)
        {
            i++;
            continue;
        }
        word[j] = n[i];
        i++;
        j++;
    }
}

void Anagram(char* word,char* text){


    int status = 0;
    int wordVal = 0;

    int i = 0;
    int j = 0;
    int p = 0;
    int c = 0;

    wordVal = val(word);
    int check = wordVal;

    char temp_word[WORD];
    char temp_text[TXT];
    char temp[32];
    char res[1024];

    strcpy(temp_word,word);
    strcpy(temp_text,text);

    while(temp_text[i] && temp_text[i]!='~'){

        j=i;

        if(temp_word[p]==temp_text[i])
        {
            temp[c++] = temp_text[j++];
            reduce(temp_word,p);
            p = 0;
            check--;

            while(temp_text[j]!='~' && p<=check)
            {
                if(temp_text[j]==' ')
                {
                    temp[c++] = temp_text[j++];
                }

                if(temp_word[p]==temp_text[j]){
                    temp[c++] = temp_text[j++];
                    reduce(temp_word,p);
                    check--;
                    p = 0;
                    if(check==1 && temp_word[0]==temp_text[j])
                    {
                        temp[c] = temp_text[j];
                        temp[++c] = '~';
                        temp[++c] = '\0';
                        while(p<c){
                            res[status++] = temp[p++];
                        }
                        p = 0;
                        break;
                    }
                    continue;
                }
                p++;
            }
            p = 0;
            c = 0;
            check = wordVal;
            strcpy(temp_word,word);
            i++;
            continue;
        }

        p++;
        if(temp_word[p]=='\0'){
            p = 0;
            i++;
        }
    }
    res[status-1] ='\0';
    printf("%s",res);
}