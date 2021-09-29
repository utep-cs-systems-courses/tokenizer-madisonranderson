#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c)
{
  if(c == ' ' || c == '\t')
    {
      return 1;
    }
  return 0;
}

int non_space_char(char c)
{
  if(c != ' ' || c != '\t')
    {
      return 1;
    }
  return 0;
}

char *word_start(char *s)
{
   int pointer = 0;
   if(space_char(s[pointer]))
   {
     s++;
   }
   while(space_char(s[pointer]))
   {
     pointer++;
   }
   return (s++);
}

char *word_terminator(char *word)
{
  char *c = word;
  while(non_space_char(*c) && *c != '\0')
  {
    c++;
  }
  return c;
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
  char *newStr = (char *)malloc(sizeof(char)*len+1);
  int i;
  for(i = 0; i < len; i++)
    {
      newStr[i] = inStr[i];
    }
  newStr[i] = '\0';
  return newStr;
}  

char **tokenize(char* str)
{
  int numberOfWords = count_words(str);
  char **tokens = malloc((numberOfWords+1)*(sizeof(char*)));

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
  int i = 0;
  while(tokens[i])
  {
    printf("\ntokens[%i] = '%s'", i,tokens[i]);
    i++;
  }
  printf("\ntoken[%i] = '[%s]'", i, tokens[i]);
  printf("\n");
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
