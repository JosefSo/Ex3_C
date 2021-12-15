#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include "my_func.h"

int g_value(char* word);
void print(char *text, int i, int j);
void findSubarrays(char *text, int size, int g);

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

    printf("\nThis is all_equal_gematrias()\n");

            int i = 0;
  printf("The text is: \n");
  while (text[i] != '\0') {
    printf("%c", text[i]);
    i++;
  }


    //find gematria of the first word
    int word_g_value = g_value(word);

    //find size of the text
    int size = 0;
    while(text[size]!='\0'){
        size++;
    }
    int size_word=0;
    while(word[size]!='\0'){
        size_word++;
    }

    printf("The size is: ");
    printf("%d ", size);
    printf("\n");
    printf("The word_g_value is: ");
    printf("%d ", word_g_value);
    printf("\n");

         i = 0;
  printf("The text is: \n");
  while (text[i] != '\0') {
    printf("%c", text[i]);
    i++;
  }

    //find find subarrays of the text
    findSubarrays(text+(4), size, word_g_value);

}

int g_value(char* word){

     printf("\nThis is g_value()\n");

    int sum=0;  // variable initialization  
    int i=0;  // variable initialization  
   
    while(word[i]!='\0')  // while loop  
    {  
        if (word[i]>64 && word[i]<91){
            sum=sum+(word[i] - 64);  
        }
        if (word[i]>96 && word[i]<123){
            sum=sum+(word[i] - 96);  
        }  
        i++;  
    }  
    //printf("\nSum of the ascii value of a string is : %d", sum);  
    return sum;  
}

// Utility function to print subarray `nums[i, j]`
void print(char *text, int i, int j)
{
    for (int k = i; k <= j; k++) {
        printf("%c",text[k]);
    }
    printf("~");
}
 
// Function to find subarrays with the given sum in an array
void findSubarrays(char *text, int size, int g)
{
  printf("\nGematria Sequences: ");
    for (int i = 0; i < size; i++)
    {
        int sum = 0;
 
        // consider all subarrays starting from `i` and ending at `j`
        for (int j = i; j < size; j++)
        {
            // sum of elements so far
            
            if (text[j]>64 && text[j]<91){
                sum=sum+(text[j] - 64);  
            }
            if (text[j]>96 && text[j]<123){
                sum=sum+(text[j] - 96);  
            }  
            if (sum == g && isalpha(text[i]) && isalpha(text[j])) {
                print(text, i, j);
            }
        }
    }
}