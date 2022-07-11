/*******************************************************************************
 * Dynamic array (darray) implementation by Mehmet Ata Bal. The default 
 * array type is char. However, this can be changed by using the macro
 * DARRAY_TYPE. Before importing darray.h, define a macro with the desired
 * type. E.g.,
 *  #define DARRAY_TYPE int
 *  #include "darray.h"
 *  ...
 * Use cases include unknown length string reading. See darray.c
*******************************************************************************/


#include <stdlib.h> /* size_t, malloc, realloc */
#include <math.h> /* pow */

#ifndef DARRAY_TYPE
#define DARRAY_TYPE char
#endif


#ifndef DARRAY_H
#define DARRAH_H


struct darray
{
    DARRAY_TYPE * array;
    size_t size;
    size_t length;
    char pwr2;
};
typedef struct darray darray_t;

darray_t init_darray();
DARRAY_TYPE get(const darray_t darray, const int index);
DARRAY_TYPE get_head(const darray_t darray);
DARRAY_TYPE push(darray_t * darray, const DARRAY_TYPE c);
DARRAY_TYPE pop(darray_t * darray);


darray_t init_darray()
{
    darray_t darray;
    darray.size = 1;
    darray.length = 0;
    darray.pwr2 = 0;
    darray.array = (DARRAY_TYPE*)malloc(sizeof(DARRAY_TYPE));
    return darray;
}


void close_darray(darray_t * darray)
{
    free(darray->array);
}


DARRAY_TYPE get(const darray_t darray, const int index)
{
    return darray.array[index];
}


DARRAY_TYPE get_head(const darray_t darray)
{
    return darray.array[darray.length-1];
}


DARRAY_TYPE push(darray_t * darray, const DARRAY_TYPE c)
{
    if(darray->pwr2 < 0)
        return '\0';

    if(darray->length-1 >= darray->size)
    {
        size_t size = (size_t)pow((double)2, (double)darray->pwr2+1);
        darray->array = (DARRAY_TYPE*)realloc(darray->array, size*sizeof(DARRAY_TYPE));
        (darray->pwr2)++;
        darray->size = size;
    }
    darray->array[darray->length] = c;
    (darray->length)++;
    return darray->array[darray->length-1];
}


DARRAY_TYPE pop(darray_t * darray)
{
    DARRAY_TYPE c = darray->array[darray->length-1];
    darray->length--;
    return c;
}

#endif