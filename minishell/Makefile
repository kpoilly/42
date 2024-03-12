# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 16:11:15 by jdoukhan          #+#    #+#              #
#    Updated: 2024/03/07 13:05:14 by jdoukhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                     CONFIG                                   #
################################################################################

NAME = minishell
CFLAGS = -g3 -Wall -Wextra -Werror
CC = cc
URL = https://cdn.intra.42.fr/pdf/pdf/117082/en.subject.pdf

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

BUILT_INS = cd.c cd_utils.c echo.c env.c exit.c export.c pwd.c unset.c \
			built_ins.c \
			history.c history_utils.c help.c

PARSING = parse_envp.c prompt.c lexer.c expander.c expander_utils.c \
			set_underscore.c unex_token.c

UTILS = check_word.c dup_envp.c on_crash.c strtab_utils.c free_sh.c \
		ft_split_skip.c ft_split_skip_utils.c print_tabtab.c \
		split_redirects.c error_printing.c

ENV = set_env.c

PIPEX = fork.c heredocs.c path_parsing.c pipex.c printing.c utils.c \
		finput.c foutput.c

SOURCES = main.c main_flags.c signals.c \
	$(addprefix built-ins/, $(BUILT_INS)) \
	$(addprefix parsing/, $(PARSING)) \
	$(addprefix utils/, $(UTILS)) \
	$(addprefix pipex/, $(PIPEX)) \
	$(addprefix env/, $(ENV))

################################################################################
#                                  LIBFT Body                                  #
################################################################################

INCLUDES = -I./includes -I./minilibft
MINILIBFT_DIR = ./minilibft
MINILIBFT = $(MINILIBFT_DIR)/minilibft.a
MINILIBFT_FLAGS = -Lminilibft -lminilibft

################################################################################
#                                 Makefile Body                                #
################################################################################

SRCS = $(addprefix srcs/, $(SOURCES))
OBJS = $(SRCS:srcs/%.c=objs/%.o)

################################################################################
#                               Makefile Rules                                 #
################################################################################

all: $(MINILIBFT) $(NAME)

bonus: $(MINILIBFT) $(B_NAME)

objs/%.o : srcs/%.c
	@$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(B_NAME) : $(B_OBJS)
	@rm -rf $(NAME)
	@$(CC) $(B_SRCS) $(CFLAGS) $(MINILIBFT_FLAGS)  -o $(NAME) $(INCLUDES)
	@echo "\033[0;32mBonus part compiled ✔️\033[0m"

$(NAME) : $(OBJS)
	@$(CC) $(SRCS) $(CFLAGS) $(MINILIBFT_FLAGS) -o $(NAME) $(INCLUDES) -lreadline
	@echo "\033[0;32mMandatory part compiled ✔️\033[0m"

$(MINILIBFT):
	@mkdir -p objs/utils objs/built-ins objs/parsing objs/env objs/pipex
	@make -C $(MINILIBFT_DIR) --no-print-directory

clean:
	@rm -rf $(OBJS) $(B_OBJS)
	@echo "\033[0;33mCleaned .o files ✔️\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[0;91mCleaned exe ✔️\033[0m"

re: fclean all



subject.txt: 
	@curl $(URL) | pdftotext - subject.txt -layout -nopgbrk

read: subject.txt
	@bat subject.txt

.PHONY: all clean fclean re bonus pdf read
