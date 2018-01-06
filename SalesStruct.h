/*****************************************************************************
Description : Implements an abstract data type consisting of an instance of a 
              Sales struct. Contains all of the information relating to a 
              particular sale and a set of interface functions.
 *****************************************************************************/
#ifndef SALESSTRUCT_H
#define SALESSTRUCT_H
#include "Date.h"

typedef struct SalesStruct
{
    Date* date;
    char code[12];
    int quantity;
}
Sale;

/*****************************************************************************
Procedure   : sale_new
Parameters  : Date date - the date of the sale as a Date struct
              char code[] - item code
              int quantity - the quantity of the item
Returns     : Sale* - pointer to newly created Sale
Description : Allocate memory for a new Sale and initialise it.  Generates an 
              error message and the program terminates if insufficient memory 
              is available.
 *****************************************************************************/
Sale *sale_new(Date *date, char code[], int quantity);

/*****************************************************************************
Procedure   : sale_free
Parameters  : Sale *sale - pointer to a Sale
Returns     : none
Description : Frees the memory taken by a sale.
 *****************************************************************************/
void sale_free(Sale *sale);

/*****************************************************************************
Procedure   : sale_print
Parameters  : Sale *sale - pointer to a Sale
Returns     : none
Description : Prints out all details to do with a sale
 *****************************************************************************/
void sale_print(Sale *sale);

/*****************************************************************************
Procedure   : sale_getDate
Parameters  : Sale *sale - pointer to a Sale
Returns     : sale->date - the date of the sale as a Date struct
Description : Accessor function returning the date of a sale.
 *****************************************************************************/
static inline Date *sale_getDate(Sale *sale)
{
    return sale->date;
}

/*****************************************************************************
Procedure   : sale_getCode
Parameters  : Sale *sale - pointer to a Sale
Returns     : sale->code - the code for the sale
Description : Accessor function returning the code of the sale.
 *****************************************************************************/
static inline char *sale_getCode(Sale *sale){
    return sale->code;
}

/*****************************************************************************
Procedure   : sale_getQuantity
Parameters  : Sale *sale - pointer to a Sale
Returns     : sale->quantity - the quantity of a sale
Description : Accessor function returning the quantity of a sale.
 *****************************************************************************/
static inline int sale_getQuantity(Sale *sale){
    return sale->quantity;
}

#endif /* SALESSTRUCT_H */

