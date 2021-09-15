/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** look around and get map commands
*/

#include "zappy_server.h"
#include "commands.h"
#include <stdlib.h>



void looknorth(client_t *client, server_t *server,
char *response, position_t *position)
{
    if (position->n == 0) {
        position->x = client->pos.x;
        position->y = client->pos.y;
        format(server, response, position);
    } else if (position->n == 2) {
        position->x = client->pos.x;
        if (client->pos.y == 0)
            position->y = server->infos.height - 1;
        else position->y = client->pos.y - 1;
        format(server, response, position);
    }
}

void looksouth(client_t *client, server_t *server,
char *response, position_t *position)
{
    if (position->n == 0) {
        position->x = client->pos.x;
        position->y = client->pos.y;
        format(server, response, position);
    } else if (position->n == 2) {
        position->x = client->pos.x;
        if (client->pos.y == server->infos.height -1)
            position->y = 0;
        else position->y = client->pos.y + 1;
        format(server, response, position);
    }
}

void lookeast(client_t *client, server_t *server,
char *response, position_t *position)
{
    if (position->n == 0) {
        position->x = client->pos.x;
        position->y = client->pos.y;
        format(server, response, position);
    } else if (position->n == 2) {
        if (client->pos.x == server->infos.width -1)
            position->x = 0;
        else position->x = client->pos.x + 1;
        position->y = client->pos.y;
        format(server, response, position);
    }
}

void lookwest(client_t *client, server_t *server,
char *response, position_t *position)
{
    if (position->n == 0) {
        position->x = client->pos.x;
        position->y = client->pos.y;
        format(server, response, position);
    } else if (position->n == 2) {
        if (client->pos.x == 0)
            position->x = server->infos.width - 1;
        else position->x = client->pos.x - 1;
        position->y = client->pos.y;
        format(server, response, position);
    }
}

char *look_around(client_t *client, server_t *server)
{
    char *response = malloc(4096);
    position_t *position = malloc(sizeof(position_t));
    position->tpos = client->pos.x;
    position->epos = client->pos.y;

    strcpy(response, "[ player ");
    for (int n = 0; n != 4; n++) {
        position->n = n;
        if (client->facing == NORTH)
            looknorth(client, server, response, position);
        if (client->facing == SOUTH)
            looksouth(client, server, response, position);
        if (client->facing == EAST)
            lookeast(client, server, response, position);
        if (client->facing == WEST)
            lookwest(client, server, response, position);
        if (n + 1 != 4)
            strcat(response, ", ");
    }
    strcat(response, "]\n");
    free(position);
    return response;
}