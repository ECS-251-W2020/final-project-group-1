#include <sys/syscall.h>
#include <linux/kernel.h>
#include <unistd.h>
#include <stdio.h>
// This program is used to call the system call from the user space.
int main()
{
         long int outp = syscall(333); // 333 is the sys Id in the systable for the systemcall.
         printf("Output: %ld\n", outp);
         return 0;
}