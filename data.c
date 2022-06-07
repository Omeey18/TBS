/**
 * @file admin.c
 * @author your name (Om.Patel@einfochips.com)
 * @brief
 * @version 0.1
 * @date 2022-06-06
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
    int found_flag=0,choice=0,count=0;
    char str_i[20];
    // start from the beginning
    while (ptr != NULL)
    {
        if(strcmp(movie_theater,ptr->movie_name)==0){
            line();
            count++;
            printf("[%d]: Theater Name: %s\n",count, ptr->theater_name);
            printf("Total Seats: %d\nAvailable Seats: %d\nBooked Seats: %d\n", ptr->seat.total_seat, ptr->seat.avail_seat, ptr->seat.booked_seat);
            printf("\n");
            found_flag=1;
            line();
        }
            ptr = ptr->next;    
    }
    while (1)
    {
        if(found_flag==1){
            printf("Enter 1 to %d for theater select: ",count);
            scanf("%d",&choice);
            // fgets( str_i, 20, stdin);
            // choice = strtol(str_i, NULL, 0);
            if(choice<=count && choice>0){
                break;
            }else{
                printf("Wrong Choice Try Again...!\n");
            }
        }else
        {
            break;
        }
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
