/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** take object
*/

#include "zappy_server.h"
#include "commands.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* set_object_suit2(client_t *client, server_t *server)
{
    if (strcmp(client->arg[1], "phiras") == 0 &&
    client->inventory.phiras != 0) {
        client->inventory.phiras--;
        server->map.tilemap[client->pos.y][client->pos.x].q5++;
        return strdup("ok\n");
    } if (strcmp(client->arg[1], "thystame") == 0 &&
    client->inventory.thystame != 0) {
        client->inventory.thystame--;
        server->map.tilemap[client->pos.y][client->pos.x].q6++;
        return strdup("ok\n");
    }
    return strdup("ko\n");
}

char* set_object_suit(client_t *client, server_t *server)
{
    if (strcmp(client->arg[1], "deraumere") == 0 &&
    client->inventory.deraumere != 0) {
        client->inventory.deraumere--;
        server->map.tilemap[client->pos.y][client->pos.x].q2++;
        return strdup("ok\n");
    } if (strcmp(client->arg[1], "sibur") == 0 &&
    client->inventory.sibur != 0) {
        client->inventory.sibur--;
        server->map.tilemap[client->pos.y][client->pos.x].q3++;
        return strdup("ok\n");
    } if (strcmp(client->arg[1], "mendiane") == 0 &&
    client->inventory.mendiane != 0) {
        client->inventory.mendiane--;
        server->map.tilemap[client->pos.y][client->pos.x].q4++;
        return strdup("ok\n");
    }
    return (strcmp(set_object_suit2(client, server), "ok\n") == 0
    ? strdup("ok\n") : strdup("ko\n"));
}

char *take_parse_suit1(client_t *client, server_t *server)
{
    if (strcmp(client->arg[1], "phiras") == 0 &&
    server->map.tilemap[client->pos.y][client->pos.x].q5 != 0) {
        client->inventory.phiras++;
        server->map.tilemap[client->pos.y][client->pos.x].q5--;
        return strdup("ok\n");
    } if (strcmp(client->arg[1], "thystame") == 0 &&
    server->map.tilemap[client->pos.y][client->pos.x].q6 != 0) {
        client->inventory.thystame++;
        server->map.tilemap[client->pos.y][client->pos.x].q6--;
        return strdup("ok\n");
    }
    return strdup("ko\n");
}

char *take_parse_suit(client_t *client, server_t *server)
{
    if (strcmp(client->arg[1], "deraumere") == 0 &&
    server->map.tilemap[client->pos.y][client->pos.x].q2 != 0) {
        client->inventory.deraumere++;
        server->map.tilemap[client->pos.y][client->pos.x].q2--;
        return strdup("ok\n");
    } if (strcmp(client->arg[1], "sibur") == 0 &&
    server->map.tilemap[client->pos.y][client->pos.x].q3 != 0) {
        client->inventory.sibur++;
        server->map.tilemap[client->pos.y][client->pos.x].q3--;
        return strdup("ok\n");
    } if (strcmp(client->arg[1], "mendiane") == 0 &&
    server->map.tilemap[client->pos.y][client->pos.x].q4 != 0) {
        client->inventory.mendiane++;
        server->map.tilemap[client->pos.y][client->pos.x].q4--;
        return strdup("ok\n");
    }
    return (strcmp(take_parse_suit1(client, server), "ok\n") == 0
    ? strdup("ok\n") : strdup("ko\n"));
}