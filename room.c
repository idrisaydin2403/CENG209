#include "room.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>  

void init_room(Room *room, const char *description) {
    room->description = strdup(description);  
    room->up = NULL;  
    room->down = NULL;
    room->left = NULL;
    room->right = NULL;
}

void connect_rooms(Room *room1, Room *room2, const char *direction) {
    if (strcmp(direction, "right") == 0) {
        room1->right = room2;
        room2->left = room1;
    }
    else if (strcmp(direction, "left") == 0) {
        room1->left = room2;
        room2->right = room1;
    }
    else if (strcmp(direction, "up") == 0) {
        room1->up = room2;
        room2->down = room1;
    }
    else if (strcmp(direction, "down") == 0) {
        room1->down = room2;
        room2->up = room1;
    }
}
