#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <json-c/json.h>
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

void storeData()
{
    struct node *ptr = head;

    FILE *file;                       // file pointer
    file = fopen("data.json", "w+"); // opening json file
    char *buffer;                     // store string data

    // Create an empty array : []
    json_object *jarray = json_object_new_array();

    // start from the beginning
    while (ptr != NULL)
    {

        // create json object
        json_object *parsed_json = json_object_new_object();
        json_object *seats_array = json_object_new_array();
        // storing data into json object
        json_object_object_add(parsed_json, "moviename", json_object_new_string(ptr->movie_name));
        json_object_object_add(parsed_json, "Screen", json_object_new_int(ptr->screen));
        json_object_object_add(parsed_json, "t_seat", json_object_new_int(ptr->seat.total_seat));

        // storing booked seats index
        for (int index = 0; index < ptr->seat.total_seat; index++)//loop total seats
        {
            if (ptr->seat.show_seat[index] == 1)//if seat is book then store in json array
            {
                json_object_array_add(seats_array, json_object_new_int(index + 1));
            }
        }
        //storing josn array into json object
        json_object_object_add(parsed_json, "show_seat", seats_array);

        json_object_array_add(jarray, parsed_json);
        ptr = ptr->next;
    }
    // storing json object into string variable
    buffer = json_object_to_json_string(jarray);
    // printf("%s",buffer);
    fprintf(file, "%s", buffer); // writing data into json file
    // fwrite(buffer,1024,1,file);
    fclose(file); // close file
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