#include <stdio.h>
#include <stdlib.h>
#include "setup.h"

struct page_cache {
  struct cache_entry *first_entry;
  int cache_size;
}pc;

struct cache_entry {
  struct page *curr_page;
  struct cache_entry *next_entry;
}ce;
