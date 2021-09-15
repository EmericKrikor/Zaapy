/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** send_map_to_gui
*/

#include "zappy_server.h"
#include "map.h"

void send_map_to_gui(server_t *server)
{
    char *map = get_map(server->map.tilemap, server->infos);

    for (int i = 1; i != server->con->nb_connected; i++) {
        send(4, map, strlen(map), 0);
    }
}