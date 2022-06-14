#ifndef HEADER_H
#define HEADER_H

/***************************************
* MACROS
****************************************/
#define C_SIZE 30
/*function declaration.*/
void insertFirst(char *movie_name, int screen, int total_seats, int seats_index[],int n_booked);
void printList();
void line();
void storeData();
void readData();
int printMovies();
void printScreen(char *choosed_movie);
int display_seats(char *choosed_movie, int screen_no);
void removeDuplicate();

#endif //HEADER_H