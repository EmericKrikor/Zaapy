/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** object
*/

#include "zappy_server.h"
#include "commands.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *take_object(client_t *client, server_t *server)
{
    if (client->arg[1] == NULL)
        return strdup("ko\n");
    if (strcmp(client->arg[1], "food") == 0 &&
    server->map.tilemap[client->pos.y][client->pos.x].q0 != 0) {
        client->inventory.food++;
        server->map.tilemap[client->pos.y][client->pos.x].q0--;
        return strdup("ok\n");
    } if (strcmp(client->arg[1], "linemate") == 0 &&
    server->map.tilemap[client->pos.y][client->pos.x].q1 != 0) {
        client->inventory.linemate++;
        server->map.tilemap[client->pos.y][client->pos.x].q1--;
        return strdup("ok\n");
    }
    return (strcmp(take_parse_suit(client, server), "ok\n") == 0
    ? strdup("ok\n") : strdup("ko\n"));
}

char *set_object(client_t *client, server_t *server)
{
    if (client->arg[1] == NULL)
        return strdup("ko\n");
    if (strcmp(client->arg[1], "food") == 0 && client->inventory.food != 0) {
        client->inventory.food--;
        server->map.tilemap[client->pos.y][client->pos.x].q0++;
        return strdup("ok\n");
    }
    if (strcmp(client->arg[1], "linemate") == 0 &&
    client->inventory.linemate != 0) {
        client->inventory.linemate--;
        server->map.tilemap[client->pos.y][client->pos.x].q1++;
        return strdup("ok\n");
    }
    return (strcmp(set_object_suit(client, server), "ok\n") == 0
    ? strdup("ok\n") : strdup("ko\n"));
}

int overcrystal(client_t *client, server_t *server)
{
    int result = 0;

    if (server->map.tilemap[client->pos.y][client->pos.x].q2 != 0)
        result += 1;
    if (server->map.tilemap[client->pos.y][client->pos.x].q3 != 0)
        result += 1;
    if (server->map.tilemap[client->pos.y][client->pos.x].q4 != 0)
        result += 1;
    if (server->map.tilemap[client->pos.y][client->pos.x].q5 != 0)
        result += 1;
    if (server->map.tilemap[client->pos.y][client->pos.x].q6 != 0)
        result += 1;
    return result;
}

char *incantation(client_t *client, server_t *server)
{
    char *lvl = malloc(sizeof(char) *30);

    chrono_set_cooldown(&client->incantation, server->infos, 300.0);
    if (!is_cooldown_ready(client))
        return strdup("Not now !\n");
    reset_cooldown(client);
    set_cooldown(client, server->infos, 300.0);

    if (client->level == 1) {
        if (server->map.tilemap[client->pos.y][client->pos.x].q1 == 1
            && overcrystal(client, server) == 0)
            client->level += 1;
        else
            return strdup("ko\n");
    }
    sprintf(lvl, "Current level: %d\n", client->level);
    if (chrono_is_cooldown_ready(&client->egg) == true)
         send(client->socket, "Elevation underway\n", 21, 0);
    return lvl;
}