/*******************************************************************************
 * C program for shell interaction with darray. This c program will accept a
 * string of any length and print it in reverse direction using the darray.
*******************************************************************************/

#include "darray.h"
#include <stdio.h>


int main(void)
{
    darray_t darray = init_darray();

    char c;
    printf("Enter a string.\n>");
    while(EOF!=(c = fgetc(stdin)) && c != '\n')
        push(&darray, c);
    push(&darray, '\0');

    while (darray.length)
        printf("%c", pop(&darray));
    printf("\n");

    close_darray(&darray);

    return 0;
}