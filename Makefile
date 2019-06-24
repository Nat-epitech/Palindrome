##
## EPITECH PROJECT, 2018
## Makefile SBLM
## File description:
## SBLM makefile
##

NAME	= palindrome

SRC	=	$(wildcard src/*.c)

OBJ	=	$(SRC:.c=.o)

CFLAGS = -Iinclude/

CFLAGS += -Wall -Wextra --pedantic -g3

END         =   \033[0m
BOLD        =   \033[1m
GREY        =   \033[30m
RED         =   \033[31m
GREEN       =   \033[32m
BLINK       =   \033[32;5m
YELLOW      =   \033[33m
BLUE        =   \033[34m
PURPLE      =   \033[35m
CYAN        =   \033[36m
WHITE       =   \033[37m

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME) --pedantic $(CFLAGS)      \
	&& echo -e "$(BLUE)$(BOLD)*--|--|--* >= Successfully linked ! Binary name: \
	$(GREEN)$(NAME)$(END)$(BOLD)$(BLUE)$(END)"      \
	|| echo -e "$(RED)$(BOLD) error while linking$(END)"
	rm -f $(OBJ)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)      \
	&& echo -e "$(PURPLE)$(BOLD) ->  $(GREEN)$(BOLD)- Workspace cleaned -$(END)"

re: fclean all

%.o:    %.c
	@$(CC) $(LDFLAGS) -c $< -o $@ $(CFLAGS) $(LDLIBS)       \
	&& echo -e "$(PURPLE)$(BOLD) -> $(CYAN)[$(PURPLE)$(BOLD)Success$(END)$(CYAN)$(BOLD)]$(GREEN) $< $(CYAN): Done!$(END)"         \
	|| echo -e "$(RED)[ERROR] $(BOLD)$<: Failed to compile $< See error log above$(END)";

.PHONY: all clean fclean re
