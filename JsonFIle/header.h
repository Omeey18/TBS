#ifndef HEADER_H
#define HEADER_H
#include <stdbool.h>

/***************************************
* MACROS
****************************************/
#define C_SIZE 30
#define READERSIZE 5024


/***************************************
 * GLOBAL VARIABLES
 ****************************************/
int total_movies;
char movies_name[C_SIZE][C_SIZE];

/***************************************
* FUNCTION DECLARATION
****************************************/
/*function declaration.*/
void insertFirst(char *movie_name, int screen, int price, int total_seats, int seats_index[],int n_booked);
void printList();
void storeData();
void readData();
char *printMovies();
void printScreen(char *choosed_movie);
int display_seats(char *choosed_movie, int screen_no);
void removeDuplicate();
int adminWork();
void resetAllSeats();
void resetSeats();
void resetOneMovieSeats();
int addData();
struct node* deleteFirst();
bool isEmpty();
void deleteAll();
int deleteOneData();
void delete();

void logo();
void line();
void setBlueColor();
void setDefaultColor();
void setRedColor();
void setGreenColor();


#endif //HEADER_H