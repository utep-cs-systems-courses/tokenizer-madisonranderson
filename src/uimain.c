#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  char id[10];
  char inputOption[100];
  char inputString[100];
  List *list = init_history();
  while(1){
    
    printf("\nPlease make a selection:\n1 to tokenize,  \n2 To select a String by ID \n3 To view history, \n4 to Quit\n");
    fgets(inputOption,10,stdin);
    char *input =  inputOption;
    if(*input == '1'){
      printf("Enter a sentence to tokenize: ");
      fgets(inputString, 100, stdin);
      char **result = tokenize(inputString);
      print_tokens(result);
      free_tokens(result);
      add_history(list, inputString);
    } else if(*input == '3'){
      print_history(list);
    } else if(*input == '2'){
      printf("Enter an ID: ");
      fgets(id, 10,stdin);
      int tokenId = atoi(id);
      char *token = get_history(list, tokenId);
      if (token != 0){
	char **tokenized = tokenize(get_history(list,tokenId));
        print_tokens(tokenized);
        free_tokens(tokenized);
      }
    }
    else if(*input == '4'){
      goto done;
    }
  }
 done:
   return 0;
}
