#include <stdio.h>
#include <malloc.h>
#include <string.h>
int main() {
    char ch;
    printf("Hit enter to allocate 1KB\n");
    ch = getchar();
    void *p1k = malloc(1024);
    printf("Copy hello1\n");
    strcpy((char*)p1k,"hello1");

    printf("Hit enter to allocate 1GB\n");
    ch = getchar();
    void *p1g = malloc(1073741824);
    printf("Copy hello2\n");
    strcpy((char*)p1g,"hello2");
    ch = getchar();

    free(p1g);
    free(p1k);
    printf("Memory deallocated\n");
    ch = getchar();
    return 0;
}