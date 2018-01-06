/*****************************************************************************
Description : Implements an abstract data type consisting of an instance of a 
              item struct. Contains all the details to do with an item along
              with a set of interface functions.
 *****************************************************************************/

#ifndef STOCKITEM_H
#define STOCKITEM_H

typedef struct ItemStruct
{
    char comType[12];
    char code[12];
    int stock;
    int price;
    char additional[10];
}
StockItem;


/*****************************************************************************
Procedure   : item_new
Parameters  : char comType[] - Type of item
              char code[] - Code of item
              int stock - Stock for the item
              int price - Price of the item
              char additional - Any additional information for the item
Returns     : StockItem* - pointer to newly created item
Description : Allocate memory for a new Item and initialise it.  Generates an 
              error message and the program terminates if insufficient memory 
              is available.
 *****************************************************************************/
StockItem *item_new(char comType[],char code[], int stock, int price, char additional[]);

/*****************************************************************************
Procedure   : item_free
Parameters  : StockItem *item - pointer to an item
Returns     : none
Description : Frees the memory taken by an item.
 *****************************************************************************/
void item_free(StockItem *item);

/*****************************************************************************
Procedure   : item_print
Parameters  : StockItem *item - pointer to a StockItem
Returns     : none
Description : Prints out all of an items details.
 *****************************************************************************/
void item_print(StockItem *item);

/*****************************************************************************
Procedure   : item_getComType
Parameters  : StockItem *item - pointer to a StockItem.
Returns     : item->comType - the comtype of an item.
Description : Accessor function returning the comtype for a StockItem struct.
 *****************************************************************************/
static inline char *item_getComType(StockItem *item)
{
    return item->comType;   
}

/*****************************************************************************
Procedure   : item_getCode
Parameters  : StockItem *item - pointer to a StockItem.
Returns     : item->code - the code of an item.
Description : Accessor function returning the code for a StockItem struct.
 *****************************************************************************/
static inline char *item_getCode(StockItem *item)
{
    return item->code;   
}

/*****************************************************************************
Procedure   : item_getStock
Parameters  : StockItem *item - pointer to a StockItem.
Returns     : item->stock - the stock of an item.
Description : Accessor function returning the stock for a StockItem struct.
 *****************************************************************************/
static inline int item_getStock(StockItem *item)
{
    return item->stock;   
}

/*****************************************************************************
Procedure   : item_getPrice
Parameters  : StockItem *item - pointer to a StockItem.
Returns     : item->price - the price of an item.
Description : Accessor function returning the price for a StockItem struct.
 *****************************************************************************/
static inline int item_getPrice(StockItem *item)
{
    return item->price;   
}

/*****************************************************************************
Procedure   : item_getAdditional
Parameters  : StockItem *item - pointer to a StockItem.
Returns     : item->additional - the additional information for an item.
Description : Accessor function returning the additional information for a StockItem struct.
 *****************************************************************************/
static inline char *item_getAdditional(StockItem *item)
{
    return item->additional;   
}

#endif /* STOCKITEM_H */

