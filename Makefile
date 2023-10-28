CLIENT 		= client

SERVER 		= server

CC 			= cc

CFLAGS 		= -Wall -Werror -Wextra

CLIENT_SRC 	= src/client.c src/utils.c

SERVER_SRC 	= src/server.c src/utils.c

RM 			= rm -rf

all			: $(CLIENT) $(SERVER)

$(CLIENT)	:
	make all -C libft
	$(CC) $(CFLAGS) $(CLIENT_SRC) -I libft -L libft -l ft -o $(CLIENT)

$(SERVER)	:
	make all -C libft
	$(CC) $(CFLAGS) $(SERVER_SRC) -I libft -L libft -l ft -o $(SERVER)

clean		:
	make clean -C libft
	$(RM) $(CLIENT)
	$(RM) $(SERVER)

fclean		: clean
	make fclean -C libft

re			: fclean all
