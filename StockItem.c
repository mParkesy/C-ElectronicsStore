/*****************************************************************************
Description : Implements an abstract data type consisting of an instance of a 
              item struct. Contains all the details to do with an item along
              with a set of interface functions.
 *****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StockItem.h"


// creates new stock item instance by allocating memory
StockItem *item_new(char comType[], char code[], int stock, int price, char additional[])
{    
   StockItem *item = (StockItem*)malloc(sizeof(StockItem));
      
   if (item == NULL)
   {
      fprintf(stderr, "Error: Unable to allocate "
              "memory in item_new()\n");
      
      exit(EXIT_FAILURE);
   }
   
   strcpy(item->comType, comType);
   strcpy(item->code, code);
   item->stock = stock;
   item->price = price;
   strcpy(item->additional, additional);
    
   return item;
}

// frees up allocated memory for given item
void item_free(StockItem *item)
{
    free(item);
}

// prints a given item
void item_print(StockItem *item)
{
    printf("%s,%s,%d,%d,%s", item->comType, item->code, 
             item->stock, item->price, item->additional);
}
