# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/05 16:33:45 by cagonzal          #+#    #+#              #
#    Updated: 2022/05/24 12:24:51 by cagonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = $(MAIN_SRC) $(SRC_MAP) $(SRC_GAME)

MAIN_SRC = main.c errors.c

LIBFT_A = libft.a
LIBF_DIR = libft/
LIBFT  = $(addprefix $(LIBF_DIR), $(LIBFT_A))

MAP = 	map_reader.c map_checker.c map_checker_utils.c \
		tilemap_generator.c enemy_generator.c
SRC_MAP = $(addprefix map/, $(MAP))

GAME =	game_init.c open_images.c open_wall_images.c open_panel.c \
		input.c player_movement.c player_end.c update.c enemy_behaviour.c  follower_behaviour.c \
		render.c draw_wall.c reset.c end_program.c
SRC_GAME = $(addprefix game/, $(GAME))

OBJ = ${MAIN_SRC:.c=.o} ${MAP:.c=.o} ${GAME:.c=.o}

FLAGS = -Wall -Wextra -Werror
INCLUDE = -lmlx -framework OpenGL -framework AppKit

# Color Aliases
NONE	= '\033[0m'
DEFAULT	= '\033[0;39m'
GRAY	= '\033[2;37m'
RED		= '\033[0;91m'
GREEN	= '\033[32m'
YELLOW	= '\033[33m'
BLUE	= '\033[0;94m'
MAGENTA	= '\033[0;95m'
CYAN	= '\033[0;96m'
WHITE	= '\033[0;97m'
CURSIVE	= '\033[3m'

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(CURSIVE)$(GRAY) "     - Making libft..." $(NONE)
	@make -C $(LIBF_DIR)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@gcc $(FLAGS) $(OBJ) $(LIBFT) $(INCLUDE) -o $(NAME)
	@echo $(GREEN)"- Compiled -"$(NONE)

$(OBJ): $(SRC)
	@echo $(CURSIVE)$(GRAY) "     - Making object files..." $(NONE)
	@gcc $(FALGS) -c $(SRC)

play0: all
	@echo $(YELLOW)"     - Playing Map 0... \n"$(NONE)
	@make -C ./ clean
	@./$(NAME) map_files/map_0.ber

play1: all
	@echo $(YELLOW)"     - Playing Map 1... \n"$(NONE)
	@make -C ./ clean
	@./$(NAME) map_files/map_1.ber
	
play2: all
	@echo $(YELLOW)"     - Playing Map 2... \n"$(NONE)
	@make -C ./ clean
	@./$(NAME) map_files/map_2.ber
	
play3: all
	@echo $(YELLOW)"     - Playing Map 3... \n"$(NONE)
	@make -C ./ clean
	@./$(NAME) map_files/map_3.ber
	
play4: all
	@echo $(YELLOW)"     - Playing Map 4... \n"$(NONE)
	@make -C ./ clean
	@./$(NAME) map_files/map_4.ber
	
play5: all
	@echo $(YELLOW)"     - Playing Map 5... \n"$(NONE)
	@make -C ./ clean
	@./$(NAME) map_files/map_5.ber
	
play6: all
	@echo $(YELLOW)"     - Playing Map 6... \n"$(NONE)
	@make -C ./ clean
	@./$(NAME) map_files/map_6.ber
	
play42: all
	@echo $(YELLOW)"     - Playing Map 42... \n"$(NONE)
	@make -C ./ clean
	@./$(NAME) map_files/map_42.ber
	
playb: all
	@echo $(YELLOW)"     - Playing Big Map... \n"$(NONE)
	@make -C ./ clean
	@./$(NAME) map_files/big.ber
	
playm: all
	@echo $(YELLOW)"     - Playing Min Map... \n"$(NONE)
	@make -C ./ clean
	@./$(NAME) map_files/min.ber
	
test: all
	@echo $(YELLOW)"     - Invalid test... \n"$(NONE)
	@make -C ./ clean
	@./$(NAME) map_files/invalid.ber
	
playall: all
	@echo $(YELLOW)"     - Playing all maps... \n"$(NONE)
	@make -C ./ clean
	@./$(NAME) map_files/map_0.ber
	@./$(NAME) map_files/map_1.ber
	@./$(NAME) map_files/map_2.ber
	@./$(NAME) map_files/map_3.ber
	@./$(NAME) map_files/map_4.ber
	@./$(NAME) map_files/map_5.ber
	@./$(NAME) map_files/map_6.ber

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@rm -rf $(OBJ)
	@make -C $(LIBF_DIR) clean

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@rm -rf $(NAME)
	@make -C $(LIBF_DIR) fclean
	@echo $(GREEN)"- Cleaned -"$(NONE)

re: fclean all