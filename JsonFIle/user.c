#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <json-c/json.h>
#include "header.h"

int main()
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

    //iterrating over all json object
    for (int i = 0; i < index; i++)
    {
        //store one json object in data
        data = json_object_array_get_idx(parsed_json, i);

        //reading data with its key and store in respective object
        json_object_object_get_ex(data, "moviename", &movie_name);
        json_object_object_get_ex(data, "Screen", &screen);
        json_object_object_get_ex(data, "t_seat", &t_seat);
        json_object_object_get_ex(data, "show_seat", &show_seats);

        //find n seat index
        n_seats = json_object_array_length(show_seats);
        seat_index = (int *) malloc(sizeof(int)*n_seats);
        for(int j=0;j<n_seats;j++){
            seat_count = json_object_array_get_idx(show_seats,j);
            seat_index[j]=json_object_get_int(seat_count);
        }
        //storing all data into local variable 
        strcpy(movie, json_object_get_string(movie_name));
        scrn = json_object_get_int(screen);
        Tseat = json_object_get_int(t_seat);

        //prints seat index
        // printf("Movie name: %s\n",movie);
        // for(int j=0;j<n_seats;j++){
        //     printf("%d ",seat_index[j]);
        // }
        // printf("\n");

        // push all data into linked list 
        insertFirst(movie, scrn, Tseat, seat_index,n_seats);
    }

    // printf("Data: %lu", index);

    printList(); // print all data



    //writing all data to json again
    storeData();    
    return 0;
}
