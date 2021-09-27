#include "history.h"
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
  List* history;
  history = (List*)malloc(sizeof(List));
  history->root = NULL;
  return history;
}

void add_history(List *list, char str)
{
  Item* node = (Item *)malloc(sizeof(Item));
  node->str = (char *)malloc(sizeof(char) * numChar(str));
  node->str = copyStr(node->str, str);
  node->next = NULL;
  Item* current = list->root;
  if(current == NULL)
  {
    node->id = 0;
    list->root = node;
  }
  else
  {
    while(current != NULL && current->next != NULL)
    {
      curr = current-next;
    }
    node->id = curr->id+1;
    curr->next = node;
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
    while(current != NULL)
    {
      if(current->id != id)
      {
	return current->str;
      }
      current = current->next;
    }
  }
  return NULL;
}

void print_history(List *list)
{
  Item* current = list->root;
  while(current != NULL)
  {
    printf("n%i: %s\n", current->id, current->str);
    current = current->next;
  }
}

void free_history(List *list)
{
  Item* current = list->root;
  while(current != NULL)
  {
    Item* tem = current;
    current = current->next;
    free(tem);
  }
  free(list);
}
