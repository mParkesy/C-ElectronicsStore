/**************************************************************
Description : Implements an abstract data type representing a 
              collection of StockItem structs. Includes
			  interface functions as well as functions to be
			  used by the main.
**************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Inventory.h"
#include "StockItem.h"
#include "Date.h"

// create new inventory list by allocating memory
InventoryList *inventoryList_new()
{
	// allocate memory
   InventoryList *inventoryList = (InventoryList*)malloc(sizeof(InventoryList));  
   // check allocation was successful
   if (inventoryList == NULL)
   {
      fprintf(stderr, "Unable to allocate memory in inventoryList_new()\n");
      
      exit(EXIT_FAILURE);
   }
   // set first and last node to null
   inventoryList->first = NULL;
   inventoryList->last  = NULL;
   // return new list
   return inventoryList; 
}

// add a stock item to the end of the list
void inventoryList_add(InventoryList *inventoryList, StockItem *item)
{
	// allocate memory to new node
	Node* node = (Node*)malloc(sizeof(Node));
	// check allocation was successful
	if (node == NULL)
	{
		fprintf(stderr, "Unable to allocate memory in inventoryList_add()\n");
      	exit(EXIT_FAILURE);
	}
	// store item with node
	node->item = item;
	// set next node to null
	node->next  = NULL;
	// check if last node of list is null
	if (inventoryList->last == NULL)
	{
		// if null, then store node in first/last node of list
		inventoryList->first = inventoryList->last = node;
	}
	else
	{
		// store node in last node of list
		inventoryList->last = inventoryList->last->next = node;  
	}
}

// insert a stock item at start of list
void inventoryList_insert(InventoryList *inventoryList, StockItem *item)
{
	// allocate memory to new node
	Node* node = (Node*)malloc(sizeof(Node));
	// check allocation was successful
	if (node == NULL)
	{
		fprintf(stderr, "Unable to allocate memory in inventoryList_insert()\n");
		exit(EXIT_FAILURE);
	}
	// store item in new node
	node->item = item;
	// set next node to first node of list
	node->next  = inventoryList->first;

	// if first node of list is NULL
	if (inventoryList->first == NULL)
	{
		// store new node in first/last node of list
		inventoryList->first = inventoryList->last = node;
	}
	else
	{
		// store new node at start of list
		inventoryList->first = node;
	}
}

// get length of list
int inventoryList_length(InventoryList *inventoryList)
{

	int length = 0;
	// loop over all nodes and count
	for (Node* node = inventoryList->first; node != NULL; node = node->next)
	{
		// increment length
		length++;
	}
	return length;
}

// clear list from memory
void inventoryList_clear(InventoryList *inventoryList)
{
	// loop until first node of list is empty
	while (inventoryList->first != NULL)
	{
		// store first node
		Node* node = inventoryList->first;
		// store first node of list as next node
		inventoryList->first = node->next;
		// clear memory for node
		free(node);
	}
	// set last node to null
	inventoryList->last = NULL;
}

// print all stock items from list
void inventoryList_print(InventoryList *inventoryList)
{
	// loop through every node until null
	for(Node *node = inventoryList->first; node != NULL; node = node->next)
	{
		// print item
		item_print(node->item);
	}
}

/*****************************************************************************
	Adapted whitespace remover from:	
 * https://stackoverflow.com/questions/13084236/function-to-remove-spaces-from-string-char-array-in-c
 *****************************************************************************/
char *removeWhitespace(char *readin)
{
    // make copies of string
    char *out = readin;
    char *input = readin;
    // loop through string till end
    for(; *readin != '\0'; ++readin){
            // if current char is not whitespace
            if(*readin != ' ')
                    // store char in input
                    *input++ = *readin;
    }
    *input = '\0';
    return out;
}

