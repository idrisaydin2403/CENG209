#include <stdio.h>
#include "game.h"
#include "player.h"

void start_game() {
  
    printf("Oyun Başladı!\n");

   
    Player player;

    
    init_player(&player);  

    printf("Oyun başladı. Zindana giriyorsunuz...\n");
    
}