CFLAGS = -Wall -Wextra -Werror
REMOVE = rm -rf
SERVER = server
CLIENT = client

SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

HEADER = minitalk.h
TOOLS = tools.c
NAME = $(SERVER) $(CLIENT)

.PHONY: all clean fclean re bonus

all: $(NAME)

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)


$(SERVER): server.c $(TOOLS) $(HEADER)
	$(CC) $(CFLAGS) server.c $(TOOLS) -o $(SERVER)

$(CLIENT): client.c $(TOOLS) $(HEADER)
	$(CC) $(CFLAGS) client.c $(TOOLS) -o $(CLIENT)

$(SERVER_BONUS): server_bonus.c $(TOOLS) $(HEADER)
	$(CC) $(CFLAGS) server_bonus.c $(TOOLS) -o $(SERVER_BONUS)

$(CLIENT_BONUS): client_bonus.c $(TOOLS) $(HEADER)
	$(CC) $(CFLAGS) client_bonus.c $(TOOLS) -o $(CLIENT_BONUS)

clean:
	$(REMOVE) $(CLIENT)
	$(REMOVE) $(SERVER)

fclean:
	$(REMOVE) $(CLIENT_BONUS)
	$(REMOVE) $(SERVER_BONUS)

re: fclean all