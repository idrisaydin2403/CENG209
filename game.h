#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "utils.h"

#define MAX_HEALTH 100
#define MAX_LEVEL 10

void start_game();  

void battle(Player* player);  
void level_up(Player* player); 
void heal_player(Player* player);  
void loot(Player* player); 

void spawn_enemy(); 
void enemy_turn(Player* player);  

#endif