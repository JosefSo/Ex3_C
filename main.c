#include <stdio.h>
// #include <conio.h>
#include <stdlib.h>
#include "my_func.h"


#define TXT 1024
#define WORD 30

//void all_equal_gematrias(char *text, char *word);

int main()
{
  //allocate the requested memory
  char *text = (char *) malloc(sizeof(char) * TXT);
  char *word = (char *) malloc(sizeof(char) * WORD);
  
  //call the function that inputs text
  input_text(text, word);


  //check if input was did correctly
  printf("\n");
  printf("MAIN: \n");
  int i = 0;
  printf("The text is: \n");
  while (text[i] != '\0') {
    printf("%c", text[i]);
    i++;
  }
  int j = 0;
  printf("\n");
  printf("The word is: \n");
  while (word[j] != '\0') {
    printf("%c", word[j]);
    j++;
  }


  i = 0;
  printf("The text is: \n");
  while (text[i] != '\0') {
    printf("%c", text[i]);
    i++;
  }
  printf("\n");
  printf("The gematries are:\n");
  //call the function that calculates all equal gimatries in the text
  all_equal_gematrias(text, word);
  
  // free the memory
  free(text);
  free(word);
  getchar();

  return 0;
}