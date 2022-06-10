#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

struct node
{
    char movie_name[C_SIZE];
    int screen;
    // struct seats *seat;
    struct seats
    {
        /* data */
        int avail_seat;
        int total_seat;
        int booked_seat;
        int *show_seat;
    } seat;

    struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

// display the list
void printList()
{
    struct node *ptr = head;
    // start from the beginning
    while (ptr != NULL)
    {
        line();
        printf("Movie Name: %s\n", ptr->movie_name);
        line();
        printf("Screen: %d\n", ptr->screen);
        printf("Total Seats: %d\nAvailable Seats: %d\nBooked Seats: %d\n", ptr->seat.total_seat, ptr->seat.avail_seat, ptr->seat.booked_seat);
        // print showsheet
        
        int design_count = 0;
        printf("\n");
        for (int index = 0; index < ptr->seat.total_seat; index++)
        {
            design_count++;
            printf("%d ", ptr->seat.show_seat[index]);
            if (design_count == 10)
            {
                printf("\n");
                design_count = 0;
            }
        }
        ptr = ptr->next;
        printf("\n");
    }
}

// insert link at the first location
void insertFirst(char *movie_name, int screen, int total_seats, int seats_index[], int n_booked)
{
    // create a link
    struct node *link = (struct node *)malloc(sizeof(struct node));

    strcpy(link->movie_name, movie_name);
    link->screen = screen;
    link->seat.avail_seat = total_seats - n_booked;
    link->seat.total_seat = total_seats;
    link->seat.booked_seat = n_booked;
    link->seat.show_seat = (int *)malloc(sizeof(int) * (total_seats));

    // initialize 0 to all seats
    for (int index = 0; index < total_seats; index++)
    {
        link->seat.show_seat[index] = 0;
    }
    for (int index = 0; index < n_booked; index++)
    {
        link->seat.show_seat[seats_index[index] - 1] = 1;
    }
    // point it to old first node
    link->next = head;

    // point first to new first node
    head = link;
}