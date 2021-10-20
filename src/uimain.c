#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  char inputString[100];
  List *list = init_history();
  printf("\nPlease make a selection:\n 1 to tokenize,\n 2 to select a token by
  ID,\n 3 to view history,\n 4 to quit");
  printf("\nEnter a sentence you'd like to tokenize: ");
  scanf("%s", &inputString);
  char **result = tokenize(inputString);
  //add to history
  print_tokens(result);
  free_tokens(result);
  return 0;
}
