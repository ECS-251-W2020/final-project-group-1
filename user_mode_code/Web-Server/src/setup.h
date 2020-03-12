#include <stdio.h>
#ifndef _SET_H_
#define _SET_H_

struct page {
  char content[20];
  struct page *next_page;
};

struct file_pages {
  struct page *first_page;
  int no_of_pages;
  int page_size;
  FILE *fp;
};

extern struct file_pages* paper1;

struct file_pages* setup(char *filename);

#endif
