#include <stdio.h>
#include "menu.h"
#include "view_showtimes.h"

int main(){
    int option = 0;
    option = menu();

    switch (option){
        case 1:
        showMoviesList();
        break;
        
        case 2:
        break;

        case 3:
        break;

        case 4:
        break;

        case 5:
        break;

        case 6:
        break;

        case 7:
        print("Exiting program...\n");
        return 0;
        break;
    }
}