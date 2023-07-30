#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <math.h>
#include <string.h>

#include "llist.h"
#include "hashmap.h"

//local function for hashing an input value (do not edit)
unsigned int _hash(hashmap_t * hm, char * val){
  //based on Java's String.hashcode()
  double k = 0;
  double len = (double) strlen(val);
  int i=1;
  for(char * c = val; *c ; c++,i++){
    k += (*c) * pow(31,len-i);
  }

  return (unsigned int) (((unsigned long) k) % hm->num_buckets);
}


//local function: resize the hashmap by doubling the number of buckets and rehashing
 void _resize(hashmap_t * hm){
/* 
  hashmap_t * temp1 = hm_init(); 
  temp1->buckets = calloc(sizeof(llist_t*),hm->num_buckets);
  temp1->num_buckets = hm->num_buckets;

  for(int i = 0; i < hm->num_buckets; i++)
  {
    temp1->buckets[i] = hm->buckets[i];
  }
  
  //temp1->buckets = hm->buckets;
  

  hm->buckets = calloc(sizeof(llist_t*),hm->num_buckets*2);
  hm->num_buckets = hm->num_buckets*2;

  for(int i = 0; i < hm->num_buckets; i++)
  {
    hm->buckets[i] = ll_init();
  }

llist_t ** temp = temp1->buckets;

  for(int i = 0; i < temp1->num_buckets; i++)
  {
    

    ll_node_t * p = temp[i]->head;

    unsigned int h = _hash(temp1,p->val);

    ll_push(hm->buckets[h], p->val);

    p = p->next;

    


  }
  for(int i = 0; i < temp1->num_buckets; i++)
  {
    ll_delete(temp1->buckets[i]);
    ll_delete(temp[i]);
  }
  free(temp1); 
  free(temp);   */
 



/*   llist_t ** temp = hm->buckets;

  hm->buckets = calloc(sizeof(llist_t*), (hm->num_buckets*2));
  hm->num_buckets = (hm->num_buckets*2);

  for(int i = 0; i < hm->num_buckets; i++)
  {
    hm->buckets[i] = ll_init();
  }

  for(int i = 0; i < hm->num_buckets/2; i++)
  {
    ll_node_t * p = temp[i]->head;

    unsigned int h = _hash(hm,p->val);

    ll_push(hm->buckets[i], p->val);

    p = p-> next;
  }
  for(int i = 0; i < hm->num_buckets/2; i++)
  {
    ll_delete(temp[i]);
  }
  free(temp);    */


  int oldnum = hm->num_buckets;
  llist_t ** newhm = calloc(sizeof(llist_t*), oldnum*2);

  for(int i = 0; i < oldnum*2; i++)
  {
    newhm[i] = ll_init();
  }

  hm->num_buckets = oldnum * 2;

  for(int i = 0; i < oldnum; i++)
  {
    ll_node_t * p = hm->buckets[i]->head;

    while(p != NULL)
    {
      unsigned int h = _hash(hm,p->val);
      ll_push(newhm[h], p->val);
      p = p->next;
    }
  }

llist_t ** oldhm = hm->buckets;
hm->buckets = newhm;

for(int i = 0; i < oldnum; i++)
{
  ll_delete(oldhm[i]);
}
free(oldhm);


  
} 



//initliaze a hashmap with initial number of buckets
hashmap_t * hm_init(){

  //create the hashmap
  hashmap_t * hm = calloc(sizeof(hashmap_t),1);

  hm->buckets = calloc(sizeof(llist_t*),HM_INIT_NUM_BUCKETS);
  hm->size = 0;
  hm->num_buckets = HM_INIT_NUM_BUCKETS;

  for(int i = 0; i < hm->num_buckets; i++)
  {
    hm->buckets[i] = ll_init();
  }
  
  return hm;
}


//delete/deallocate the hashmap
void hm_delete(hashmap_t * hm){

  //TODO: properly deallocate
  for(int i = 0; i < hm->num_buckets; i++)
  {
      ll_delete(hm->buckets[i]);
      
  }

  //delete the hashmap
  free(hm->buckets);
  free(hm);
}

//add a string value to the hashmap
void hm_add(hashmap_t * hm, char * val){
  // You get this function for free :)
  
  //check the load on the hashtable, if > max load, resize!
  if(((hm->size+1)/(double) hm->num_buckets) > HM_MAX_LOAD){
    _resize(hm); 
  }

  unsigned int h = _hash(hm,val); //get hash
  ll_push(hm->buckets[h],val); //note that list does string dup
  hm->size++; //increase size


}

//see if a string value is in the hashmap
bool hm_check(hashmap_t * hm, char * val)
{

  unsigned int h = _hash(hm,val);


 // for(int i = 0; i < hm->num_buckets; i++)
 // {
    ll_node_t * p = hm->buckets[h]->head;
    while(p != NULL)
    {
      if(strcmp(p->val,val)==0)
        {
          return true; 
        }
        
      p = p->next;
    }
  //}
 

return false; 




  
}


