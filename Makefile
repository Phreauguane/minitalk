CLIENT	=	client

SERVER	=	server

FLAG		=	-Wall -Wextra -Werror

LIBFT_PATH	=	./libft/

LIBFT_FILE	=	libft.a

LIBFT_LIB	=	$(addprefix $(LIBFT_PATH), $(LIBFT_FILE))

CLI_SRC		=	src/client.c src/utils.c

SRV_SRC		=	src/server.c src/utils.c

all: lib $(CLIENT) $(SERVER)
	@echo "\033[0;33m\nCOMPILING MINITALK..."

lib:
	@echo "\033[0;33m\nCOMPILING $(LIBFT_PATH)"
	@make -C $(LIBFT_PATH)
	@echo "\033[1;32m$(LIBFT_FILE) created"

$(CLIENT):
	@cc $(FLAGS) -I libft $(CLI_SRC) $(LIBFT_LIB) -o $(CLIENT)
	@echo "\033[1;32m$(CLIENT) executable created"

$(SERVER):
	@cc $(FLAGS) -I libft $(SRV_SRC) $(LIBFT_LIB) -o $(SERVER)
	@echo "\033[1;32m$(SERVER) executable created"

clean:
	@echo "\033[0;31mDeleting objects in $(LIBFT_PATH)..."
	@make clean -sC $(LIBFT_PATH)
	@echo "\033[1;32mDone"

fclean: clean
	@echo "\033[0;31mDeleting executables..."
	@rm -f $(CLIENT) $(SERVER)
	@make fclean -C $(LIBFT_PATH)
	@echo "\033[1;32mDone"

re: fclean all

.PHONY: all clean fclean re