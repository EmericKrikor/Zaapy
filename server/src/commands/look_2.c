/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** look
*/

#include "zappy_server.h"
#include "commands.h"
#include <stdlib.h>

void format(server_t *server, char *response, position_t *position)
{
    for (int i = 0; i != server->map.tilemap[position->y][position->x].q0; i++)
        strcat(response, "food ");
    for (int i = 0; i != server->map.tilemap[position->y][position->x].q1; i++)
        strcat(response, "linemate ");
    for (int i = 0; i != server->map.tilemap[position->y][position->x].q2; i++)
        strcat(response, "deraumere ");
    for (int i = 0; i != server->map.tilemap[position->y][position->x].q3; i++)
        strcat(response, "sibur ");
    for (int i = 0; i != server->map.tilemap[position->y][position->x].q4; i++)
        strcat(response, "mendiane ");
    for (int i = 0; i != server->map.tilemap[position->y][position->x].q5; i++)
        strcat(response, "phiras ");
    for (int i = 0; i != server->map.tilemap[position->y][position->x].q6; i++)
        strcat(response, "thystame ");
}