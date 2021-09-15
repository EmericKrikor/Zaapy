/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** map
*/

#include <stdbool.h>

#ifndef MAP_H_
#define MAP_H_

typedef struct s_tile {
    int q0;
    int q1;
    int q2;
    int q3;
    int q4;
    int q5;
    int q6;
    bool end;
} tile_t;

typedef struct s_map {
    tile_t **tilemap;
} map_t;

#endif /* !MAP_H_ */

