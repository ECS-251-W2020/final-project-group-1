## Code structure
---
Our source code is present in the /user_mode_code/Web-Server/src directory

/serverfiles contains the files that can be accessed by the user

The different parts of our project are separated out as follows:
* server.c, net.c, mime.c, llist.c, hashtable.c, cache.c - Web server related code
* file.c - file loading and freeing related code
* freadd.c - our implementation of fread and prefetching
* page_cache.c - page cache structure and all operations related to page cache, secondary and ghost caches (for cache replacement algorithms)
* setup.c - file pages structure and setup functions for loading files into our struct and primary cache
