#ifndef _FREAD_H_ // This was just _FILE_H_, but that interfered with Cygwin
#define _FREAD_H_
void prefetch(struct page* curr_page, int N);

void freadd(void *ptr, struct file_pages* fpgs);

#endif
