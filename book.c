#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "book.h"

#include "type_define.h"
#include "value_define.h"
#include "utils_define.h"

#define MAX_NUM_OF_BOOKS 256


typedef struct book_tag
{
    BOOL isIdle;
    PSTR pName;
    PSTR pISBN;
    UINT price;
} book;

typedef struct books_tag
{
    UINT number;
    book array[MAX_NUM_OF_BOOKS];
}book_list;

book_list books;

PRIVATE void init_abook(book *pbook)
{
    pbook->isIdle = TRUE;
   // pbook->index = INVALID_UINT;
    pbook->pName = NULL;
    pbook->pISBN = NULL;
    pbook->price = INVALID_UINT;
}

void init_books(void)
{
    books.number=0;
    
    for(UINT i = 0; i < MAX_NUM_OF_BOOKS; i++)
    {
        init_abook(&(books.array[i]));
    }
}

PRIVATE void print_abook(book *pBook)
{
    printf("    name: %s, iSBN: %s, price: %u.\n", pBook->pName, pBook->pISBN, pBook->price);
}

void print_books(void)
{
    for (int i = 0; i < books.number; i++)
    {
        if (books.array[i].isIdle == TRUE)
        {
            continue;
        }

        print_abook(&(books.array[i]));
    }
}

PRIVATE UINT find_idlebook(void)
{
    for (UINT i = 0; i < MAX_NUM_OF_BOOKS; i++)
    {
        if ( books.array[i].isIdle == TRUE)
        return i;
    }

    return INVALID_UINT;
}

PRIVATE ERR_CODE set_abook(book *pBook, PSTR pName, PSTR pISBN, UINT price)
{
    R_ASSERT(pName != NULL && pISBN != NULL, ERROR);

    pBook->isIdle = FALSE;

    pBook->pName = malloc(strlen(pName)+1);
    R_ASSERT(pBook->pName != NULL, ERROR)
    strcpy(pBook->pName, pName);

    pBook->pISBN = malloc(strlen(pISBN)+1);
    R_ASSERT_DO(pBook->pISBN != NULL, ERROR, free(pBook->pName));
    strcpy(pBook->pISBN, pISBN);

    pBook->price = price;
    
    return SUCCESS;
}

ERR_CODE insert_abook(PSTR pName, PSTR pISBN, UINT price)
{
    R_FALSE_RET(pName != NULL && pISBN != NULL, ERROR);

    R_FALSE_RET(books.number < MAX_NUM_OF_BOOKS, ERROR);

    UINT index = find_idlebook();
    R_ASSERT(index < MAX_NUM_OF_BOOKS, ERROR);

    ERR_CODE ret = set_abook(&(books.array[index]), pName, pISBN, price);
    
    R_ASSERT(ret == SUCCESS, ERROR);

    books.number++;

    return SUCCESS;
}


