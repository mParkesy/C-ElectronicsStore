/**************************************************************
Description : Implements an abstract data type representing a 
              collection of Sale structs. Includes
              interface functions as well as functions to be
              used by the main.
**************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Sales.h"
#include "Date.h"

// creates new sales list by allocating memory
SalesList *salesList_new()
{
    // allocate memory
    SalesList *salesList = (SalesList*)malloc(sizeof(SalesList));
    // check allocation was successful
    if (salesList == NULL)
    {
      fprintf(stderr, "Unable to allocate memory in salesList_new()\n");
      exit(EXIT_FAILURE);        
    }
    // set first and last node to null
    salesList->first = NULL;
    salesList->last = NULL;
    // return new list
    return salesList;
}

// add a stock item to the end of the list
void salesList_add(SalesList *salesList, Sale *sale)
{
    // allocate memory to the new node
    Node2* node =(Node2*)malloc(sizeof(Node2));
    // check allocation was successful
    if (node == NULL)
    {
        fprintf(stderr, "Unable to allocate memory in salesList_add()\n");
        exit(EXIT_FAILURE);        
    }
    // store sale with node
    node->sale = sale;
    // set next node to null
    node->next = NULL;
    // check if last node of list is null
    if (salesList->last == NULL)
    {
        // if null, then store node in first/last node of list
        salesList->first = salesList->last = node;
    } else {
        // store node in last node of list
        salesList->last = salesList->last->next = node;
    } 
}

// insert a sale at start of list
void salesList_insert(SalesList *salesList, Sale *sale)
{
    // allocate memory to new node
    Node2* node =(Node2*)malloc(sizeof(Node2));
    // check allocation was successful
    if (node == NULL)
    {
        fprintf(stderr, "Error: Unable to allocate memory in salesList_add()\n");
        exit(EXIT_FAILURE);          
    }
    // store sale in new node
    node->sale = sale;
    // set next node to first node of list
    node->next = salesList->first;
    // if first node of list is null
    if(salesList->first == NULL)
    {
        // store new node in first/last node of list
        salesList->first = salesList->last = node;
    } else {
        // store new node at start of list
        salesList->first = node;
    }
}

// get length of list
int SalesList_length(SalesList *salesList)
{
    int length = 0;
    // loop over all nodes and count
    for (Node2* node = salesList->first; node != NULL; node = node->next)
    {
        // increment length
        length++;
    }
    return length;
}

// clear list from memory
void salesList_clear(SalesList *salesList)
{
    // loop until first node of list is empty
    while (salesList->first != NULL)
    {
        // store first node
        Node2* node = salesList->first;
        // store first node of list as next node
        salesList->first = node->next;
        // clear memory for node
        free(node);
    }
    // set last node to null
    salesList->last = NULL;
}

// print all sale items from list
void salesList_print(SalesList *salesList)
{
    // loop through every node until null
    for(Node2 *node = salesList->first; node != NULL; node = node->next){
        // print sale
        sale_print(node->sale);
    }  
}

// add sale to sales list
void salesList_addFromFile(SalesList *salesList, InventoryList *inventoryList, char file[], SalesList *failList)
{
    // open file
    FILE *readin = fopen(file, "r");
    // check file opened
    if( readin == NULL) {
        printf("Unable to open %s.\n", file);
        exit(EXIT_FAILURE);
    }
    // create new sale
    Sale *complete;
    Sale *fail;
    // store each line
    char line[255];
    // loop through file line by line
    while(fgets(line, sizeof(line), readin) != NULL){
        // store each part of line seperated by comma and remove whitespace
        char* tempDate = removeWhitespace(strtok(line, ","));
        char* tempCode = removeWhitespace(strtok(NULL, ","));
        char* tempQuantity = removeWhitespace(strtok(NULL, ","));
        // covert quantity into an int
        int quantity = atoi(tempQuantity);
        // seperate date string by / and convert to int
        int tempDay = atoi(strtok(tempDate, "/"));
        int tempMonth = atoi(strtok(NULL, "/"));
        int tempYear = atoi(strtok(NULL, "/"));
        // create new date
        Date *newDate;
        // make instance of date with temp ints
        newDate = date_new(tempDay, tempMonth, tempYear);
        int saleComplete;
        // reduce quantity of item based on sale
        saleComplete = inventoryList_reduceQuantity(inventoryList, tempCode, quantity);
        // if sale failed then output message
        if (saleComplete == 0){
            fail = sale_new(newDate, tempCode, quantity);
            salesList_add(failList, fail);
        } else {
            // if sale was successful then make new sale instance
            complete = sale_new(newDate, tempCode, quantity);
            // add sale to list
            salesList_add(salesList, complete);
        }
    }    
}

void salesList_printToFile(SalesList *salesList, char file[])
{
    FILE *f = fopen(file, "w");
    if (f == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    
    for(Node2 *node = salesList->first; node != NULL; node = node->next){
        int day = node->sale->date->day;
        int month = node->sale->date->month;
        int year = node->sale->date->year;
        char *code = node->sale->code;
        int quantity = node->sale->quantity;
        
        fprintf(f,"%d/%d/%d,%s,%d\n", day, month, year, code, quantity);
    }  
    
}