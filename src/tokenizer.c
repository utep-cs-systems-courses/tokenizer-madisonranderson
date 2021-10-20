#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c)
{
  if((c == '\t' || c == ' ') && c != '\0'){
      return 1;
  }
  return 0;
}

int non_space_char(char c)
{
  if(c != '\t' && c != '\0' && c != ' '){
    return 1;
  }
  return 0;
}

char *word_start(char *str)
{
  while(1)
  {
    if(!space_char(*str))
    {
      return str;
    }
    if(space_char(*str))
    {
      str++;
    }
  }
}

char *word_terminator(char *word)
{
  while(1)
    {
      if(non_space_char(*word) == 0)
      {
	return word;
      }
      if(non_space_char(*word) == 1)
      {
	word++;
      }
    }
}

int count_words(char *str)
{
  int count = 0;
  while(*str)
  {
    str = word_start(str);
    if(*str == '\0')
    {
      return count;
    }
    str = word_terminator(str);
    count++;
  }
  return count;
}

char *copy_str(char *inStr, short len)
{
  char *newStr = malloc((len+1)*sizeof(char));
  int i;
  for(i = 0; i < len; i++)
    {
      newStr[i] = inStr[i];
    }
  newStr[len] = '\0';
  return newStr;
}  

char **tokenize(char* str)
{
  int numberOfWords = count_words(str);
  char **tokens = (char**) malloc((numberOfWords+1)*sizeof(char*));
  for(int i = 0; i < numberOfWords; i++)
  {
    if(str[0] == ' ')
    {
      str = word_start(str);
    }
    int length = word_terminator(str) - word_start(str);
    tokens[i] = copy_str(str, length);
    str = word_start(word_terminator(str));
  }	 
  tokens[numberOfWords] = 0;
  return tokens;
}

void print_tokens(char **tokens)
{
  int count = 1;
  while(*tokens)
  {
    printf("word[%i] = %s\n", count, *tokens);
    count++;
    tokens++;
  }
}

void free_tokens(char **tokens)
{
  char **tokensCopy = tokens;
  while(*tokens)
  {
    free(*tokens);
    tokens++;
  }
  free(tokensCopy);
}
