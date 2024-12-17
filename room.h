#ifndef ROOM_H
#define ROOM_H

typedef struct Room {
	char *description;
	struct Room *up;
	struct Room *down;
	struct Room *left;
	struct Room *right;
} Room;

void init_room(Room *room, const char *description);
void connect_rooms(Room *room1, Room *room2, const char *direction);

#endif