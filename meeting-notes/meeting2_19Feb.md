## Sam's comments:
       implement "something" in the kernel space.
       Have a Trello Board.

## How did the last week go?

       Jayneel: 
              started with a UI fuzzer, realised strace does the work on each individual command.
              worked on implementing a basic system call- "Hello! username", following a tutorial- Adding a Hello World System Call to Linux Kernel on a Ubuntu System.
       
       Dhruvatara: 
              wrote a shell script to run strace on gcc and call the cleaner script.
              wrote cleaner script to parse strace data to get relevant information.
       
       Anusha: 
              started implementing a system-wide file table data structure which is used for storing parsed information from strace.
       
## What's next?

      Jayneel:
              build accusim on a sys.
              understand how the manage module works in accusim.
              identify how the algorithms will run and send an input to the Manager Module about the block that needs to be added and removed.
       
      Dhruvatara: implement a cache manager module that adds and removes blocks in the cache based on the input coming from algorithm module
      
      Anusha: implement the LRU algorithm which is used in the Algorithm module.

[Trello Board](https://trello.com/b/NnINPmtG/ecs-251-group-1-board)

## Issues we're facing
       
       Dhruvatara: haven’t been able to get information about the offset of the first block being accessed via strace.
