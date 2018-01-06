#include <stdio.h>
#include <stdlib.h>
#include "StockItem.h"
#include "Inventory.h"
#include "Sales.h"
#include "SalesStruct.h"

int main(int argc, char** argv) { 
    // make new inventory list
    InventoryList *inventoryList = inventoryList_new();
    // add inventory from file to list
    inventoryList_addFromFile(inventoryList,"inventory.txt");
    
    // make new sales list
    SalesList *salesList = salesList_new();
    SalesList *failSalesList = salesList_new();
    /* add sales from file to list
     and run all transactions */
    salesList_addFromFile(salesList, inventoryList, "sales.txt", failSalesList);
    
    printf("Completed sales found in completedSales.txt.\n");
    printf("Failed sales found in failSales.txt.\n\n");
    
    //print all failed transactions to a seperate file
    salesList_printToFile(failSalesList, "failSales.txt");
    // print all successful transactions to a seperate file
    salesList_printToFile(salesList, "completedSales.txt");
       
    // task 1 - sort in order of increasing price
    printf("List of inventory, sorted in order of increasing price:\n");
    inventoryList_sortPrice(inventoryList);
    inventoryList_print(inventoryList);
    
    // task 3 - find how many NPN transistors are left in stock
    char *checkAdditional = "NPN";
    int stockCheck = inventoryList_searchAdditional(inventoryList, checkAdditional);
    printf("\nThere are %d NPN transistors left in stock.\n", stockCheck);
          
    // task 4 - get total resistance of all remaining resistors
    //int resistance = inventoryList_getResistance(inventoryList);
    //printf("\nThe total resistance of resistors in stock is: %d", resistance);
    return (EXIT_SUCCESS);
}

