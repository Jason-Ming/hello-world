#include <stdio.h>
#include "book.h"
int main()
{
    printf("Hello world!\n");

    init_books();
    printf("init_books!\n");

    ERR_CODE ret;
    ret = insert_abook("CLRS", "7-111-18777-6", 85);
    printf("insert_abook!\n");
    ret = insert_abook("APUE", "978-7-115-35211-8", 128);
    printf("insert_abook!\n");
    print_books();
    printf("print_books!\n");
    return ret;
}

