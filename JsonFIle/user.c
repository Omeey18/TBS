/**
 * @file user.c
 * @author OM PATEL(Om.Patel@einfochips.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
/***************************************
* HEADER FILES
****************************************/
#include <stdio.h>
#include "header.h"



/***************************************
* MAIN FUNCTION
****************************************/
int main()
{
    readData(); // reading data form json

    // printList(); // print all data

    printMovies();//print all movie name

    //writing all data to json again
    storeData();    
    return 0;
}
