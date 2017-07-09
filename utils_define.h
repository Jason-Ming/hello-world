#ifndef __UTILS_DEFINE_H__
#define __UTILS_DEFINE_H__

#include <stdio.h>
#include <string.h>


#include "type_define.h"
#include "value_define.h"


#define R_FALSE_RET(condition, value)\
    if(!(condition))\
    {\
        return value;\
    }

#define R_ASSERT(condition, value)\
    if(!(condition))\
    {\
        printf("ASSERT! "#condition"\n");\
        return value;\
    }

#define R_ASSERT_DO(condition, value, action)\
    if(!(condition))\
    {\
        printf("ASSERT! "#condition"\n");\
        action;\
        return value;\
    }
/*
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
*/
#endif

