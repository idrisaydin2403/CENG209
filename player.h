#ifndef PLAYER_H
#define PLAYER_H

typedef struct {
    int health;
    int power;
    int level;
    int gold;
    int experience;
    char name[50];
} Player;

void init_player(Player* p);
void display_player_stats(const Player* p);
void level_up(Player* p);
void gain_experience(Player* p, int exp);
void increase_power(Player* p, int power_increase);

#endif