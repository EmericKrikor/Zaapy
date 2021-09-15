/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** get_tile_info from tilemap
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "zappy_server.h"
#include "raise.h"

#define SOUTH_X 1
#define SOUTH_Y 1

tile_t get_tile_infos(client_t client, tile_t **tilemap)
{
    return tilemap[client.pos.y][client.pos.x];
}

tile_t *get_tiles_vision_field_infos(client_t client, tile_t **tilemap,
__attribute__((unused))facing_e facing, __attribute__((unused))infos_t infos)
{
    tile_t *tile;
    int i = 0;
    int pres = 1;

    for (int j = 0; j != client.level; j++, pres += 2)
        i += pres;
    tile = malloc(sizeof(tile_t) * (i + 1));
    if (!tile)
        raise("Error while getting player field of vision");
    printf("\nClient pos: %d %d\nclient on tile: %d\n", client.pos.x,
    client.pos.y, tilemap[client.pos.x][client.pos.y].q0);
    return tile;
}

char *fill_map_content(char *response, vector_t pos,
tile_t **tilemap, infos_t infos)
{
    for (int i = 0; i != tilemap[pos.y][pos.x].q0; i++)
        strcat(response, "food ");
    for (int i = 0; i != tilemap[pos.y][pos.x].q1; i++)
        strcat(response, "linemate ");
    for (int i = 0; i != tilemap[pos.y][pos.x].q2; i++)
        strcat(response, "deraumere ");
    for (int i = 0; i != tilemap[pos.y][pos.x].q3; i++)
        strcat(response, "sibur ");
    for (int i = 0; i != tilemap[pos.y][pos.x].q4; i++)
        strcat(response, "mendiane ");
    for (int i = 0; i != tilemap[pos.y][pos.x].q5; i++)
        strcat(response, "phiras ");
    for (int i = 0; i != tilemap[pos.y][pos.x].q6; i++)
        strcat(response, "thystame ");
    if ((pos.x + 1) * (pos.y + 1) == (infos.width * infos.height))
        strcat(response, "]");
    else strcat(response, ",");
    return response;
}

char *get_map(tile_t **tilemap, infos_t infos)
{
    size_t map_size = infos.width * infos.height;
    char *response = malloc((map_size * 11) + 4);
    int x = 0;
    int y = 0;

    if (!response)
        raise("Error while translating map to string");
    strcpy(response, "[");
    for (; y != infos.height; y++) {
        for (x = 0; x != infos.width; x++) {
            fill_map_content(response, (vector_t) {x, y}, tilemap, infos);
        }
    }
    return response;
}