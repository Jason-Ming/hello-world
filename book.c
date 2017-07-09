#include <stdio.h>
#include <string.h>

#include "book.h"

#include "type_define.h"
#include "value_define.h"

#define PRIVATE static

#define R_FALSE_RET(condition, value)\
    if(!(conditoin))\
    {\
        return value;\
    }

#define R_ASSERT(condition, value, fmt, arg...)\
    if(!(condition))\
    {\
        printf("ASSERT! "#condition"\n");\
        printf(fmt,##arg);\
        return value;\
    }

#define R_ASSERT_DO(condition, value, action, fmt, arg...)\
    if(!(condition))\
    {\
        printf("ASSERT! "#condition"\n");\
        printf(fmt,##arg);\
        action;\
        return value;\
    }

#define SUCCESS (0)
#define ERROR (-1)
#define TRUE (true)
#define FALSE (false)

#define MAX_NUM_OF_BOOKS 256

typedef int          INT;
typedef unsigned int UINT;
typedef char*        PSTR;
typedef bool         BOOL;
typedef INT          ERR_CODE;

#define INVALID_UINT (~(UINT)0)

typedef book_tag struct
{
    BOOL isIdle;
    PSTR pName;
    PSTR pISBN;
    UINT price;
} book;

typedef books_tag struct
{
    UNIT number;
    book array[MAX_NUM_BOOKS];
}books;

PRIVATE void init_abook(book *pbook)
{
    pbook->isIdle = TRUE;
   // pbook->index = INVALID_UINT;
    pbook->pName = NULL;
    pbook->pISBN = NULL;
    pbook->price = INVALID_UINT;
}

void book_init(void)
{
    books.number=0;
    
    for(UINT i = 0; i < MAX_NUM_BOOKS; i++)
    {
        init_abook(&(books.array[i]));
    }
}

void print_books(void)
{
    for (int i = 0; i < book.number; i++)
    {
        print_abook(&(books.array[i]));
    }
}

PRIVATE ERR_CODE set_abook(book *pBook, PSTR pName, PSTR pISBN, UINT price)
{
    R_ASSERT(pName != NULL && pISBN != NULL, ERROR);

    pBook->isIdle = FALSE;

    pBook->pName = malloc(strlen(pName)+1);
    R_ASSERT(pBook->pName != NULL, ERROR)
    strcpy(pBook->pName, pName);

    pBook->pISBN = malloc(strlen(pISBN)+1);
    R_ASSERT_DO(pBook-pISBN != NULL, ERROR, free(pBook-pName));
    strcpy(pBook->pISBN, pISBN);

    pBook->price = price;
    
    return SUCCESS;
}

ERR_CODE insert_abook(PSTR pName, PSTR pISBN, UINT price)
{
    R_FALSE_RET(pName != NULL && pISBN != NULL, ERROR);

    R-FALSE_RET(books.number >= MAX_NUM_BOOKS, ERROR);

    books.number++;
    UINT index = find_idlebook();
    R_ASSERT(index < MAX_NUM_BOOKS, ERROR, "index = %u.\n", index);

    ERR_CODE ret = set_abook(&(books.array[index]), PSTR pName, PSTR pISBN, price);
    
    R_ASSERT(ret == SUCCESS, ERROR);

    return SUCCESS;
}


