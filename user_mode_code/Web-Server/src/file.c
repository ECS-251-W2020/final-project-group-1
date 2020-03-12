#include <stdlib.h>
#include "setup.h"
#include "file.h"
/**
 * Loads a file into memory and returns a pointer to the data.
 *
 * Buffer is not NUL-terminated.
 */
struct file_data *file_load(struct file_pages *fpgs)
{
    //char *buffer, *p;

    // Allocate that many bytes
    int total_pages = fpgs->no_of_pages;
    int page_size = fpgs->page_size;
    //FILE *fp = fpgs->fp;
    //p = buffer = malloc(total_pages*page_size);
    char p[total_pages*page_size];

    if (p == NULL) {
        return NULL;
    }
    //printf("%d\n",total_pages*page_size);
    // Read in the entire file
    freadd(p,fpgs);

    // Allocate the file data struct
    struct file_data *filedata = malloc(sizeof *filedata);

    if (filedata == NULL) {
        free(p);
        return NULL;
    }

    filedata->data = p;
    filedata->size = total_pages*page_size;

    return filedata;
}

/**
 * Frees memory allocated by file_load().
 */
void file_free(struct file_data *filedata)
{
    free(filedata->data);
    free(filedata);
}
