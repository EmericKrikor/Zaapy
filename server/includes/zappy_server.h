/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** Zappy server header file
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <string.h>
#include <time.h>
#include "map.h"

#ifndef ZAPPY_SERVER_H_
#define ZAPPY_SERVER_H_

typedef enum e_facing {
    NORTH,
    EAST,
    SOUTH,
    WEST
} facing_e;

typedef struct s_chrono {
    float action_cooldown;
    struct timespec cooldown_start;
    struct timespec cooldown_dest;
} chrono_t;

typedef struct s_vector {
    int x;
    int y;
} vector_t;

typedef struct position_s {
    int x;
    int y;
    int n;
    int tpos;
    int epos;
} position_t;

typedef struct items_s
{
    int food;
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
} items_t;

typedef struct s_client {
    int socket;
    int id;
    char *tagname;
    char *team_name;
    char *buffer;
    char *response;
    char **arg;
    bool cheksock;
    vector_t pos;
    items_t inventory;
    chrono_t egg;
    chrono_t incantation;
    int level;
    facing_e facing;
    bool first_co;
    float action_cooldown;
    struct timespec cooldown_start;
    struct timespec cooldown_dest;
    chrono_t chrono;
} client_t;

typedef struct s_connection {
    int nb_connected;
    int max_clients;
    int max_sock;
    int *socket_list;
    client_t **client_list;
    ssize_t readed;
    char buf[1024];
} connection_t;

typedef struct s_general_informations {
    int port;
    int width;
    int height;
    char **name_tab;
    char **teams_name;
    int teams_length;
    int *teams_slots;
    int client_per_team;
    int freq;
} infos_t;

typedef struct s_server {
    infos_t infos;
    connection_t *con;
    map_t map;
    int sockfd;
    struct sockaddr_in my_addr;
    fd_set readfds;
    socklen_t sin_size;
    bool find_cmd;
} server_t;

/*
** Core functions for zappy server
*/

void init_server(server_t *server);
int zappy_server(server_t *server);
void check_connections(server_t *server, client_t **client);
void execcmd(server_t *server, client_t *client, int i);
void init_client(client_t *client, infos_t infos);

/*
** Map general functions
*/

tile_t **map_generate(infos_t infos);

tile_t get_tile_infos(client_t client, tile_t **tilemap);

tile_t *get_tiles_vision_field_infos(client_t client, tile_t **tilemap,
facing_e facing, infos_t infos);

void send_map_to_gui(server_t *server);

char *get_map(tile_t **tilemap, infos_t infos);

/*
** Usage and argument management function
*/

int print_help(void);
int check_args(char **av, server_t *server);

/*
** Time functions for cooldown management between clients requests
*/

bool is_cooldown_ready(client_t *client);
void reset_cooldown(client_t *client);
void set_cooldown(client_t *client, infos_t infos, float cooldown);

/*
** Chrono functions works like Time functions
*/

void init_chrono(chrono_t *chrono);
bool chrono_is_cooldown_ready(chrono_t *chrono);
void chrono_start(chrono_t *chrono);
void chrono_set_cooldown(chrono_t *chrono, infos_t infos, float cooldown);

/*
** String manipulation functions
*/

char **my_str_to_wordtab(char *str);
char *strip_copy(const char *s);
char *concat_tab(const char **tab);

#endif /* !ZAPPY_SERVER_H_ */