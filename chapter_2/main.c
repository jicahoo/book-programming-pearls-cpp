#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include <sys/mman.h>
#include <unistd.h>

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

//process memory distribution
// https://linuxhint.com/using_mmap_function_linux/
void mmap_example1(){
    int N = 1024*1024; // Number of elements for the array
    int *ptr = mmap ( NULL, N*sizeof(int),
                      PROT_READ | PROT_WRITE,
                      MAP_PRIVATE | MAP_ANONYMOUS,
                      0, 0 );
    if(ptr == MAP_FAILED){
        printf("Mapping Failed\n");
    }


    sleep(10*60);

    // Fill the elements of the array
    for(int i=0; i<N; i++){
        ptr[i] = 1;
    }

    for(int i=0; i<N; i++){
        printf("[%d] ",ptr[i]);
    }

    printf("\n");
    int err = munmap(ptr, 10*sizeof(int));

    if(err != 0) {
        printf("UnMapping Failed\n");
    }

}

void mmap_example2(){
    int N = 1024*1024; // Number of elements for the array
    int *ptr = mmap ( NULL, N*sizeof(int),
                      PROT_NONE,
                      MAP_PRIVATE | MAP_ANONYMOUS,
                      0, 0 );
    if(ptr == MAP_FAILED){
        printf("Mapping Failed\n");
    }
    //Will error if write to it?

    for(int i=0; i<N; i++){
        ptr[i] = 1;
    }

    sleep(10*60);

}


int main() {
    mmap_example2();
    return 0;
}
