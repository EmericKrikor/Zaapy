/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** commands
*/

#include "zappy_server.h"
#include "commands.h"
#include "raise.h"
#include <stdio.h>
#include <stdlib.h>

static char *text_basic_commands[13] = {"Forward", "Right", "Left",
    "Look", "Inventory", "Broadcast", "Connect_nbr",
    "Fork", "Eject", "Take", "Set",
    "Incantation", NULL};

static char *(*basic_commands[13])() = {forward, right, left,
    look_around, inventory, broadcast, connect_nbr,
    fork_, eject, take_object, set_object, incantation, NULL};

char *basic_command_loop(client_t *client, server_t *server)
{
    client->arg = my_str_to_wordtab(strip_copy(client->buffer));
    if (client->arg == NULL)
        return strdup("No commands\n");
    for (int i = 0; basic_commands[i]; i++) {
        if (strcmp(client->arg[0], text_basic_commands[i]) == 0) {
            client->response = (*basic_commands[i])(client, server);
            break;
        }
    }
    return (client->response != NULL) ? client->response : strdup("ko\n");
}

char *graphic_cmd(__attribute__((unused)) client_t *client,
__attribute__((unused)) server_t *server)
{
    return strdup("ok\n");
}