#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"    
#include "room.h"      
#include "creature.h"
#include "utils.h"
void process_command(char *command, Player *player, Room *current_room, Creature *creature) {
    if (strncmp(command, "move", 4) == 0) {
        char direction[10];
        if (sscanf(command, "move %s", direction) == 1) {
            if (strcmp(direction, "right") == 0 && current_room->right != NULL) {
                *current_room = *(current_room->right);
                printf("Kendini %s odasinda buldun.\n", current_room->description);
            } else if (strcmp(direction, "left") == 0 && current_room->left != NULL) {
                *current_room = *(current_room->left);
                printf("Kendini %s odasinda buldun.\n", current_room->description);
            } else {
                printf("Bu yönde gidilemez.\n");
            }
        }
    }
    else if (strcmp(command, "look") == 0) {
        printf("Odayı inceledin: %s\n", current_room->description);
    }
    else if (strncmp(command, "pickup", 6) == 0) {
        char item_id[50];
        if (sscanf(command, "pickup %s", item_id) == 1) {
            printf("Eşyayı aldın: %s\n", item_id);  
        }
    }
    else if (strcmp(command, "inventory") == 0) {
        printf("Envanterini inceledin. Henüz bir şeyin yok.\n");  
    }
    else if (strcmp(command, "attack") == 0) {
    if (creature != NULL) {
        printf("Goblin'e saldırdın! Canavara %d hasar verdin.\n", player->attack_power);
        creature->health -= player->attack_power;
        if (creature->health <= 0) {
            printf("Goblin'i yendin!\n");
            creature = NULL;  
        } else {
            printf("Goblin'in kalan sağlığı: %d\n", creature->health);
        }
    } else {
        printf("Canavar şu anda odada değil.\n");
    }
}

    else if (strcmp(command, "exit") == 0) {
        
    } else {
        printf("Geçersiz komut.\n");
    }
}

int main() {
    Player player;
    char player_name[50];

    printf("Oyuncu ismini girin: ");
    fgets(player_name, sizeof(player_name), stdin);
    player_name[strcspn(player_name, "\n")] = 0;  

    init_player(&player);
    strcpy(player.name, player_name);  

    Room room1, room2;
    init_room(&room1, "Karanlık bir oda.");
    init_room(&room2, "Işıklı bir oda.");
    connect_rooms(&room1, &room2, "right");

    Creature creature = {"Goblin", 50, 5};  

    Room *current_room = &room1;
    char command[100];
    
    printf("Oyun Başladı! Komutları yazın: move <yön>, look, pickup <eşya_id>, inventory, attack, exit\n");

    while (1) {
        printf("\nKomut girin: ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "exit") == 0) {
            printf("Oyundan çıkılıyor...\n");
            break;
        }

        process_command(command, &player, current_room, &creature);
    }

    return 0;
}