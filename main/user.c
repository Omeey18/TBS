/**
 * @file user.c
 * @author Om Patel (Om.Patel@einfochips.com)
 * @brief
 * @version 0.1
 * @date 2022-06-07
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include "header.h"
#include <string.h>

int main()
{
    //insert data 
    insertFirst("RRR", "INOX Adalaj", 4, 30, 20, 10);
    insertFirst("RRR", "INOX Gandhinagar", 4, 30, 30, 0);
    insertFirst("KGF", "INOX Adalaj", 4, 30, 30, 0);
    insertFirst("BHOOL BHULAIYAA 2", "INOX Adalaj", 4, 30, 30, 0);
    printList();//print all data 
    int i;
    //new release movie array
    char moviename[4][C_SIZE] = {"RRR", "KGF", "BHOOL BHULAIYAA 2", "JURASSIC WORLD"};
    char moviechoose[C_SIZE];
    const char *userTheater;
    printf("Enter Movie name\n");
    for (i = 0; i < 4; i++)
    {
        printf("%d: %s\n", i + 1, moviename[i]);
    }
    scanf("%1d", &i);//read movie name 
    strcpy(moviechoose, moviename[i - 1]);

    theaterList(moviechoose);//print all theater which has this movie
    // printf("\nDATA FOUND\n");
    // printf("Your choose theater is %s\n",userTheater);
    return 0;
}