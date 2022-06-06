/**
 * @file user.c
 * @author Om Patel (Om.Patel@einfochips.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include "header.h"
#include<string.h>

int main()
{
    insertFirst("RRR", "INOX Adalaj", 4, 30, 20, 10);
    insertFirst("RRR", "INOX Gandhinagar", 4, 30, 30, 0);
    insertFirst("KGF", "INOX Adalaj", 4, 30, 30, 0);
    printList();
    int i;
    char moviename[C_SIZE];
    printf("Enter Movie name\n"
    "1. RRR\n"
    "2. KGF\n"
    );
    scanf(" %d",&i);
    if(i==1){
        strcpy(moviename,"RRR");
    }
    else if (i==2)
    {
        strcpy(moviename,"KGF");
    }

    theaterList(moviename);
    printf("\nDATA FOUND\n");

    return 0;
}