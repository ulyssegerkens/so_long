# Variables
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
CFLAGS			+=	-Iinclude -Isrc -O3
RM				=	rm -rf
SO_LONG			=	so_long
SO_LONG_BONUS	=	so_long_bonus
NAME			=	$(SO_LONG)

################################################################################

# Libraries
LIBFT_DIR		=	lib/libft
GNL_DIR			=	lib/get_next_line
FT_PRINTF_DIR	=	lib/ft_printf
CFLAGS			+=	-I $(LIBFT_DIR)/include -I $(GNL_DIR)/include -I $(FT_PRINTF_DIR)/include
LIBS			=	$(LIBFT_DIR)/libft.a $(GNL_DIR)/get_next_line.a $(FT_PRINTF_DIR)/ft_printf.a

MAKE_LIB		=	make --no-print-directory -C

MLX				=	libmlx42.a
MLX_DIR			=	lib/MLX42
MLX_FILE		=	$(MLX_DIR)/build/$(MLX)
CFLAGS			+=	-I $(MLX_DIR)/include/MLX42
LDFLAGS			=	-framework Cocoa -framework OpenGL -framework IOKit

################################################################################

# Source and Object Files
VPATH			=	src:src/events:src/graphics:src/so_long:src/map:include
INC				=	data.h so_long.h events.h graphics.h map.h
SRC				=	main.c data.c \
					init_map.c map_utils.c import_map.c import_map_utils.c map_valididy.c map_valid_path.c \
					events.c move.c move_to_block.c move_utils.c \
					display_game.c init_assets.c animation.c status_bar.c end_game.c mlx_facades.c graphics_utils.c
VPATH			+=	src_bonus:src_bonus/events_bonus:src_bonus/graphics_bonus:src_bonus/so_long_bonus:src_bonus/map_bonus:include_bonus
SRC_B			=	main.c data.c \
					init_map.c map_utils.c import_map.c import_map_utils_bonus.c map_valididy.c map_valid_path.c \
					events.c move.c move_to_block.c move_utils.c \
					display_game.c init_assets.c animation.c status_bar.c end_game.c mlx_facades.c graphics_utils.c

OBJ_DIR			=	obj
OBJ_DIR_BONUS	=	obj_bonus

SO_LONG_OBJ		=	$(SRC:%.c=obj/%.o)
SO_LONG_BONUS_OBJ =	$(SRC_B:%.c=obj/%.o)

################################################################################

# Rules
all:			$(SO_LONG)

bonus:			$(SO_LONG_BONUS)

obj:
				mkdir -p obj

$(OBJ_DIR)/%.o: %.c $(INC)
				mkdir -p $(dir $@)
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR_BONUS)/%.o: %.c $(INC)
				mkdir -p $(dir $@)
				$(CC) $(CFLAGS) -c $< -o $@

$(LIBS):
				$(MAKE_LIB) $(@D)

$(MLX_FILE): 	$(MLX_DIR)/sentinel

$(MLX_DIR)/sentinel:
				cmake $(MLX_DIR) -B $(MLX_DIR)/build > /dev/null 2>&1
				make -C $(MLX_DIR)/build -j4 > /dev/null 2>&1
				touch $(MLX_DIR)/sentinel

$(SO_LONG):		$(SO_LONG_OBJ) $(LIBS) $(MLX_FILE)
				$(CC) $(CFLAGS) $(LDFLAGS) $(LIBS) $(MLX_FILE) -ldl -Llib/glfw/lib -lglfw -pthread -lm $(SO_LONG_OBJ) -o $@

$(SO_LONG_BONUS):	$(SO_LONG_BONUS_OBJ) $(LIBS) $(MLX_FILE)
				$(CC) $(CFLAGS) $(LDFLAGS) $(LIBS) $(MLX_FILE) -ldl -Llib/glfw/lib -lglfw -pthread -lm $(SO_LONG_BONUS_OBJ) -o $@

lib_clean:
				$(MAKE_LIB) $(LIBFT_DIR) clean
				$(MAKE_LIB) $(GNL_DIR) clean
				$(MAKE_LIB) $(FT_PRINTF_DIR) clean
				$(RM) $(MLX_DIR)/sentinel

lib_fclean:
				$(MAKE_LIB) $(LIBFT_DIR) fclean
				$(MAKE_LIB) $(GNL_DIR) fclean
				$(MAKE_LIB) $(FT_PRINTF_DIR) fclean
				$(RM) $(MLX_DIR)/build
				$(RM) $(MLX_DIR)/sentinel

clean:			lib_clean
				$(RM) $(OBJ_DIR) $(OBJ_DIR_BONUS)

fclean:			clean lib_fclean
				$(RM) $(SO_LONG) $(SO_LONG_BONUS)

re:				fclean all

.SILENT:

.PHONY:			all lib_clean lib_fclean clean fclean re bonus

###############################################################
