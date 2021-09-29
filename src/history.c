#include "history.h"
#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>

char* copyStr(char* dest, char* src)
{
  int i;
  for(i = 0; src[i] != '\0'; i++)
  {
    dest[i] = src[i];
  }
  dest[i] = '\0';
}

int numChar(char *str)
{
  int i = 0;
  int count = 0;
  while(str[i] != '\0')
  {
    count++;
    i++;
  }
  return count;
}

List* init_history()
{
  List* history = malloc(sizeof(List));
  return history;
}

void add_history(List *list, char *str)
{
  if(!list->root)
  {
    Item *node = (Item *)malloc(sizeof(Item));
    (*node).id = 0;
    char *newStr = copy_str(str, find_length(str));
    (*node).str = newStr;
    list->root = node;
  }
  else
  {
    int current_id = 1;
    Item *temp = list->root;
    while(temp->next)
    {
      current_id++;
      temp = temp->next;
    }
    Item *node = malloc(sizeof(Item));
    (*node).id = current_id;
    char *newStr = copy_str(str, find_length(str));
    (*node).str = newStr;
    (*node).next = 0;
    temp->next = node;
  }
}

char *get_history(List *list, int id)
{
  Item* current = list->root;
  if(id == 0)
  {
    return list->root->str;
  }
  else
  {
    while(current)
    {
      if(current->id == id)
      {
	char *newStr = current->str;
	return newStr;
      }
      current = current->next;
    }
  }
  return 0;
}

void print_history(List *list)
{
  Item *current = list->root;
  while(current)
  {
    printf("n%i: %s\n", current->id, current->str);
    current = current->next;
  }
}

void free_history(List *list)
{
  Item *current = list->root;
  while(current)  
  {
    free(current);
    current = current->next;
  }
  free(list);
}

int find_length(char *str)
{
  int length = 0;
  while(*str)
    {
      length++;
      str++;
    }
  return length;
}
