#include <stdio.h>
#include "my_func.h"
#include <string.h>
#include <ctype.h>


int size_text(char *text){
    int size = 0;
    while(text[size]!='\0'){
        size++;
    }
    return size;
}

int g_value(char* word){

    int curr_gematria=0;  // variable initialization  
    int i=0;  // variable initialization  
   
    while(word[i]!='\0')  // while loop  
    {  
        if (word[i]>64 && word[i]<91){
            curr_gematria=curr_gematria+(word[i] - 64);  
        }
        if (word[i]>96 && word[i]<123){
            curr_gematria=curr_gematria+(word[i] - 96);  
        }  
        i++;  
    }  
    return curr_gematria;  
}

// Utility function to print subarray `nums[i, j]`
void print(char *text, int i, int j, int flag)
{
    if (flag){
        printf("~");
    }
    for (int k = i; k <= j; k++) {
        printf("%c",text[k]);
    }
}
 
// Function to find subarrays with the given curr_gematria in an array
void findSubarrays(char *text, int size, int word_gematria)
{
    int firstWord = 0;

    for (int i = 0; i < size; i++)
    {
        int curr_gematria = 0;
 
        // consider all subarrays starting from `i` and ending at `j`
        for (int j = i; j < size; j++)
        {
            // curr_gematria
            
            if (text[j]>64 && text[j]<91){
                curr_gematria=curr_gematria+(text[j] - 64);  
            }
            if (text[j]>96 && text[j]<123){
                curr_gematria=curr_gematria+(text[j] - 96);  
            }  
            if (curr_gematria == word_gematria && isalpha(text[i]) && isalpha(text[j])) {
                print(text, i, j, firstWord);
                firstWord = 1;
            }
        }
    }
}

void all_equal_gematrias(char *text, char *word){
    //find gematria of the first word
    int word_g_value = g_value(word);

    //find size of the text
    int size = size_text(text);

    //find size of the word
    int size_word = size_text(word);

    //find find subarrays of the text
    findSubarrays(text+(size_word), size, word_g_value);

}


