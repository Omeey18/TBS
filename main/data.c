/**
 * @file data.c
 * @author Om Patel (Om.Patel@einfochips.com)
 * @brief
 * @version 0.1
 * @date 2022-06-07
 *
 * @copyright Copyright (c) 2022
 *
 */

/***************************************
 * INCLUDES
 ****************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "header.h"

struct node
{
    char movie_name[C_SIZE];
    char theater_name[C_SIZE];
    int time_slots;
    // struct seats *seat;
    struct seats
    {
        /* data */
        int avail_seat;
        int total_seat;
        int booked_seat;
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
        printf("Movie Name: %s\nTheater Name: %s\nTime Slots: %d\n", ptr->movie_name, ptr->theater_name, ptr->time_slots);
        printf("Total Seats: %d\nAvailable Seats: %d\nBooked Seats: %d\n", ptr->seat.total_seat, ptr->seat.avail_seat, ptr->seat.booked_seat);
        ptr = ptr->next;
        printf("\n");
    }
}

// display the list
void theaterList(char *movie_theater)
{
    struct node *ptr = head;
    int found_flag = 0, choice = 0, count = 0;
    char str_i[20];
    // start from the beginning
    char temp_theatername[C_SIZE][C_SIZE];
    while (ptr != NULL)
    {
        if (strcmp(movie_theater, ptr->movie_name) == 0)
        {
            line();
            strcpy(temp_theatername[count], ptr->theater_name);
            count++;
            printf("[%d]: Theater Name: %s\n", count, ptr->theater_name);
            printf("Total Seats: %d\nAvailable Seats: %d\nBooked Seats: %d\n", ptr->seat.total_seat, ptr->seat.avail_seat, ptr->seat.booked_seat);
            printf("\n");
            found_flag = 1;
            line();
        }
        ptr = ptr->next;
    }
    while (1)
    {
        // check that theater is availabel or not
        if (found_flag == 1)
        {
            printf("Enter 1 to %d for theater select: ", count);
            // fflush(stdin);
            scanf("%d", &choice);
            printf("ch: %d\n",choice);
            // fgets( str_i, 20, stdin);
            // choice = strtol(str_i, NULL, 0);
            if (choice <= count && choice > 0)
            {

                break;
            }
            else
            {
                printf("Wrong Choice Try Again...!\n");
            }
        }
        else
        {
            break;
        }
    }
    printf("choose theater is :%s\n", temp_theatername[choice - 1]);
    showSheats(movie_theater, temp_theatername[choice - 1]);
}

void showSheats(char *movie, char *theaterName)
{
    struct node *ptr = head;
    int count = 0, seats = 0;

    while (ptr != NULL)
    {
        if (strcmp(movie, ptr->movie_name) == 0 && strcmp(theaterName, ptr->theater_name) == 0)
        {
            line();
            if (ptr->seat.avail_seat <= 0)
            {
                printf("Theater is booked\n");
                break;
            }
            // reading seat amount user want to book
            printf("Enter seats you want to booked: ");
            scanf("%d", &seats);
            if (ptr->seat.avail_seat - seats < 0)
            {
                printf("Seat is not availabel\n");
                break;
            }
            else
            {
                ptr->seat.avail_seat = ptr->seat.avail_seat - seats;
                ptr->seat.booked_seat = ptr->seat.booked_seat + seats;
                printf("%d seat booked successfully...!\n", seats);
                printf("Total Seats: %d\nAvailable Seats: %d\nBooked Seats: %d\n", ptr->seat.total_seat, ptr->seat.avail_seat, ptr->seat.booked_seat);
                printf("\n");
            }

            // strcpy(temp_theatername[count],ptr->theater_name);
            count++;
            // found_flag=1;
            line();
        }
        ptr = ptr->next;
    }
}
// insert link at the first location
void insertFirst(char *movie_name, char *theater_name, int time_slots, int total_seats, int avail_seat, int booked_seats)
{
    // create a link
    struct node *link = (struct node *)malloc(sizeof(struct node));

    strcpy(link->movie_name, movie_name);
    strcpy(link->theater_name, theater_name);
    link->time_slots = time_slots;
    link->seat.avail_seat = avail_seat;
    link->seat.total_seat = total_seats;
    link->seat.booked_seat = booked_seats;
    // point it to old first node
    link->next = head;

    // point first to new first node
    head = link;
}	
