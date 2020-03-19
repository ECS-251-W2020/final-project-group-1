#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "page_cache.h"
#include "setup.h"

int is_in_cache(struct page *pge) {
  //printf("in here\n");
  /*if(p_cache == NULL){
    return false;
  }
  else {*/
    //printf("first");
    struct p_cache_entry *c_entry = p_cache->first_entry;
    while(c_entry!=NULL) {
      if(c_entry->curr_page == pge){
        //printf("in while\n");
        return 1;
      }
      c_entry = c_entry->next_entry;
    }
  //}
  return 0;
}

void put_in_cache(struct page *pge) {
  struct p_cache_entry *c_entry = (struct p_cache_entry*) malloc(sizeof(struct p_cache_entry));
  c_entry->curr_page = pge;
  c_entry->next_entry = NULL;
  if(p_cache->no_of_entries < p_cache->cache_size) {
      struct p_cache_entry *temp = p_cache->first_entry;
      while(temp->next_entry!=NULL) {
        temp=temp->next_entry;
        //printf("in put here %s\n",pge->content);
      }
      //printf("in put2 here %s\n",pge->content);
      temp->next_entry = c_entry;
      p_cache->no_of_entries+=1;
    } else {
      //call to cache replacement algorithm
    }
}

void remove_from_cache(struct page *pge) {

}

struct page_cache* setup_cache(struct page *pge) {
  struct p_cache_entry *entr = (struct p_cache_entry*) malloc(sizeof(struct p_cache_entry));
  struct page_cache *p_c = (struct page_cache*) malloc(sizeof(struct page_cache));
  entr->curr_page = pge;
  entr->next_entry = NULL;
  p_c->first_entry = entr;
  p_c->no_of_entries = 1;
  p_c->cache_size = 20;
  return p_c;
}