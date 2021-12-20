#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include <string.h>
#include "my_func.h"

#define WORD 30

//all declarations of the functions in the program 
int g_value(char* word);
void print(char *text, int i, int j);
void findSubarrays(char *text, int size, int g);
int size_text(char *text);
void atbash(char *word);
void reverse(char *str1);
void allOccurrence(char* str, char* word1,char* word2);




void input_text(char *text, char *word){

    int i = 0;
    int j = 0;
    int flag = 1;

  while (1) {
    scanf("%c", &text[i]);
    if (text[i] == '~') {
      break;
    }
    if (text[i] == ' ' || text[i] == '\n' || text[i] == '\t'){
        flag = 0;
    }
    if (flag){
        word[j] = text[i];
        j++;
    }
    if (text[i] != '~') {
      i++;
    }
  }

  //add \0 to arrays of chars in order to print them in main()
  text[i] = '\0';
  word[j] = '\0';

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
void print(char *text, int i, int j)
{
    for (int k = i; k <= j; k++) {
        printf("%c",text[k]);
    }
    printf("~");
}
 
// Function to find subarrays with the given curr_gematria in an array
void findSubarrays(char *text, int size, int word_gematria)
{
    printf("\nGematria Sequences: ");
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
                print(text, i, j);
            }
        }
    }
}

void all_atbash(char *text, char *word){

    char word_atbash[strlen(word)];
    int count = 0;

    //copy word to word_atbash (deep copy) we can use strcpy instead
    while (word[count] != '\0') {
      word_atbash[count] = word[count];
      count++;
    } 
    //change the word_atbash to atbash
    atbash(word_atbash);

    //check myself if atbash works correctly
    printf("\n");
    printf("%s\n", word_atbash);

    char reverse_atbash[strlen(word)+1];
    count = 0;

    //copy word to reverse_atbash (deep copy) we can use just strcpy
    while (word[count] != '\0') {
      reverse_atbash[count] = word_atbash[count];
      count++;
    } 

    //reverse reverse_atbash
    reverse(reverse_atbash);

    //check myself if reverse works correctly
    printf("%s\n", reverse_atbash);

    //size_text() - returns the size of the text (we can use strlen() instead)
    int size = size_text(text);

    //start algorithm for finding all atbash in text
    printf("\nAtbash in the text : \n");
    allOccurrence(text, word_atbash, reverse_atbash);
    for (int i = 0; i < size; i++)
    {
        int flag1 = 1;
        int flag2 = 1;
        int c1_index = 0;
        int c2_index = 0;
        // char c1 = word_atbash[c1_index];
        // char c2 = reverse_atbash[c2_index];
        
 
        // consider all subarrays starting from `i` and ending at `j`
        for (int j = i; flag1 == 1; j++)
        {
            
            //looking for atbash word
            if(word_atbash[c1_index] == text[j]){
                c1_index++;
            }
            else if(text[j] == ' '){
                continue;
            }
            else if(word_atbash[c1_index] != text[j]){
                flag1 = 0;
            }

            //looking for reverse atbash word
            if(reverse_atbash[c2_index] == text[j]){
                c2_index++;
            }
            else if(text[j] == ' '){
                continue;
            }
            else if(reverse_atbash[c2_index] != text[j]){
                flag1 = 0;
            }
            
            //get to end of atbash word
            if ((c1_index)-1 == strlen(word_atbash)) {
                print(text, i, j);
                printf("\n");
            }

            //get to end of reverse atbash word
            if (c2_index == strlen(reverse_atbash)) {
                print(text, i, j);
                printf("\n");
            }
        }
    }

}

void allOccurrence(char* str, char* word1, char* word2){

    int i, j,index, found;
    int strLen, wordLen;
    strLen  = strlen(str);  // Find length of string
    wordLen = strlen(word1); // Find length of word1 and

    for(i=0; i<strLen; i++)
    {
        index = 0;
        // Match word at current position
        found = 1;

        for(j=0; j<wordLen; j++)
        {
            
            // printf("str[i + j]: ");
            // printf("%c",str[i + j]);
            // printf("=?=");

            // printf("word1[j]: ");
            // printf("%c",word1[j]);
            // printf("  ");

            // If word is not matched
            if(str[i + j] == word1[j] || str[i + j] == word2[j])
            {
                j++;
                continue;
            }
        }



        // If word have been found then print found message
        if(found == 1)
        {
            // printf("'%s' found at index: %d %d \n", word1, i, i+wordLen+index);
            if (str[(i+wordLen+index)] != word1[wordLen])
                print(str, i, (i+wordLen+index)-1);
            else
                print(str, i, (i+wordLen+index));
        }
    
        index = 0;
        // Match word at current position
        found = 1;
        
        for(j=0; j<wordLen; j++)
        {
            // If word is not matched
            if(str[i + j] != word2[j])
            {
                if(str[i + j] == ' ')
                {
                    while(str[i + j + index] == ' ')
                    {
                        index++;
                    }
                    if (str[i + j + index] != word2[j] || j == 0){
                        found = 0;
                        break;
                    }
                }
                else
                {
                    found = 0;
                    break;
                }

            }
        }

        if(found == 1)
        {
            //printf("'%s' found at index: %d %d \n", word1, i, i+wordLen+index);
            // printf("'%s' found at index: %d %d \n", word1, i, i+wordLen+index);
            if (str[(i+wordLen+index)] != word2[wordLen])
                print(str, i, (i+wordLen+index)-1);
            else
                print(str, i, (i+wordLen+index));
        }
    }
}

void atbash(char *word){

    int i;
    for(i=0;i<=strlen(word)-1;i++) {
        unsigned char c = word[i];
        if(c < 'A' || (c > 'Z' && c < 'a') || c > 'z') {
            word[i] = c;
            continue;
        }
        int flag = 0;
        if(c <= 90) {
            c = c+32;
            flag = 1;
        }
        int off = c-'a';
        word[i] = 'z'-off;
        if(flag)
            word[i] = word[i]-32;
    }
    //printf("%s\n", word);
}

void reverse(char *str1)  
{  
    // declare variable  
    int i, len, temp; 

    // use strlen() to get the length of str string   
    len = strlen(str1); 
      
    // use for loop to iterate the string   
    for (i = 0; i < len/2; i++)  
    {  
        //temp variable use to temporary hold the string  
        temp = str1[i];  
        str1[i] = str1[len - i - 1];  
        str1[len - i - 1] = temp;  
    }  
}
