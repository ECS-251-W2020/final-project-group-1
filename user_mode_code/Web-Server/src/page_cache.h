#ifndef _PC_H_
#define _PC_H_
struct page_cache {
  struct p_cache_entry *first_entry;
  int cache_size;
  int no_of_entries;
};

struct p_cache_entry {
  struct page *curr_page;
  struct p_cache_entry *next_entry;
};

extern struct page_cache *p_cache;
int is_in_cache(struct page *pge);

void put_in_cache(struct page *pge);

void remove_from_cache(struct page *pge);

struct page_cache* setup_cache(struct page *pge);

#endif
