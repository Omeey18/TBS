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
        printf("Movie Name: %s\nScreen: %d\n", ptr->movie_name, ptr->screen);
        printf("Total Seats: %d\nAvailable Seats: %d\nBooked Seats: %d\n", ptr->seat.total_seat, ptr->seat.avail_seat, ptr->seat.booked_seat);
        // print showsheet
        for (int index = 0; index < (ptr->seat.total_seat - ptr->seat.booked_seat); index++)
        {
            printf("%d ", ptr->seat.show_seat[index]);
        }
        ptr = ptr->next;
        printf("\n");
    }
}

// insert link at the first location
void insertFirst(char *movie_name, int screen, int total_seats, int avail_seat, int booked_seats)
{
    // create a link
    struct node *link = (struct node *)malloc(sizeof(struct node));

    strcpy(link->movie_name, movie_name);
    link->screen = screen;
    link->seat.avail_seat = avail_seat;
    link->seat.total_seat = total_seats;
    link->seat.booked_seat = booked_seats;
    link->seat.show_seat = (int *)malloc(sizeof(int) * (total_seats - booked_seats));

    for (int index = 0; index < (total_seats - booked_seats); index++)
    {
        link->seat.show_seat[index] = 0;
    }
    // point it to old first node
    link->next = head;

    // point first to new first node
    head = link;
}