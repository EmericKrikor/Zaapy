/*
** EPITECH PROJECT, 2021
** cmd
** File description:
** cmd_H
*/

#ifndef CMD_H
#define CMD_H
#include <stdio.h>

/*
** Basic commands definition 
*/

char *basic_command_loop(client_t* client, server_t *server);
char *graphic_cmd(client_t *client, server_t *server);
char *forward(client_t *bs_player, server_t *server);
char *right(client_t *bs_player, server_t *server);
char *left(client_t *bs_player, server_t *server);
char *look_around(client_t *bs_player, server_t *server);
void format(server_t *server, char *response, position_t *position);
char *inventory(client_t *bs_player, server_t *server);
char *broadcast(client_t *bs_player, server_t *server);
char *connect_nbr(client_t *bs_player, server_t *server);
char *fork_(client_t *bs_player, server_t *server);
char *eject(client_t *bs_player, server_t *server);
char *take_object(client_t *bs_player, server_t *server);
char *set_object(client_t *bs_player, server_t *server);
char *incantation(client_t *bs_player, server_t *server);
char *tna(client_t *bs_player, server_t *server);
char *take_parse_suit1(client_t *client,  server_t *server);
char *take_parse_suit(client_t *client,  server_t *server);
char* set_object_suit(client_t *client,  server_t *server);
char* set_object_suit2(client_t *client,  server_t *server);

#endif /* !CMD_H */

