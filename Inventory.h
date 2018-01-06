/**************************************************************
Description : Implements an abstract data type representing a 
              collection of StockItem structs. Includes
			  interface functions as well as functions to be
			  used by the main.
**************************************************************/
#include "StockItem.h"
#ifndef  INVENTORY_H
#define INVENTORY_H

typedef struct NodeStruct
{
    StockItem *item;
    struct NodeStruct *next;
}
Node;

typedef struct InventoryListStruct
{
    Node *first;
    Node *last;
}
InventoryList;

/*****************************************************************************
Procedure   : inventoryList_new
Parameters  : none
Returns     : InventoryList *inventoryList - pointer to newly created Inventory List
Description : Allocate memory for a new linked list of Stock Items and
              initialise it.
 *****************************************************************************/
InventoryList *inventoryList_new();

/*****************************************************************************
Procedure   : inventoryList_add
Parameters  : InventoryList *inventoryList - pointer to Inventory List which
			  the item will be added to
              StockItem *item - pointer to a StockItem to be added to the list
Returns     : none
Description : Inserts an item to the end of the list.
 *****************************************************************************/
void inventoryList_add(InventoryList *inventoryList, StockItem *item);

/*****************************************************************************
Procedure   : inventoryList_insert
Parameters  : InventoryList *inventoryList - pointer to Inventory List which
			  the item will be added to
              StockItem *item - pointer to the StockItem to be added to the list
Returns     : none 
Description : Inserts an item to the start of the list
 *****************************************************************************/
void inventoryList_insert(InventoryList *inventoryList, StockItem *item);

/*****************************************************************************
Procedure   : inventoryList_length
Parameters  : InventoryList *inventoryList - pointer to a Inventory List  
Returns     : int - number of items in inventory list.
Description : Determines the number of items stored in the inventory list.
 *****************************************************************************/
int inventoryList_length(InventoryList *inventoryList);

/*****************************************************************************
Procedure   : inventoryList_clear
Parameters  : InventoryList *inventoryList - pointer to a Inventory List  
Returns     : none
Description : Clears the inventory list.
 *****************************************************************************/
void inventoryList_clear(InventoryList *inventoryList);

/*****************************************************************************
Procedure   : inventoryList_print
Parameters  : InventoryList *inventoryList - pointer to a Inventory List  
Returns     : none
Description : Prints all items in the list.
 *****************************************************************************/
void inventoryList_print(InventoryList *inventoryList);

/*****************************************************************************
Procedure   : removeWhitespace
Parameters  : char *readin - a pointer to a string which will have its white
              spaces removed
Returns     : char - number of items in inventory list.
Description : Determines the number of items stored in the inventory list.
 *****************************************************************************/
char *removeWhitespace(char *readin);

/*****************************************************************************
Procedure   : inventoryList_addFromFile
Parameters  : InventoryList *inventoryList - pointer to a Inventory List 
              char file[] - stores the file to be opened and read from 
Returns     : none
Description : Reads in items to be put into a inventory list
 *****************************************************************************/
void inventoryList_addFromFile(InventoryList *inventoryList, char file[]);

/*****************************************************************************
Procedure   : inventoryList_sortPrice
Parameters  : InventoryList *inventoryList - pointer to a Inventory List  
Returns     : none
Description : Sorts the inventory list by price in ascending order
 *****************************************************************************/
void inventoryList_sortPrice(InventoryList *inventoryList);

/*****************************************************************************
Procedure   : inventoryList_reduceQuantity
Parameters  : InventoryList *inventoryList - pointer to a Inventory List
              char searchCode[] - the code from the sale that has been read
              int quantity - the quantity from the sale that has been read  
Returns     : int - 0 for sale failed and 1 for sale was successful
Description : Reduces the stock quantity for each item based on a sale
              that has been read
 *****************************************************************************/
int inventoryList_reduceQuantity(InventoryList *inventoryList, char searchCode[], int quantity);

/*****************************************************************************
Procedure   : inventoryList_searchAdditional
Parameters  : InventoryList *inventoryList - pointer to a Inventory List  
              char searchAdditional - the additional information that is 
              being searched
Returns     : int - the total stock for the items with the additional
              information that was searched
Description : Gets the total stock of all items with the additional information
              search term provided
 *****************************************************************************/
int inventoryList_searchAdditional(InventoryList *inventoryList, char searchAdditional[]);

/*****************************************************************************
Procedure   : inventoryList_getResistance
Parameters  : InventoryList *inventoryList - pointer to a Inventory List  
Returns     : int - the total resistance
Description : Determines the total resistance of all the resistors 
              left in stock
 *****************************************************************************/
int inventoryList_getResistance(InventoryList *inventoryList);

#endif /* INVENTORY_H */