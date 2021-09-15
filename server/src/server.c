/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** Server
*/

#include "zappy_server.h"
#include "raise.h"
#include <stdio.h>

void init_connections(server_t *server)
{
    server->con = malloc(sizeof(connection_t));
    server->con->max_clients = FD_SETSIZE;
    server->con->max_sock = FD_SETSIZE;
    server->con->socket_list = malloc(sizeof(int) * FD_SETSIZE);
    server->con->client_list = malloc(sizeof(client_t*) * FD_SETSIZE);
    memset(server->con->buf, '\0', 1024);
    for (int i = 0; i != FD_SETSIZE; i++) {
        server->con->client_list[i] = malloc(sizeof(client_t));
        init_client(server->con->client_list[i], server->infos);
        server->con->client_list[i]->team_name = NULL;
        server->con->socket_list[i] = 0;
    }
    server->con->socket_list[0] = server->sockfd;
    server->con->nb_connected = 1;
}

void init_server(server_t *server)
{
    server->sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    server->my_addr.sin_family = AF_INET;
    server->my_addr.sin_port = htons(server->infos.port);
    server->my_addr.sin_addr.s_addr = INADDR_ANY;
    server->sin_size = sizeof(struct sockaddr_in);
    if (bind(server->sockfd, (struct sockaddr*) &server->my_addr,
        sizeof(server->my_addr)) != 0)
        raise("error on binding");
    if (listen(server->sockfd, FD_SETSIZE) != 0)
        raise("error on listening");
    server->map.tilemap = map_generate(server->infos);
    init_connections(server);
}

void initteams_slot(server_t *server)
{
    int length = 0;

    for(; server->infos.name_tab[length] != NULL; length++);
    server->infos.teams_length = length;
    server->infos.teams_slots = malloc(sizeof(int) * length + 1);
    for (int i = 0; i != length; i++)
        server->infos.teams_slots[i] = server->infos.client_per_team;
}

void initfirst_slot(client_t **client)
{
    for (int i = 0; i != FD_SETSIZE; i++)
        client[i]->cheksock = 0;
}

int zappy_server(server_t *server)
{
    initteams_slot(server);
    initfirst_slot(server->con->client_list);
    while (1) {
        check_connections(server, server->con->client_list);
    }
    return 0;
}