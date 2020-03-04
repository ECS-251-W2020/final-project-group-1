#include <linux/kernel.h>
#include <stdlib.h>
//asmlinkage defines to the compiler to look for parameters on the CPU stack instead of the registers.

asmlinkage long sys_hello(void)
{
// print Hello! username
// getenv from stdlib- for username.
        printf("Hello %s\n",getenv("USER") );
        return 0;
}