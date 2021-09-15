/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** Check for new connections
*/

#include "zappy_server.h"
#include "commands.h"
#include "raise.h"
#include <string.h>
#include <unistd.h>

#define WELCOME "WELCOME\n"

void init_client(client_t *client, infos_t infos)
{
    client->response = NULL;
    client->arg = NULL;
    client->buffer = NULL;
    client->id = 0;
    client->level = 1;
    client->facing = NORTH;
    client->action_cooldown = 0.0;
    client->pos = (vector_t) {rand() % infos.width, rand() % infos.height};
    reset_cooldown(client);
    client->inventory = (items_t) {0, 0, 0, 0, 0, 0, 0};
    set_cooldown(client, infos, 0.0);
    client->cheksock = 0;
}

void send_recv(server_t *server, client_t **client)
{
    for (size_t i = 1; i != FD_SETSIZE; i++) {
        if (FD_ISSET(server->con->socket_list[i], &server->readfds) &&
        (server->con->readed = recv(server->con->socket_list[i],
        &server->con->buf, 1024, 0) <= 0)) {
            close(server->con->socket_list[i]);
            server->con->socket_list[i] = 0;
            bzero(server->con->buf, 1024);
        } else if (FD_ISSET(server->con->socket_list[i], &server->readfds))
            execcmd(server, client[i], i);
    }
}

void select_connexion(server_t *server, client_t **client, int tmp_fd,
struct sockaddr_in *client_struct)
{
    if (select(server->con->max_sock + 1,
        &server->readfds, NULL, NULL, NULL) == -1)
        raise("Error while getting new client");
    if (FD_ISSET(server->sockfd, &server->readfds)) {
        if ((tmp_fd = accept(server->sockfd,
        (struct sockaddr*) &client_struct, &server->sin_size)) == -1)
            exit(84);
        init_client(client[server->con->nb_connected - 1], server->infos);
        client[server->con->nb_connected - 1]->socket = tmp_fd;
        printf("Client sockfd: %d\n", tmp_fd);
        send(tmp_fd, WELCOME, strlen(WELCOME), 0);
        server->con->nb_connected++;
        server->con->socket_list[server->con->nb_connected - 1] = tmp_fd;
    }
    send_recv(server, client);
}

void check_connections(server_t *server, client_t **client)
{
    int tmp_fd = 0;
    struct sockaddr_in client_struct;

    FD_ZERO(&server->readfds);
    for (int i = 0; i != server->con->max_clients; i++) {
        if (server->con->socket_list[i] != 0)
            FD_SET(server->con->socket_list[i], &server->readfds);
        if (server->con->max_sock <= server->con->socket_list[i])
            server->con->max_sock = server->con->socket_list[i];
    }
    select_connexion(server, client, tmp_fd, &client_struct);
}