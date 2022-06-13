#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    readData(); // reading data form json

    // printList(); // print all data

    printMovies();//print all movie name

    //writing all data to json again
    storeData();    
    return 0;
}
