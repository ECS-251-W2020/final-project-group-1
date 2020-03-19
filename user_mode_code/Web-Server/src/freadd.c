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
bool freadd(void *ptr, struct file_pages* fpgs, int type) {
   
    struct page *curr_pg = fpgs->first_page;
    int number = fpgs->no_of_pages;
    int pg_size = fpgs->page_size;
    int N=3;
    check=replacement(type,*curr_pg,N);
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
    return check;
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
bool LRU(struct file_page* *pge, int pages)
{
    // check if the page is in the page cache
    int isin= is_in_cache(*pge);
    // if yes return the page, delete from the queue and add it again.
    // if no, add the page to the queue.
    if(isin==1){
        remove_from_cache(*pge);
        put_in_cache(*pge);
        return true;
    }
    else{
        put_in_cache(*pge);
        return false;
    }
}
bool f2Q(struct file_page* *pge, int pages)
{
    // check if the page is in the page cache
    int isin= is_in_cache(*pge);
    // if yes return the page, delete from the queue and add it again.
    if(isin==1){
        remove_from_cache(*pge);
        put_in_cache(*pge);
        return true;
    }
    else{
        int isin2= is_in_sec_cache(*pge);
        if(isin2==1)
        {
            remove_from_sec_cache(*pge);
            put_in_cache(*pge);
            return true;
        }
        else{
            put_in_sec_cache(*pge);
            return false;
        }
    }
    // if no, check if page is in the secondary cache,
            //  if exists, delete from secondary cache and add to primary cache
            //  if doesnt, add page to the secondary cache.
}

bool ARC(struct file_page* *pge, int pages)
{ int p;
    p=0;
    int c=ghost1_cache->cache_size + ghost2_cache->cache_size + sec_cache->cache_size +p_cache->cache_size ;
    c=c/2;
    struct page cur = pge;
    int isin1=is_in_cache(*pge);
    int isin2=is_in_sec_cache(*pge);
    int ising1=is_in_ghost1_cache(*pge);
    int ising2=is_in_ghost2_cache(*pge);
    if (isin1+isin2 > 0)
    {
        if(isin1==1){
            remove_from_cache(*pge);
            
        }
        else{
            remove_from_sec_cache(*pge);
        }
        put_in_cache(*cur);

        return true;
    }
    else if(ising1==1){
        
        float check_max = ghost2_cache->no_of_entries / ghost1_cache->no_of_entries;
        float check1=p+ (checkmax > 1 ? checkmax: 1);
        p= check1 > c?c:check1;
        replace(p);
        remove_from_ghost1_cache(*pge);
        put_in_sec_cache(*cur);

        return true;
    }
    
    else if(ising2==1){
         float check_max = ghost1_cache->no_of_entries / ghost2_cache->no_of_entries;
               float check1=p-  (checkmax > 1 ? checkmax: 1);
        p= check1 > 0 ? check1:0;
               replace(p);
               remove_from_ghost1_cache(*pge);
               put_in_sec_cache(*cur);

        return true;
    }
    
    else{
        if (ghost1_cache->no_of_entries +p_cache->no_of_entries== c){
            if(p_cache->no_of_entries < c){ removelast_from_ghost1_cache();
                replace(p);}
            else{
                removelast_from_cache();
            }
        }
        else if ( (ghost1_cache->no_of_entries +p_cache->no_of_entries <c) && (ghost1_cache->no_of_entries + ghost2_cache->no_of_entries + sec_cache->no_of_entries +p_cache->no_of_entries ) >=c){
            if(ghost1_cache->no_of_entries + ghost2_cache->no_of_entries + sec_cache->no_of_entries +p_cache->no_of_entries ==2c) {removelast_from_ghost2_cache();
                replace(p);
            }
        }
        return false;
    }
    
}
void replace(float p)
{
    if ( p_cache->no_of_entries >=1) && ( ( p_cache->no_of_entries >= p )   ) {
        struct page *pge=getlast_from_cache();
        removelast_from_cache();
        put_in_ghost1_cache(pge);
        
    }
    else{
        struct page *pge=getlast_from_sec_cache();
        removelast_from_sec_cache();
        put_in_ghost2_cache(pge);
    }
}
void replacement(int which, struct file_page* *pge, int pages)
{
    if(which==1)
    {
        //call LRU
        return LRU(pge,pages);
    }
    if(which==2)
    {
        //call 2Q
        return f2Q(pge,pages);
    }
    if(which==3)
       {
           //call 2Q
           return ARC(pge,pages);
       }
    
}


