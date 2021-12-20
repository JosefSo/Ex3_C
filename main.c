#include <stdio.h>
#include "my_func.h"
// #include <conio.h>
#include <stdlib.h>
#include <string.h>


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

int main(){

    
    //allocate the requested memory
  char *text = (char *) malloc(sizeof(char) * TXT);
  char *word = (char *) malloc(sizeof(char) * WORD);
  
  // if memory cannot be allocated
  if(text == NULL) {
    printf("Error! memory for text not allocated.");
    exit(0);
  }

  // if memory cannot be allocated
  if(word == NULL) {
    printf("Error! memory for word not allocated.");
    exit(0);
  }


  //call the function that inputs text
  input_text(text, word);

  int word_size = strlen(word);

    // gimatria
    printf("Gematria Sequences: ");
    all_equal_gematrias(text + word_size, word);
    printf("\n");
    
    //atbash
    printf("Atbash Sequences: ");   
    Atbash(text + word_size, word);
    // // printf("%s", result);

    // Anagram
    printf("Anagram Sequences: ");
    Anagram(word,text + word_size);
//     // printf("\n");

// free the memory
  free(text);
  free(word);
  getchar();
}



