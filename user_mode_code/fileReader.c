#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>
#define PAGE_SIZE 20
typedef size_t (*orig_fread)(void *ptr, size_t size, size_t nmemb, FILE *stream);
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream) {
  float divi = (size*nmemb)/PAGE_SIZE;
  int t = (int)divi;
  int no_of_pages = t + (divi-t)*PAGE_SIZE;
  char* page_content[21];
  while(no_of_pages > 0) {
    
  }
}
