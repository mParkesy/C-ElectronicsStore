/**************************************************************
Description : Implements an abstract data type representing a 
              collection of Sale structs. Includes
              interface functions as well as functions to be
	      used by the main.
**************************************************************/
#include "SalesStruct.h"
#include "Inventory.h"
#ifndef SALES_H
#define SALES_H

typedef struct NodeStruct2
{
    Sale *sale;
    struct NodeStruct2 *next;
}
Node2;

typedef struct SalesListStruct
{
    Node2 *first;
    Node2 *last;
}
SalesList;

/*****************************************************************************
Procedure   : salesList_new
Parameters  : none
Returns     : SalesList *salesList - pointer to newly created Sales List
Description : Allocate memory for a new linked list of Sales and
              initialise it.
 *****************************************************************************/
SalesList *salesList_new();

/*****************************************************************************
Procedure   : salesList_add
Parameters  : SalesList *salesList - pointer to Sales List where the sale
              will be added
              Sale *sale - pointer to a Sale to be added to the list
Returns     : none
Description : Adds a sale to the end of the list.
 *****************************************************************************/
void salesList_add(SalesList *salesList, Sale *sale);

/*****************************************************************************
Procedure   : salesList_insert
Parameters  : SalesList *salesList - pointer to Sales List where the sale
              will be inserted
              Sale *sale - pointer to the Sale to be added to the list
Returns     : none 
Description : Inserts a sale to the start of the list.
 *****************************************************************************/
void salesList_insert(SalesList *salesList, Sale *sale);

/*****************************************************************************
Procedure   : salesList_length
Parameters  : SalesList *salesList - pointer to a Sales List  
Returns     : int - number of items in sales list
Description : Determines the number of sales stored in the sales list.
 *****************************************************************************/
int salesList_length(SalesList *salesList);

/*****************************************************************************
Procedure   : salesList_clear
Parameters  : SalesList *salesList - pointer to a Sales List  
Returns     : none
Description : Clears the sales list.
 *****************************************************************************/
void salesList_clear(SalesList *salesList);

/*****************************************************************************
Procedure   : salesList_print
Parameters  : SalesList *salesList - pointer to a Sales List  
Returns     : none
Description : Prints all sales in the list.
 *****************************************************************************/
void salesList_print(SalesList *salesList);

/*****************************************************************************
Procedure   : salesList_addFromFile
Parameters  : SalesList *inventoryList - pointer to a Sales List 
              char file[] - stores the file to be opened and read from 
Returns     : none
Description : Reads in sales to be put into a sales list
 *            It also attempts the transaction and outputs a message if it fails
 *****************************************************************************/
void salesList_addFromFile(SalesList *salesList, InventoryList *inventoryList, char file[], SalesList *failList);

void salesList_printToFile(SalesList *salesList, char file[]);

#endif /* SALES_H */

