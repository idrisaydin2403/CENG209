#include <stdio.h>
#include <string.h>
#include "player.h"

void init_player(Player* p) {
    
    printf("Oyuncu oluşturuluyor...\n");

    p->health = 100;
    p->power = 20;
    p->level = 1;
    p->gold = 0;
    p->experience = 0;

    
    printf("Oyuncunun ismini girin: ");
    fgets(p->name, sizeof(p->name), stdin);
    p->name[strcspn(p->name, "\n")] = '\0';  

    printf("Oyuncu başarıyla oluşturuldu!\n");
    display_player_stats(p);
}

void display_player_stats(const Player* p) {
    printf("Oyuncu: %s\n", p->name);
    printf("Sağlık: %d\n", p->health);
    printf("Güç: %d\n", p->power);
    printf("Seviye: %d\n", p->level);
    printf("Altın: %d\n", p->gold);
    printf("Deneyim: %d\n", p->experience);
}

void level_up(Player* p) {
    p->level++;
    p->health += 10; 
    p->power += 5;    
    printf("Tebrikler! %s, %d. seviyeye ulaştı!\n", p->name, p->level);
    display_player_stats(p);
}

void gain_experience(Player* p, int exp) {
    
    p->experience += exp;
    printf("%s, %d deneyim kazandı!\n", p->name, exp);

    
    if (p->experience >= 100) {
        printf("%s, seviye atlamak için yeterli deneyime sahip!\n", p->name);
        level_up(p);
        p->experience = 0;  
    }
}

void increase_power(Player* p, int power_increase) {
    
    p->power += power_increase;
    printf("%s'in gücü arttı! Yeni güç: %d\n", p->name, p->power);
}