#include<stdio.h>
#include<fcntl.h>
#include<errno.h>

int fib(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        int a = fib(n-1);
        int b = fib(n-2);
        return a + b;
    }
}

//Stack status when system call
extern int errno;
int create_file() {
    // if file does not have in directory
    // then file foo.txt is created.
    // https://chromium.googlesource.com/chromiumos/docs/+/master/constants/syscalls.md
    int fd = open("foo.txt", O_RDWR | O_CREAT);

    printf("fd = %d/n", fd);

    if (fd ==-1)
    {
        // print which type of error have in a code
        printf("Error Number % d\n", errno);

        // print program detail "Success or failure"
        perror("Program");
    }
    return 0;
}

//stack status when function def in so.

int square(int n) {
    int r = n * n;
    return r;
}

int square_add(int a, int b) {
    int a2 = square(a);
    int b2 = square(b);
    create_file();
    return a2 + b2;
}


int main() {
    //int r = fib(10)
    int r = square_add(3, 4);
    printf("%d\n", r);
    return 0;
}
