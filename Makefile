##
## EPITECH PROJECT, 2021
## Zappy
## File description:
## Makefile
##

all:
	make -s -C server/

clean:
	make clean -s -C server/

fclean: clean
	make fclean -s -C server/

re: fclean all

zappy_server:
	make -s -C server/

zappy_gui:
	make -s -C gui/

zappy_ai:
	make -s -C ai/

##tests_run:
##	$(MAKE) -C unit_tests/
##	cd unit_tests/ && ./test
##	gcovr

.PHONY: all clean fclean re zappy_server zappy_gui zappy_ai
