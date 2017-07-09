#ifndef __BOOK_H__
#define __BOOK_H__

#include "type_define.h"
#include "value_define.h"

ERR_CODE init_books(void);
void print_books(void);
ERR_CODE insert_abook(PSTR pName, PSTR pISBN, UINT price);

#endif

