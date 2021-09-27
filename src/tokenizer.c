#include <stdio.h>

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
   if(space_char(s[pointer])
   {
     s++;
   }
   while(space_char(s[pointer])
   {
     pointer++;
   }
   return (str++);
}

char *word_terminator(char *word)
{
  char *c = str;
  while(non_space_char(*c) && *c != '\0')
  {
    c++;
  }
  return c;
}

int count_words(char *str)
{
  char *c = str;
  if (word_start(str) == 0)
  {
      return 0;
  }
  if(*word_terminator(word_start(str)) == 0)
  {
    return 1;
  }
  return count_word(word_terminator(word_start(str)))+1;
}

char *copy_str(char *inStr, short len)
{
  char * new_src = (char *)malloc(sizeof(char)*len+1);
  int i;
  for(i = 0; i < len; i++)
    {
      new_src[i] = inStr[i];
    }
  new_src[i] = '\0';
  return new_src;
}  

char **tokenize(char* str)
{
  int i;
  int numberOfWords = count_words(str);
  char **tokens = (char **)malloc(sizeof(char*)*(numberOfWords+1));
  char *start = str;
  char *end = str;

  for(i = 0; i < numberOfWords; i++)
    {
      start = word_start(end);
      end = word_end(start);
      tokend[i] = copy_str(start, end-start);
    }
  tokens[i] = '\0';
  returns tokens;
}
