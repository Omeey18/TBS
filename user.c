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
    char moviename[4][C_SIZE]={"RRR","KGF","BHOOL BHULAIYAA 2","JURASSIC WORLD"};
    char moviechoose[C_SIZE];
    printf("Enter Movie name\n");
    for(i=0;i<4;i++)
    {
    printf("%d: %s\n",i+1,moviename[i]);
    }

        scanf("%1d",&i);
        strcpy(moviechoose,moviename[i-1]);

    

    theaterList(moviechoose);
    // printf("\nDATA FOUND\n");

    return 0;
}