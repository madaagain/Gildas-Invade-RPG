##
## EPITECH PROJECT, 2023
## MyRPG
## File description:
## Makefile
##

CC ?=	gcc
SRC = 	source/display/window.c \
		source/display/view.c\
		source/display/destroy_gamestate.c\
		source/sprites/initialise.c \
		source/map/initalise.c \
		source/map/draw.c \
		source/map/free_map.c \
		source/map/get_level_path.c\
		source/map/load_level.c\
		source/map/get_size.c\
		source/map/traps.c\
		source/map/trap_assign_damage.c\
		source/player/draw_player.c\
		source/player/init_player.c\
		source/npc/position_npc.c	\
		source/npc/draw_npc.c	\
		source/npc/attack_npc.c	\
		source/npc/bouncing.c\
		source/npc/initiate_npc.c	\
		source/npc/type.c	\
		source/npc/mobs_list.c	\
		source/npc/npc_management.c	\
		source/npc/animation_npc.c\
		source/entity/free_entity.c\
		source/movements/collision.c\
		source/movements/collision_separate_file.c\
		source/movements/check_move.c\
		source/event/manage_event.c\
		source/event/interact.c\
		source/event/door.c\
		source/event/is_door.c\
		source/event/check.c\
		source/event/chest_event.c\
		source/fight/collid_hitbox.c\
		source/fight/get_utils.c\
		source/fight/hit_system.c\
		source/menu/menu.c	\
		source/menu/init_button.c	\
		source/menu/update_buttons.c	\
		source/menu/options.c	\
		source/menu/init_menu.c	\
		source/menu/init_opt_buttons.c	\
		source/menu/update_options.c	\
		source/hud/hud.c	\
		source/fight/sword.c\
		source/fight/bow.c\
		source/fight/initialisation.c\
		source/fight/anim_weapon.c\
		source/ig_menu/ig_menu.c	\
		source/ig_menu/ig_addons.c	\
		source/ig_menu/init_ig_menu.c	\
		source/save/save.c	\
		source/save/save_addons.c	\
		source/menu/game_over.c	\

OBJ = $(SRC:.c=.o)

MAIN = source/main.c

NAME = my_rpg

EXEC = ./$(NAME)

VALGRIND_PARAMS ?= '-h'

CFLAGS = -Wall -Wextra
CPPFLAGS = -iquote include
LDFLAGS = -L/lib -lmy -lcsfml-graphics -lcsfml-window \
		  -lcsfml-system -lcsfml-audio

LIB 	=	-lmy -lm

DIR	=	-L./lib/

MKDIR = mkdir -p

all: $(NAME)


$(NAME): 	SRC += $(MAIN)
$(NAME): 	$(OBJ) $(MAIN:.c=.o)
			$(MAKE) -C ./lib/my
			$(CC) $(OBJ) -o $(NAME) $(DIR) $(LIB) $(LDFLAGS) $(CFLAGS)

clean:
		$(RM) $(OBJ) $(MAIN:.c=.o)
		$(MAKE) clean -C ./lib/my

fclean: clean
		$(RM) $(NAME) vgcore*
		$(MAKE) fclean -C ./lib/my

re: fclean
	$(MAKE) all

debug: CFLAGS += -g
debug: re

valgrind: 	re
			valgrind $(EXEC) $(VALGRIND_PARAMS)

.PHONY: all lib clean fclean re valgrind
