/*****************************************************************************
Description : Implements an abstract data type consisting of an instance of a 
              date struct. Contains all of the information relating to a 
              particular date and a set of interface functions.
 *****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Date.h"

// creates new date instance by allocating memory
Date *date_new(int day, int month, int year)
{
    Date *date =(Date*)malloc(sizeof(Date));
    
    if (date == NULL)
    {
          fprintf(stderr, "Error: Unable to allocate "
              "memory in date_new()\n");
      exit(EXIT_FAILURE);    
    }
    
   date->day = day;
   date->month = month;
   date->year = year;
   
   return date;
}

// frees up allocated memory for given date
void date_free(Date *date)
{
    free(date);
}

// prints a given date in dd/mm/yyyy format
void date_print(Date *date)
{
    printf("%d/%d/%d", date->day, date->month, date->year);
}