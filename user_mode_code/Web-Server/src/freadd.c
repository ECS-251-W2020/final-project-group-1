#include "setup.h"
#include "page_cache.h"
#include <string.h>

void prefetch(struct page* curr_page, int N) {
  //printf("in pftch\n");
  if(N==3) {
    put_in_cache(curr_page);
  }
  curr_page = curr_page->next_page;
  for(int i=1;i<=N;i++) {
    if(curr_page!=NULL){
      put_in_cache(curr_page);
      //printf("in pft if\n");
      curr_page = curr_page->next_page;
    }
    else
      break;
  }
}
void freadd(void *ptr, struct file_pages* fpgs) {
    struct page *curr_pg = fpgs->first_page;
    int number = fpgs->no_of_pages;
    int pg_size = fpgs->page_size;
    int N=3;
    replacement(1,*curr_pg,N)
    //replacement(2,*curr_pg,N)
    //replacement(3,*curr_pg,N)
    //replacement(4,*curr_pg,N)
    memcpy(ptr,curr_pg->content,pg_size+1);
    //printf("post mcp\n");
    ptr+=pg_size+1;
    //printf("upar problem %d\n",N);
    prefetch(curr_pg,N);
    number-=1;
    curr_pg = curr_pg->next_page;
    
}
/**
void freadd(void *ptr, struct file_pages* fpgs) {
  printf("in fread\n");
  struct page *curr_pg = fpgs->first_page;
  int number = fpgs->no_of_pages;
  int pg_size = fpgs->page_size;
  int N=3;
  int flag;
  while(number>0) {
    flag = is_in_cache(curr_pg);
    if(flag) {
      if(2*N < 32)
        N=2*N;
      else
        N=32;
    } else {
      put_in_cache(curr_pg);
      N = 3;
    }
    memcpy(ptr,curr_pg->content,pg_size+1);
    //printf("post mcp\n");
    ptr+=pg_size+1;
    //printf("upar problem %d\n",N);
    prefetch(curr_pg,N);
    number-=1;
    curr_pg = curr_pg->next_page;
  }
}
*/
void LRU(struct file_page* *pge, int pages)
{
    // check if the page is in the page cache
    int isin= is_in_cache(*pge);
    // if yes return the page, delete from the queue and add it again.
    // if no, add the page to the queue.
    if(isin==1){
        remove_from_cache(*pge);
        put_in_cache(*pge);
    }
    else{
        put_in_cache(*pge);
    }
}

void f2Q(struct file_page* *pge, int pages)
{
    // check if the page is in the page cache
    int isin= is_in_cache(*pge);
    // if yes return the page, delete from the queue and add it again.
    if(isin==1){
        remove_from_cache(*pge);
        put_in_cache(*pge);
    }
    else{
        int isin2= is_in_sec_cache(*pge);
        if(isin2==1)
        {
            remove_from_sec_cache(*pge);
            put_in_cache(*pge);
        }
        else{
            put_in_sec_cache(*pge);
        }
    }
    // if no, check if page is in the secondary cache,
            //  if exists, delete from secondary cache and add to primary cache
            //  if doesnt, add page to the secondary cache.
}

void ARC(struct file_page* *pge, int pages)
{
    
}

void replacement(int which, struct file_page* *pge, int pages)
{
    if(which==1)
    {
        //call LRU
        LRU(pge,pages);
    }
    if(which==2)
    {
        //call 2Q
        f2Q(pge,pages);
    }
    
    
}


