#ifndef DATE_H
#define DATE_H

typedef struct DateStruct
{
    int day;
    int month;
    int year;
}
Date;

/*****************************************************************************
Procedure   : date_new
Parameters  : int day - day of date struct
              int month - month of date struct
              int year - year of date struct.
Returns     : Date* - pointer to newly created Date
Description : Allocate memory for a new Date and initialise it.  Generates an 
              error message and the program terminates if insufficient memory 
              is available.
 *****************************************************************************/
Date *date_new(int day, int month, int year);

/*****************************************************************************
Procedure   : date_free
Parameters  : Date *date - pointer to a date
Returns     : none
Description : Frees the memory taken by a date.
 *****************************************************************************/
void date_free(Date *date);

/*****************************************************************************
Procedure   : date_print
Parameters  : Date *date - pointer to a date
Returns     : none
Description : Prints out all of a date in dd/mm/yyyy format
 *****************************************************************************/
void date_print(Date *date);

/*****************************************************************************
Procedure   : date_getDay
Parameters  : Date *day - pointer to a Date.
Returns     : date->day - the day of the date.
Description : Accessor function returning the day for a Date struct.
 *****************************************************************************/
static inline int date_getDay(Date *date)
{
    return date->day;
}

/*****************************************************************************
Procedure   : date_getMonth
Parameters  : Date *date - pointer to a Date.
Returns     : date->month - the month of the date.
Description : Accessor function returning the month for a Date struct.
 *****************************************************************************/
static inline int date_getMonth(Date *date)
{
    return date->month;
}

/*****************************************************************************
Procedure   : date_getYear
Parameters  : Date *day - pointer to a Date.
Returns     : date->year - the year of the date.
Description : Accessor function returning the year for a Date struct.
 *****************************************************************************/
static inline int date_getYear(Date *date)
{
    return date->year;
}

#endif /* DATE_H */

