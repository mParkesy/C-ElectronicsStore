#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SalesStruct.h"
#include "Date.h"

// creates a new sale instance by allocating memory
Sale *sale_new(Date *date, char code[], int quantity)
{
    Sale *sale= (Sale*)malloc(sizeof(Sale));
    if(sale == NULL)
    {
        fprintf(stderr, "Error: Unable to allocate "
              "memory in sale_new()\n");
        exit(EXIT_FAILURE);    
    }
        
    sale->date = date;
    strcpy(sale->code, code);
    sale->quantity = quantity;
    
    return sale;
}

// frees up allocated memory for given sale
void sale_free(Sale *sale)
{
    free(sale);
}

// prints a given sale in a list format
void sale_print(Sale *sale){
    date_print(sale_getDate(sale));
    printf(",%s,%d\n", sale_getCode(sale), sale_getQuantity(sale));
}
