#include <stdio.h>
#include <stdlib.h>
#include "setup.h"
#include <string.h>

struct file_pages* setup(char *filename) {
  FILE *fip;
  fip = fopen(filename,"r");
  char pg_content[21];
  fread(pg_content,1,21,fip);
    
  struct page *first_page = (struct page*) malloc(sizeof(struct page));
  struct file_pages* file_pages = (struct file_pages*) malloc(sizeof(struct file_pages));
  memcpy(first_page->content,pg_content,strlen(pg_content)+1);
  first_page->next_page = NULL;
  struct page* curr_page = first_page;
  int no_of_pages = 0;
  while(feof(fip)==0) {
    fread(pg_content,1,21,fip);
    struct page *new_page = (struct page*) malloc(sizeof(struct page));
  //  printf("%s\n",pg_content);
    memcpy(new_page->content,pg_content,strlen(pg_content)+1);
    new_page->next_page = NULL;
    curr_page->next_page = new_page;
    curr_page = curr_page->next_page;
    no_of_pages++;
    //fseek(fp,20,SEEK_CUR);
  }

  file_pages->first_page = first_page;
  file_pages->no_of_pages = no_of_pages;
  file_pages->page_size = 20;
  file_pages->fp = fip;

  printf("Setup done\n");
  fclose(fip);
  return file_pages;
}

struct file_pages* setup_prim() {
  struct page *first_page = (struct page*) malloc(sizeof(struct page));
  struct file_pages* file_pages = (struct file_pages*) malloc(sizeof(struct file_pages));
  memcpy(first_page->content,"",1);
  first_page->next_page = NULL;
  struct page* curr_page = first_page;
  int no_of_pages = 0;

  file_pages->first_page = first_page;
  file_pages->no_of_pages = no_of_pages;
  file_pages->page_size = 20;
  file_pages->fp = fip;

  printf("Primary setup done\n");

  return file_pages;
}
