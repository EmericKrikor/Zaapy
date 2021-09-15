/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** exec de cmd
*/

#include "zappy_server.h"
#include "commands.h"
#include "raise.h"
#include <string.h>
#include <unistd.h>

char *initteam(client_t *client, server_t *server)
{
    char *socket = malloc(sizeof(char) * 1024);
    bool checkname = false;

    for (int i = 0; i != server->infos.teams_length; i++) {
        if (strcmp(client->team_name,  server->infos.name_tab[i]) == 0) {
            sprintf(socket, "%d\n", server->infos.teams_slots[i]);
            if (server->infos.teams_slots[i] != 0)
                server->infos.teams_slots[i] -= 1;
            checkname = true;
            break;
        }
    }
    return checkname == true ? socket : strdup("ko\n");
}

void init_player_co(server_t *server, client_t *client)
{
    char *socket = malloc(sizeof(char) * 1024);
    char mappos[1024];
    char *map;

    if (strcmp(strip_copy(server->con->buf), "GraphicClient") == 0) {
        client->tagname = strdup("Graph");
        client->cheksock = true;
        sprintf(socket, "%d %d\n", server->infos.width, server->infos.height);
        send(client->socket, socket, strlen(socket), 0);
        map = get_map(server->map.tilemap, server->infos);
        printf("gui socket is: %d\n", client->socket);
        send(client->socket, map, strlen(map), NULL);
    } else
        client->tagname = strdup("IA");
    if (strcmp(client->tagname, "IA") == 0) {
        client->team_name = strip_copy(server->con->buf);
        socket = initteam(client, server);
        sprintf(mappos, "%d %d\n", server->infos.width, server->infos.height);
        send(client->socket, socket, strlen(socket), 0);
        if (strcmp(socket, "ko\n") != 0) {
            send(client->socket, mappos, strlen(mappos), 0);
            client->cheksock = true;
        }
    }
    free(socket);
}

void execcmd(server_t *server, client_t *client, int i)
{
    char *response = NULL;

    client->socket = server->con->socket_list[i];
    printf("Clien socket is %d\n", client->socket);
    printf("Cheksock %d\n", client->cheksock);
    if (client->cheksock == false)
        init_player_co(server, client);
    else {
        if (strcmp(client->tagname, "IA") == 0) {
            client->buffer = server->con->buf;
            response = basic_command_loop(client, server);
            send(client->socket, response, strlen(response), 0);
            bzero(server->con->buf, 1024);
            free(response);
            client->response = NULL;
            send_map_to_gui(server);
        } else {
            client->buffer = server->con->buf;
            response = graphic_cmd(client, server);
            send(client->socket, response, strlen(response), 0);
            bzero(server->con->buf, 1024);
            free(response);
            client->response = NULL;
        }
    }
    bzero(server->con->buf, strlen(server->con->buf));
}