/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** main
*/

#include "zappy_server.h"
#include <stdlib.h>

int main(int ac, char **av)
{
    server_t *server = malloc(sizeof(server_t));

    if (check_args(av, server) != 0 || ac == 1)
        return print_help();
    init_server(server);
    return zappy_server(server);
}