/*
** EPITECH PROJECT, 2021
** inventory
** File description:
** zappy
*/

#include "zappy_server.h"
#include "commands.h"
#include <stdlib.h>

static char *text_inv[8] = { "food ", "linemate ",
    "deraumere ", "sibur ", "mendiane ", "phiras ", "thystame ", NULL};

int checksize(client_t *client)
{
    int length = 0;

    for (int i = 0; i != client->inventory.food; i++)
        length += 1;
    for (int i = 0; i != client->inventory.linemate; i++)
        length += 1;
    for (int i = 0; i != client->inventory.deraumere; i++)
        length += 1;
    for (int i = 0; i != client->inventory.sibur; i++)
        length += 1;
    for (int i = 0; i != client->inventory.mendiane; i++)
        length += 1;
    for (int i = 0; i != client->inventory.phiras; i++)
        length += 1;
    for (int i = 0; i != client->inventory.thystame; i++)
        length += 1;
    return length;
}

char *strconcat(char *response, int i, int key)
{
    char *tmp = malloc(sizeof(char) * 1024);

    if (key == 6)
        sprintf(tmp, "%d", i);
    else
        sprintf(tmp, "%d, ", i);
    strcat(response, text_inv[key]);
    strcat(response, tmp);
    return response;
}

void format_inventory1(client_t *client, char *response)
{
    for (int i = 0; i <= client->inventory.sibur; i++)
        if (i == client->inventory.sibur)
            response = strconcat(response, i, 3);
    for (int i = 0; i <= client->inventory.mendiane; i++)
        if (i == client->inventory.mendiane)
            response = strconcat(response, i, 4);
    for (int i = 0; i <= client->inventory.phiras; i++)
        if (i == client->inventory.phiras)
            response = strconcat(response, i, 5);
    for (int i = 0; i <= client->inventory.thystame; i++)
        if (i == client->inventory.thystame)
            response = strconcat(response, i, 6);
}

void format_inventory(client_t *client, char *response)
{
    strcpy(response, "[ ");
    for (int i = 0; i <= client->inventory.food; i++)
        if (i == client->inventory.food)
            response = strconcat(response, i, 0);
    for (int i = 0; i <= client->inventory.linemate; i++)
        if (i == client->inventory.linemate)
            response = strconcat(response, i, 1);
    for (int i = 0; i <= client->inventory.deraumere; i++)
        if (i == client->inventory.deraumere)
            response = strconcat(response, i, 2);
    format_inventory1(client, response);
    strcat(response, " ]\n");
}

char *inventory(client_t *client, __attribute__((unused)) server_t *server)
{
    int length = checksize(client);
    char *response;

    if (length == 0)
        response = malloc(sizeof(char) * 100);
    else
        response = malloc(sizeof(char) * 4096);
    format_inventory(client, response);
    return response;
}
