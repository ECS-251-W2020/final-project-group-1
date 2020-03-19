#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "page_cache.h"
#include "setup.h"

int is_in_cache(struct page *pge) {

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
void removelast_from_cache()
{
    //remove last element.
    struct p_cache_entry *c_entry = p_cache->first_entry;
    while(c_entry!=NULL) {
      if(c_entry->next_entry->next_entry == NULL){
          c_entry->next_entry=NULL;
          p_cache->no_of_entries--;
      }
    }
    put_in_cache(*pge);
}
struct page* getlast_from_cache()
{
    //remove last element.
    struct p_cache_entry *c_entry = p_cache->first_entry;
    while(c_entry!=NULL) {
      if(c_entry->next_entry == NULL){
          return *c_entry;
      }
    }
}
struct page* getlast_from_sec_cache()
{
    //remove last element.
    struct sec_cache_entry *c_entry = sec_cache->first_entry;
    while(c_entry!=NULL) {
      if(c_entry->next_entry == NULL){
          return *c_entry;
      }
    }
}
void removelast_from_sec_cache()
{
    //remove last element.
    struct sec_cache_entry *c_entry = sec_cache->first_entry;
    while(c_entry!=NULL) {
      if(c_entry->next_entry->next_entry == NULL){
          c_entry->next_entry=NULL;
          p_cache->no_of_entries--;
      }
    }
    put_in_cache(*pge);
}
void removelast_from_ghost2_cache()
{
    //remove last element.
    struct ghost2_cache_entry *c_entry = ghost2_cache->first_entry;
    while(c_entry!=NULL) {
      if(c_entry->next_entry->next_entry == NULL){
          c_entry->next_entry=NULL;
          p_cache->no_of_entries--;
      }
    }
    put_in_cache(*pge);
}
void removelast_from_ghost1_cache()
{
    //remove last element.
    struct ghost1_cache_entry *c_entry = ghost1_cache->first_entry;
    while(c_entry!=NULL) {
      if(c_entry->next_entry->next_entry == NULL){
          c_entry->next_entry=NULL;
          p_cache->no_of_entries--;
      }
    }
    put_in_cache(*pge);
}
int is_in_sec_cache(struct page *pge) {

    struct sec_cache_entry *c_entry = sec_cache->first_entry;
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
int is_in_ghost1_cache(struct page *pge) {

    struct ghost1_cache_entry *c_entry = ghost1_cache->first_entry;
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
int is_in_ghost2_cache(struct page *pge) {

    struct ghost1_cache_entry *c_entry = ghost1_cache->first_entry;
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
        removelast_from_cache();
    }
}

void put_in_sec_cache(struct page *pge) {
  struct sec_cache_entry *c_entry = (struct sec_cache_entry*) malloc(sizeof(struct sec_cache_entry));
  c_entry->curr_page = pge;
  c_entry->next_entry = NULL;
  if(sec_cache->no_of_entries < sec_cache->cache_size) {
      struct sec_cache_entry *temp = sec_cache->first_entry;
      while(temp->next_entry!=NULL) {
        temp=temp->next_entry;
        //printf("in put here %s\n",pge->content);
      }
      //printf("in put2 here %s\n",pge->content);
      temp->next_entry = c_entry;
      sec_cache->no_of_entries+=1;
    } else {
            //remove last element.
            struct sec_cache_entry *c_entry = sec_cache->first_entry;
            while(c_entry!=NULL) {
              if(c_entry->next_entry->next_entry == NULL){
                  c_entry->next_entry=NULL;
                  sec_cache->no_of_entries--;
              }
            }
            put_in_sec_cache(*pge);
        }
}

void put_in_ghost1_cache(struct page *pge) {
  struct ghost1_cache_entry *c_entry = (struct ghost1_cache_entry*) malloc(sizeof(struct ghost1_cache_entry));
  c_entry->curr_page = pge;
  c_entry->next_entry = NULL;
  if(ghost1_cache->no_of_entries < ghost1_cache->cache_size) {
      struct ghost1_cache_entry *temp = ghost1_cache->first_entry;
      while(temp->next_entry!=NULL) {
        temp=temp->next_entry;
        //printf("in put here %s\n",pge->content);
      }
      //printf("in put2 here %s\n",pge->content);
      temp->next_entry = c_entry;
      ghost1_cache->no_of_entries+=1;
    } else {
            //remove last element.
            struct ghost1_cache_entry *c_entry = ghost1_cache->first_entry;
            while(c_entry!=NULL) {
              if(c_entry->next_entry->next_entry == NULL){
                  c_entry->next_entry=NULL;
                  ghost1_cache->no_of_entries--;
              }
            }
            put_in_ghost1_cache(*pge);
        }
}

void put_in_ghost2_cache(struct page *pge) {
  struct ghost2_cache_entry *c_entry = (struct ghost2_cache_entry*) malloc(sizeof(struct ghost2_cache_entry));
  c_entry->curr_page = pge;
  c_entry->next_entry = NULL;
  if(ghost2_cache->no_of_entries < ghost2_cache->cache_size) {
      struct ghost2_cache_entry *temp = ghost2_cache->first_entry;
      while(temp->next_entry!=NULL) {
        temp=temp->next_entry;
        //printf("in put here %s\n",pge->content);
      }
      //printf("in put2 here %s\n",pge->content);
      temp->next_entry = c_entry;
      ghost2_cache->no_of_entries+=1;
    } else {
            //remove last element.
            struct ghost2_cache_entry *c_entry = ghost2_cache->first_entry;
            while(c_entry!=NULL) {
              if(c_entry->next_entry->next_entry == NULL){
                  c_entry->next_entry=NULL;
                  ghost1_cache->no_of_entries--;
              }
            }
            put_in_ghost2_cache(*pge);
        }
}

void remove_from_cache(struct page *pge) {
    
    struct p_cache_entry *c_entry = p_cache->first_entry;
      while(c_entry!=NULL) {
        if(c_entry->curr_page == pge){
            //remove the page.
            c_entry= c_entry->next_page;
        }
        c_entry = c_entry->next_entry;
      }
    //}
    return 0;

    
  }


void remove_from_ghost1_cache(struct page *pge) {
    
    struct ghost1_cache_entry *c_entry = ghost1_cache->first_entry;
      while(c_entry!=NULL) {
        if(c_entry->curr_page == pge){
            //remove the page.
            c_entry= c_entry->next_page;
        }
        c_entry = c_entry->next_entry;
      }
    //}
    return 0;
  }

void remove_from_ghost2_cache(struct page *pge) {
    
    struct ghost2_cache_entry *c_entry = ghost2_cache->first_entry;
      while(c_entry!=NULL) {
        if(c_entry->curr_page == pge){
            //remove the page.
            c_entry= c_entry->next_page;
        }
        c_entry = c_entry->next_entry;
      }
    //}
    return 0;
  }

void remove_from_sec_cache(struct page *pge) {
    struct sec_cache_entry *c_entry = sec_cache->first_entry;
      while(c_entry!=NULL) {
        if(c_entry->curr_page == pge){
            //remove the page.
            sec
        }
        c_entry = c_entry->next_entry;
      }
    //}
    return 0;
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

struct sec_cache* setup_sec_cache(struct page *pge) {
  struct sec_cache_entry *entr = (struct sec_cache_entry*) malloc(sizeof(struct sec_cache_entry));
  struct page_cache *sec_c = (struct sec_cache*) malloc(sizeof(struct sec_cache));
  entr->curr_page = pge;
  entr->next_entry = NULL;
  sec_c->first_entry = entr;
  sec_c->no_of_entries = 1;
  sec_c->cache_size = 20;
  return sec_c;
}

struct sec_cache* setup_ghost1_cache(struct page *pge) {
  struct ghost1_cache_entry *entr = (struct ghost2_cache_entry*) malloc(sizeof(struct ghost1_cache_entry));
  struct page_cache *ghost1_c = (struct ghost1_cache*) malloc(sizeof(struct ghost1_cache));
  entr->curr_page = pge;
  entr->next_entry = NULL;
  sec_c->first_entry = entr;
  sec_c->no_of_entries = 1;
  sec_c->cache_size = 20;
  return sec_c;
}
struct sec_cache* setup_ghost2_cache(struct page *pge) {
  struct ghost2_cache_entry *entr = (struct ghost2_cache_entry*) malloc(sizeof(struct ghost2_cache_entry));
  struct page_cache *ghost2_c = (struct ghost2_cache*) malloc(sizeof(struct ghost2_cache));
  entr->curr_page = pge;
  entr->next_entry = NULL;
  sec_c->first_entry = entr;
  sec_c->no_of_entries = 1;
  sec_c->cache_size = 20;
  return sec_c;
}
