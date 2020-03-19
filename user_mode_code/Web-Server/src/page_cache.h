#ifndef _PC_H_
#define _PC_H_
struct page_cache {
  struct p_cache_entry *first_entry;
  int cache_size;
  int no_of_entries;
};

// for 2Q, it will act as the secondary cache.
struct sec_cache {
  struct sec_cache_entry *first_entry;
  int cache_size;
  int no_of_entries;
};
struct ghost1_cache {
  struct sec_cache_entry *first_entry;
  int cache_size;
  int no_of_entries;
};
struct ghost2_cache {
  struct sec_cache_entry *first_entry;
  int cache_size;
  int no_of_entries;
};
/*  for ARC, page_cache acts as L1,
 sec_cache as L2.
ghost1_cache as B1
 ghost2_cache as B2.
*/
struct p_cache_entry {
  struct page *curr_page;
  struct p_cache_entry *next_entry;
};

struct sec_cache_entry {
  struct page *curr_page;
  struct p_cache_entry *next_entry;
};
struct ghost1_cache_entry {
  struct page *curr_page;
  struct p_cache_entry *next_entry;
};
struct ghost2_cache_entry {
  struct page *curr_page;
  struct p_cache_entry *next_entry;
};

extern struct page_cache *p_cache;
extern struct sec_cache *sec_cache;
extern struct ghost1_cache *ghost1_cache;
extern struct ghost2_cache *ghost2_cache;
int is_in_cache(struct page *pge);
int is_in_sec_cache(struct page *pge)
int is_in_ghost1_cache(struct page *pge)
int is_in_ghost2_cache(struct page *pge)

void put_in_cache(struct page *pge);
void put_in_sec_cache(struct page *pge);
void put_in_ghost1_cache(struct page *pge);
void put_in_ghost2_cache(struct page *pge);

void remove_from_cache(struct page *pge);
void remove_from_sec_cache(struct page *pge);
void remove_from_ghost1_cache(struct page *pge);
void remove_from_ghost2_cache(struct page *pge);


void getlast_from_cache(struct page *pge);
void getlast_from_sec_cache(struct page *pge);

void removelast_from_cache(struct page *pge);
void removelast_from_sec_cache(struct page *pge);
void removelast_from_ghost1_cache(struct page *pge);
void removelast_from_ghost2_cache(struct page *pge);

struct page_cache* setup_cache(struct page *pge);
struct page_cache* setup_sec_cache(struct page *pge);
struct page_cache* setup_ghost1_cache(struct page *pge);
struct page_cache* setup_ghost2_cache(struct page *pge);
#endif
