#include <stdlib.h>
#include <string.h>

#include "llist.h"

//initialize a linked list
llist_t * ll_init()
{
  llist_t * list = malloc(sizeof(llist_t));
  list->head = NULL;
  list->size = 0;
  return list; 
}

//delete a linked list
void ll_delete(llist_t * ll){

  ll_node_t * temp;
  temp = ll->head;

  while(temp != NULL)
  {
    temp = ll->head->next;
    free(ll->head->val);
    free(ll->head);
    ll->head = temp;
  }
  free(ll);
}

//push an item onto the front of the list
void ll_push(llist_t * ll, char * s){

  ll_node_t * temp = malloc(sizeof(ll_node_t));
  temp->val = strdup(s);
 // temp->next = ll->head;
 // ll->head = temp;
  

   ll_node_t * temp1;
  temp1 = ll->head;
  
  ll->head = temp;

  temp->next = temp1; 


}




