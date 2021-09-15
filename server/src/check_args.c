/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** check arguments given at executable
*/

#include "zappy_server.h"
#include <unistd.h>
#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include <stdlib.h>

static char *tab[256];

char **get_names(char **av, int from)
{
    int to_get = 0;
    int from_ = ++from;
    char **dest;
    int i;

    for (; strncmp(av[from_], "-", 1) != 0; to_get++, from_++);
    dest = malloc(sizeof(char*) * (to_get + 1));
    if (!dest)
        exit(84);
    for (i = 0; i != to_get; i++) {
        dest[i] = strdup(av[from + i]);
        if (!dest[i])
            exit(84);
    }
    dest[i] = NULL;
    return dest;
}

static void set_ressources(server_t *server)
{
    if (!tab[(int)'p'] || !tab[(int)'x'] || !tab[(int)'y'] ||
    !tab[(int)'n'] || !tab[(int)'c'] || !tab[(int)'f']) {
        print_help();
        exit(0);
    }
    server->infos.port = atoi(tab[(int)'p']);
    server->infos.width = atoi(tab[(int)'x']);
    server->infos.height = atoi(tab[(int)'y']);
    server->infos.client_per_team = atoi(tab[(int)'c']);
    server->infos.freq = atoi(tab[(int)'f']);
}

int check_args(char **av, server_t *server)
{
    int i = 0;

    for (i = 0; av[i]; i++) {
        if (strcmp(av[i], "-p") == 0)
            tab[(int)'p'] = strdup(av[i + 1]);
        if (strcmp(av[i], "-x") == 0)
            tab[(int)'x'] = strdup(av[i + 1]);
        if (strcmp(av[i], "-y") == 0)
            tab[(int)'y'] = strdup(av[i + 1]);
        if (strcmp(av[i], "-c") == 0)
            tab[(int)'c'] = strdup(av[i + 1]);
        if (strcmp(av[i], "-f") == 0)
            tab[(int)'f'] = strdup(av[i + 1]);
        if (strcmp(av[i], "-n") == 0) {
            tab[(int)'n'] = strdup(av[i + 1]);
            server->infos.name_tab = get_names(av, i);
        }
    }
    set_ressources(server);
    return 0;
}