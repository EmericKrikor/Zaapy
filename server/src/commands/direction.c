/*
** EPITECH PROJECT, 2021
** ZAppy
** File description:
** direction
*/

#include "zappy_server.h"
#include "commands.h"


char *forward(client_t *client, __attribute__((unused)) server_t *server)
{
    if (!is_cooldown_ready(client))
        return strdup("Not now !\n");
    reset_cooldown(client);
    set_cooldown(client, server->infos, 7.0);
    switch (client->facing) {
    case NORTH:
        if (client->pos.y == 0)
            client->pos.y = server->infos.width - 1;
        else client->pos.y += -1;
        break;
    case SOUTH:
        if (client->pos.y == 9)
            client->pos.y = 0;
        else client->pos.y += 1;
        break;
    case EAST:
        if (client->pos.x == 9)
            client->pos.x = 0;
        else client->pos.x += 1;
        break;
    case WEST:
        if (client->pos.x == 0)
            client->pos.x = server->infos.height - 1;
        else client->pos.x += -1;
        break;
    }
    return strdup("ok\n");
}

char *left(client_t *client, __attribute__((unused)) server_t *server)
{
    switch (client->facing) {
    case NORTH:
        client->facing = WEST;
        break;
    case SOUTH:
        client->facing = EAST;
        break;
    case EAST:
        client->facing = NORTH;
        break;
    case WEST:
        client->facing = SOUTH;
        break;
    }
    return strdup("ok\n");
}

char *right(client_t *client, __attribute__((unused)) server_t *server)
{
    switch (client->facing) {
    case NORTH:
        client->facing = EAST;
        break;
    case SOUTH:
        client->facing = WEST;
        break;
    case EAST:
        client->facing = SOUTH;
        break;
    case WEST:
        client->facing = NORTH;
        break;
    }
    return strdup("ok\n");
}

char *broadcast(client_t *client, server_t *server)
{
    for (int i = 1; i != server->con->nb_connected; i++) {
        if (client->socket - 3 != i)
            send(server->con->socket_list[i],
            client->arg[1], strlen(client->arg[1]), 0);
    }
    return strdup("ok\n");
}