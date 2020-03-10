#include <stdio.h>
#include<stdlib.h>
#define pg_size 20

struct page {
  char *content;
  struct page *next_page;
}p;

struct file_pages {
  struct page *first_page;
  int no_of_pages;
}fp;

struct file_pages* setup(char *filename) {
  struct file_pages *wb_pgs = NULL;
  FILE *fip;
  fip = fopen(filename,"r");
  char pg_content[26];
  fread(pg_content,1,25,fip);
  //fseek(fp,0,SEEK_CUR);
  //printf("%s\n",pg_content);
  struct page* first_page = (struct page*) malloc(sizeof(struct page));
  struct file_pages* pages_in_disk = (struct file_pages*) malloc(sizeof(struct file_pages));
  first_page->content = pg_content;
  first_page->next_page = NULL;
  struct page* curr_page = first_page;
  int no_of_pages = 0;
  while(feof(fip)==0) {
    fread(pg_content,1,25,fip);
    struct page *new_page = (struct page*) malloc(sizeof(struct page));
    //printf("%s\n",pg_content);
    new_page->content = pg_content;
    new_page->next_page = NULL;
    curr_page->next_page = new_page;
    curr_page = curr_page->next_page;
    no_of_pages++;
    //fseek(fp,20,SEEK_CUR);
  }
  pages_in_disk->first_page = first_page;
  pages_in_disk->no_of_pages = no_of_pages;
  printf("Setup done\n");
  fclose(fip);
  return pages_in_disk;
}
