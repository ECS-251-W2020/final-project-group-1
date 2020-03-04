#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>
typedef char* (*orig_fgets)(char* str, int num, FILE *stream);
char* fgets(char* str,int num,FILE *stream) {
  //TODO:
  orig_fgets o_fgets;
  o_fgets = (orig_fgets)dlsym(RTLD_NEXT,"fgets");
  printf("This is where we will implement prefetching and cache replacement logic");
  return o_fgets(str,num,stream);
}
