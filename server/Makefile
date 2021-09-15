##
## EPITECH PROJECT, 2021
## Zappy
## File description:
## Server Makefile
##

CC	=	gcc -Iincludes

NAME	=	zappy_server

SRCS	=	src/main.c 						 \
			src/server.c					 \
			src/clientcmd_exec.c			 \
			src/connections.c				 \
			src/print_help.c				 \
			src/check_args.c				 \
			src/string/strtwa.c				 \
			src/string/strip_copy.c			 \
			src/string/concat_tab.c			 \
			src/commands/basic_commands.c 	 \
			src/commands/direction.c         \
			src/commands/look.c				 \
			src/commands/look_2.c			 \
			src/commands/inventory.c         \
			src/map/map_generator.c			 \
			src/map/get_tile_infos.c		 \
			src/commands/teams_connect_cmd.c \
			src/commands/object.c            \
			src/commands/take_obj.c 		 \
			src/time/time.c					 \
			src/send_map_to_gui.c			 \

OBJS	=	$(SRCS:.c=.o)

CFLAGS += 

INCLUDES += -I includes/

all:	$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(CFLAGS)
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re