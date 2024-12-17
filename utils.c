#include "utils.h"
#include <stdlib.h>  
#include <time.h>    


int random_number(int min, int max) {
    
    srand(time(NULL));

 
    return (rand() % (max - min + 1)) + min;
}