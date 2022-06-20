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
#include <string.h>
#include "header.h"

/***************************************
 * MAIN FUNCTION
 ****************************************/
int init()
{

    while (1)
    {

        int user_admin_ch;
        line();
        printf("[+] 1 for admin:\n[+] 2 for user:\n[+] 3 for exit: ");
        scanf("%d", &user_admin_ch);
        getchar();
        printf("\n");
        line();
        // choosing user, admin or exit
        switch (user_admin_ch)
        {
        // admin pannel
        case 1:
            /* code */
            printf("YOu are in admin panel\n");
            adminWork();
            break;

        // user pannel
        case 2:
            /* code */
            printf("YOu are in user panel\n");
            char movie[C_SIZE] = {};
            strcpy(movie, printMovies()); // print all movie name
            printScreen(movie);
            break;

        // exit form code
        case 3:
            /* code */
            // writing all data to json again
            storeData();
            return 0;

        default:
            printf("Wronge choice\n");
            break;
        }

        // printList(); // print all data
    }
}

int main()
{
    readData(); // reading data form json
    init();
    return 0;
}
