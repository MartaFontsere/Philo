# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfontser <mfontser@student.42.barcel>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/06 12:21:16 by mfontser          #+#    #+#              #
#    Updated: 2024/11/19 02:59:13 by mfontser         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------COLORS------------------------------------------------------#

NC = \033[0m
GREEN = \033[1;92m
RED = \033[1;91m
CYAN = \e[1;96m
YELLOW = \e[1;93m
PURPLE =\e[1;95m
ORANGE =\e[1;38;2;255;128;0m

#------------------------------------------------VARIABLES---------------------------------------------------#

FILES =  philo.c parsing.c initialitations.c error_messages.c utils/utils.c  utils/atoi.c


SRCDIR = src/
SRCS = 	$(addprefix $(SRCDIR), $(FILES))

OBJDIR = obj/
OBJS = $(patsubst $(SRCDIR)%.c, $(OBJDIR)%.o, $(SRCS))

INCLUDES = -I ./inc

NAME = philo

HEADER = inc/philo.h
CC = cc 
RM = rm -rf 
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address


#--------------------------------------------------NORMAS----------------------------------------------------#

#Metodo implicito

$(OBJDIR)%.o: $(SRCDIR)%.c $(HEADER) Makefile  
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(GREEN)Compiling... $(END)$(patsubst $(DIR_BUILD)%,%,$@)"

# Mis metodos

all: ${NAME}

${NAME}: ${OBJS}
	@$(CC) $(CFLAGS) ${OBJS} -o $(NAME)
	@echo "$(RED)"
	@echo "			⢀⠔⠉⠉⠢⣀⠔⠉⠉⠹⣦⣄"
	@echo "			⡇⠀⠀⠀⠀⠀⠁⠀⠀ ⠀⣿⠇"
	@echo "			⠡⡀  $(CYAN)Philo$(END) $(RED)⣼⡟"
	@echo "			⠀⠈⠢⡀⠀⠀⠀⠀⢀⡾⠋"
	@echo "			⠀⠀⠀⠀⠙⠲⣦⠞⠋ $(END)"
	@echo "		$(NC)	⠀⠀⠀⠀⠀⠀⢸⠀⠀$(END)⠀$(YELLOW)⠀⠀⠀⠀⠀⢀⠠⠂⠉⣴⣿⠏⠀$(END)"
	@echo "		$(NC)	⠀⠀⠀⠀⠀⠀⢸⠀⠀$(END)⠀$(YELLOW)⠀⠀⠀⡠⠊⠀⢀⡤⠞⠛⠋⠉⣩⣿⡿$(END)"
	@echo "		$(NC)	⠀⠀⠀⠀⠀⠀⢸⠀⠀$(END)⠀$(YELLOW)⠀⡠⠊⠀⡠⠞⠁⠀⠀⣀⣴⣾⠟⠋$(END)"
	@echo "		$(NC)	⠀⠀⠀⠀⠀⠀⢸$(END)$(YELLOW)⡠⠒⠉⠁⠀⠀⣊⣀⣤⣴⠿⠛⠋⠁"
	@echo "			⠀⠀⠀⠀⠀⣠⠊⠀$(END)$(CYAN)♥$(END)⠀⠀$(YELLOW)⠀⠀⠀⢿⡆"
	@echo "			⠀⠀⠀⠀⠀⠙⣄⠀⠀⠀⠀⠀⠀⠀⣾⠇$(END)"
	@echo "		$(NC)	⠀⠀⠀⠀⠀⠀⢸$(END)$(YELLOW)⠳⢦⣄⡀⠀⠠⢴⣅$(END)"
	@echo "		$(NC)	⠀⠀⠀⠀⠀⠀⠸$(END)$(YELLOW)⠀⡔⠁⠀⠀⠀⠀⣀⣉⡻⢦"
	@echo "			⠀⠀⠀⠀⠀⠀⠀⠀⢁⠀⠀⠀⢀⡾⠉⠀⠀⠀⠻⡄"
	@echo "			⠀⠀⠀⠀⠀⠀⠀⠀⡘⠀⠀⠀⣿⠁⠀⠀⠀⠀⠀⠹⠦⣄"
	@echo "			⠀⠀⠀⠀⠀⠀⠀⣰⠁⠀⢀⣴⣿⡄⠀⠀⠀⠀⠀⣨⣤⡿"
	@echo "			⠀⠀⠀⠀⠀⠀⠀⠹⠶⠖⠋⠀⠈⠻⢶⣤⣤⣤⠞⠋"
	@echo "$(END)"

clean:
	@${RM} ${OBJDIR}
	@echo "$(RED)PHILO OBJECTS DELETED$(END)"

fclean:
	@${RM} ${OBJDIR}
	@echo "$(RED)PHILO OBJECTS DELETED$(END)"
	@${RM} ${NAME}
	@echo "$(RED) PHILO EXEC DELETED$(END)"

re: fclean all
	@echo "$(GREEN) PHILO RE DONE$(END)"

.PHONY: all clean fclean re