// add stock items to inventory list
void inventoryList_addFromFile(InventoryList *inventoryList, char file[])
{
	// open file
	FILE *readin = fopen(file, "r");
    // check file opened correctly
    if (readin == NULL) {
        printf("Unable to open %s.\n", file);
        exit(EXIT_FAILURE);
    }
	// create new stock item
    StockItem *item;
    // to store each line
    char line[255];
	// loop through file line by line
    while (fgets(line, sizeof(line), readin) != NULL)
    {
		// store each part of line by a comma and remove whitespace
		char* tempComType = removeWhitespace(strtok(line, ","));
		char* tempCode = removeWhitespace(strtok(NULL, ","));
		char* tempStock = removeWhitespace(strtok(NULL, ","));
		char* tempPrice = removeWhitespace(strtok(NULL, ","));
		char* tempAdditional = strtok(NULL, ",");
		// check that the line had a additional information
		if (tempAdditional == NULL) {
			// if not provided then fill with null
			tempAdditional = "NULL\n";
		} else {
			// otherwise remove whitespace for additional information
			removeWhitespace(tempAdditional);
		}
		// convert stock and price to ints
		int stockInt = atoi(tempStock);           
		int priceInt = atoi(tempPrice);
		// create a new item using split up line of text
		item = item_new(tempComType, tempCode, stockInt, priceInt, tempAdditional);
		// add the item to the end of the list
		inventoryList_add(inventoryList, item);
    }
}

// sort the linked list based on the price of items in ascending order
void inventoryList_sortPrice(InventoryList *inventoryList)
{
	// check list contains at least two items before sorting
	if (inventoryList->first != inventoryList->last){
		int isSorted;
		// loop until sorted
		while(!isSorted){
			isSorted =1;
			// loop through every node
			for (Node *node=inventoryList->first; node->next!=NULL; node=node->next){
				// check to see if first node is greater than next and if so swap 
				if (node->item->price > node->next->item->price)
				{
					StockItem *temp = node->item;
					node->item = node->next->item;
					node->next->item = temp;
					isSorted = 0;
				}
			}
		}
	}
}

// reduce the quantity of an item based on a transcation/sale being carried out
int inventoryList_reduceQuantity(InventoryList *inventoryList, char searchCode[], int quantity)
{

    // to store curret items code
    char *code; 
    //  to store current items stock and new stock number
    int currentStock, newStock;
    // loop through every node/item of list
    for(Node *node = inventoryList->first; node != NULL; node = node->next){
            // store code of current item
        code = item_getCode(node->item);
            // check to see if current item code and sale code are the same
        if((strcmp(searchCode, code)) == 0){
            // get current stock of item
            currentStock = item_getStock(node->item);
             // calculate new stock
            newStock = currentStock - quantity;
            // if stock become less than 1
            if(newStock < 0){
                // transcation/sale has failed, do not change any values of item
                return 0;
            } else {
                // store newStock in current items stock
                node->item->stock = newStock;
                // transaction successful
                return 1;
            }
        } 
    }
}

// search items based on there additional information and return a stock count
int inventoryList_searchAdditional(InventoryList *inventoryList, char searchAdditional[])
{
    // will store current items additional information
    char *additional;
    // will store total stock
    int totalStock;
    // loop through all items
    for(Node *node = inventoryList->first; node != NULL; node = node->next){
	// get additional information of current item
        additional = item_getAdditional(node->item);
        // check to see if current additional and search additional are the same
        if((strcmp(searchAdditional, additional)) == 0){
            // total up the stock if they are
            totalStock = totalStock + item_getStock(node->item);
        }
    }
    // return total stock
    return totalStock;    
}

// get total resistance of all items in stock
int inventoryList_getResistance(InventoryList *inventoryList)
{
    char *additional;
    char *comType;
    int stock;
    for(Node *node = inventoryList->first; node != NULL; node=node->next){
        comType = item_getComType(node->item);
        stock = item_getStock(node->item);
        if((strcmp(comType, "resistor") == 0) && stock > 0){
            additional = item_getAdditional(node->item);
            printf("%s", additional);
            
            char *resistanceNum;
            char letter;
            for (int i = 0; i < strlen(additional); i++){
                if(isdigit(additional[i])){
                    int len = strlen(resistanceNum);
                    resistanceNum[len] = additional[i];
                    resistanceNum[len+1] = '\0';
                } else {
                    letter = additional[i];
                }
                printf("%s, %c", resistanceNum, letter);
            }
        }       
    }
}