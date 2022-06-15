#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    // read data from csv
    FILE *file; // file pointer
    file = fopen("data.csv", "r");

    // VARIABLE
    char buffer[1024]; // buffer
    int column = 0;
    // data for linked list
    char movie_name[C_SIZE];
    int screen, t_seat, a_seat, b_seat;
    while (fgets(buffer, 1024, file))
    {
        column = 0;
        char *value;
        value = strtok(buffer, ",");
        // cout<<value;
        while (value)
        {
            if (column == 0)
            {
                strcpy(movie_name, value);
            }
            if (column == 1)
            {
                screen = atoi(value);
            }
            if (column == 2)
            {
                t_seat = atoi(value);
            }
            if (column == 3)
            {
                a_seat = atoi(value);
            }
            if (column == 4)
            {
                b_seat = atoi(value);
            }
            value = strtok(NULL, ",");
            column++;
        }
        insertFirst(movie_name, screen, t_seat, a_seat, b_seat);
    }
    fclose(file);

    printList(); // print all data
    return 0;
}
