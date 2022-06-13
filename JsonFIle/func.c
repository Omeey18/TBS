#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <json-c/json.h>
#include "header.h"

int total_movies;
char movies_name[C_SIZE][C_SIZE];

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

// reading data from json file
void readData()
{
    // read data from csv
    FILE *file;                     // file pointer
    file = fopen("data.json", "r"); // opening json file

    // VARIABLE
    char buffer[1024]; // buffer
    // data for linked list
    char movie[C_SIZE];
    int scrn, Tseat, *seat_index;

    // json parsing
    // declare all json objects
    struct json_object *parsed_json;
    struct json_object *movie_name;
    struct json_object *screen;
    struct json_object *t_seat;
    struct json_object *show_seats;
    struct json_object *seat_count;
    size_t n_seats;
    struct json_object *data;

    // read json file
    fread(buffer, 1024, 1, file);
    fclose(file); // close file

    parsed_json = json_tokener_parse(buffer);             // store all data into parsed json object
    size_t index = json_object_array_length(parsed_json); // store number of json object in index
    total_movies = index;                                 // storing data into global variable
    // iterrating over all json object
    for (int i = 0; i < index; i++)
    {
        // store one json object in data
        data = json_object_array_get_idx(parsed_json, i);

        // reading data with its key and store in respective object
        json_object_object_get_ex(data, "moviename", &movie_name);
        json_object_object_get_ex(data, "Screen", &screen);
        json_object_object_get_ex(data, "t_seat", &t_seat);
        json_object_object_get_ex(data, "show_seat", &show_seats);

        // find n seat index
        n_seats = json_object_array_length(show_seats);
        seat_index = (int *)malloc(sizeof(int) * n_seats);
        for (int j = 0; j < n_seats; j++)
        {
            seat_count = json_object_array_get_idx(show_seats, j);
            seat_index[j] = json_object_get_int(seat_count);
        }
        // storing all data into local variable
        strcpy(movie, json_object_get_string(movie_name));
        strcpy(movies_name[i], movie); // storing data into global variable
        scrn = json_object_get_int(screen);
        Tseat = json_object_get_int(t_seat);

        // prints seat index
        //  printf("Movie name: %s\n",movie);
        //  for(int j=0;j<n_seats;j++){
        //      printf("%d ",seat_index[j]);
        //  }
        //  printf("\n");

        // push all data into linked list
        insertFirst(movie, scrn, Tseat, seat_index, n_seats);
    }
}

// storing data into json file
void storeData()
{
    struct node *ptr = head;

    FILE *file;                      // file pointer
    file = fopen("data.json", "w+"); // opening json file
    char *buffer;                    // store string data

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
        for (int index = 0; index < ptr->seat.total_seat; index++) // loop total seats
        {
            if (ptr->seat.show_seat[index] == 0) // if seat is book then store in json array
            {
                json_object_array_add(seats_array, json_object_new_int(index + 1));
            }
        }
        // storing josn array into json object
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
            printf("%d\t", ptr->seat.show_seat[index]);
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
        link->seat.show_seat[index] = index + 1;
    }
    for (int index = 0; index < n_booked; index++)
    {
        link->seat.show_seat[seats_index[index] - 1] = 0;
    }
    // point it to old first node
    link->next = head;

    // point first to new first node
    head = link;
}

int printMovies()
{
    int movie_count = 0, movie_choice = 0;
    char choosed_movie[C_SIZE];
    for (int i = 0; i < total_movies; i++)
    {
        line();
        printf("%d: %s\n", i + 1, movies_name[i]);
        movie_count++;
    }

    if (movie_count > 0)
    {
        line();
        printf("Enter 1 to %d to select movie: ", movie_count);
        while (1)
        {
            /* code */
            scanf("%1d", &movie_choice);
            if (movie_choice > 0 && movie_choice <= movie_count)
            {
                strcpy(choosed_movie, movies_name[movie_choice - 1]);
                break;
            }
            else
                printf("Wronge Choice Try Again...!\n");
        }
    }
    else
    {
        printf("No Moives available\n");
        return 0;
    }
    // printf("Choosed Movie is: %s\n",choosed_movie);
    printScreen(choosed_movie);
    return 0;
}

// It will print screens according to movie  
void printScreen(char *choosed_movie)
{
    struct node *ptr = head;
    // start from the beginning
    while (ptr != NULL)
    {
        if (strcmp(choosed_movie, ptr->movie_name) == 0)
        {
            line();
            printf("Screen: %d\n", ptr->screen);
            printf("Total Seats: %d\nAvailable Seats: %d\nBooked Seats: %d\n", ptr->seat.total_seat, ptr->seat.avail_seat, ptr->seat.booked_seat);
        }

        ptr = ptr->next;
    }
    int screen_no;
    line();
    printf("Enter Screen number: ");
    scanf("%d", &screen_no);
    display_seats(choosed_movie, screen_no);
}

//it will display seats according screen no...
int display_seats(char *choosed_movie, int screen_no)
{
    struct node *ptr = head;
    int flag = 0;
    // start from the beginning
    // print showsheet

    line();
    while (ptr != NULL)
    {
        int design_count = 0;
        if (strcmp(choosed_movie, ptr->movie_name) == 0 && screen_no == ptr->screen)
        {
            printf("Screen: %d\n", ptr->screen);
            printf("Total Seats: %d\nAvailable Seats: %d\nBooked Seats: %d\n", ptr->seat.total_seat, ptr->seat.avail_seat, ptr->seat.booked_seat);
            line();
            printf("\n");
            for (int index = 0; index < ptr->seat.total_seat; index++)
            {
                design_count++;
                printf("%d\t", ptr->seat.show_seat[index]);
                if (design_count == 10)
                {
                    printf("\n\n");
                    design_count = 0;
                }
            }
            flag = 1;
            if(ptr->seat.avail_seat<=0){
                printf("No Seat available...!\n");
                return 0;
            }
        }
        ptr = ptr->next;
    }
    printf("\n");
    if (flag == 0)
    {
        printf("No screen found...!\n");
    }



    //booking tickets 
    printf("How many tickets you want to book\n");
    return 0;
}
