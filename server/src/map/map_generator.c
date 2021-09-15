/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** map generator
*/

#include "zappy_server.h"
#include "map.h"
#include "raise.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void map_generate_ressources(tile_t **tab, int width, int height)
{
    for (float q0_max = (width * height) * 0.50; q0_max >= 0; q0_max--)
        tab[rand() % height][rand() % width].q0 += 1;
    for (float q1_max = (width * height) * 0.30; q1_max >= 0; q1_max--)
        tab[rand() % height][rand() % width].q1 += 1;
    for (float q2_max = (width * height) * 0.15; q2_max >= 0; q2_max--)
        tab[rand() % height][rand() % width].q2 += 1;
    for (float q3_max = (width * height) * 0.10; q3_max >= 0; q3_max--)
        tab[rand() % height][rand() % width].q3 += 1;
    for (float q4_max = (width * height) * 0.10; q4_max >= 0; q4_max--)
        tab[rand() % height][rand() % width].q4 += 1;
    for (float q5_max = (width * height) * 0.08; q5_max >= 0; q5_max--)
        tab[rand() % height][rand() % width].q5 += 1;
    for (float q6_max = (width * height) * 0.05; q6_max >= 0; q6_max--)
        tab[rand() % height][rand() % width].q6 += 1;
}

tile_t **map_generate(infos_t infos)
{
    tile_t **tab = malloc(sizeof(tile_t*) * (infos.height + 1));

    if (!tab)
        raise("Error while creating map");
    tab[infos.height] = NULL;
    for (int i = 0; i != infos.height; i++) {
        tab[i] = malloc(sizeof(tile_t) * (infos.width + 1));
        if (!tab[i])
            raise("Error while creating map");
        tab[i][infos.width] = (tile_t){0, 0, 0, 0, 0, 0, 0, true};
    }
    srand(time(NULL));
    for (int i = 0; i != infos.height; i++) {
        for (int j = 0; j != infos.width; j++)
            tab[i][j] = (tile_t){0, 0, 0, 0, 0, 0, 0, true};
    }
    map_generate_ressources(tab, infos.width, infos.height);
    printf("Map generated succesfully\n");
    return tab;
}