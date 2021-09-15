/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** teams_connection_command
*/

#include "zappy_server.h"
#include "commands.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int returnnbrslot(client_t *client, server_t *server)
{

    for (int i = 0; i != server->infos.teams_length; i++)
        if (strcmp(client->team_name, server->infos.name_tab[i]) == 0)
            return (server->infos.teams_slots[i]);
    return -1;
}

char *connect_nbr(client_t *client, server_t *server)
{
    char response[10];

    for (int i = 0; i != server->infos.teams_length; i++)
        if (strcmp(client->team_name, server->infos.name_tab[i]) == 0)
            sprintf(response, "%d\n", server->infos.teams_slots[i]);
    return strdup(response);
}

char *fork_(__attribute__((unused))client_t *client,
__attribute__((unused)) server_t *server)
{
    chrono_set_cooldown(&client->egg, server->infos, 600.0);
    if (!is_cooldown_ready(client))
        return strdup("Not now !\n");
    reset_cooldown(client);
    set_cooldown(client, server->infos, 42.0);
    if (chrono_is_cooldown_ready(&client->egg) == true)
        send(client->socket, "Egg ready\n", 12, 0);
    if (returnnbrslot(client, server) >= 1)
        return strdup("ok\n");
    return strdup("ok\n");
}

char *eject(__attribute__((unused))client_t *client,
__attribute__((unused)) server_t *server)
{
    return strdup("ok\n");
}