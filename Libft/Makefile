SRCS	= 	ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strlen.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_split.c \
			ft_itoa.c \
			ft_substr.c \
			ft_strtrim.c \
			ft_strmapi.c \
			ft_putchar_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_striteri.c \
			ft_printf.c \
			ft_printf_utils.c

SRCS_BONUS	=	ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c

NAME	= libft.a
OBJS	= ${SRCS:.c=.o}
BONUS_OBJS	= ${SRCS_BONUS:.c=.o}
FLAGS	= -Wall -Wextra -Werror -fPIC

.c.o	:
		@gcc $(FLAGS) -c -I . $< -o ${<:.c=.o}
		@echo "\033[0;93mCompiling : $< \033[0;39m"

${NAME}	: ${OBJS}
		@ar rc ${NAME} ${OBJS}
		@ranlib ${NAME}
		@echo "\033[0;92mLibft successfully compiled.\033[0;39m"

all : ${NAME}

clean :
		@rm -f ${OBJS}
		@rm -f ${BONUS_OBJS}
		@echo "\033[0;92m.o files cleaned.\033[0;39m"

fclean : clean
		@rm -f ${NAME}
		@echo "\033[0;92mLibft cleaned.\033[0;39m"

re : fclean all
		@echo "\033[0;92mCleaned and rebuilded.\033[0;39m"

bonus :	${OBJS} ${BONUS_OBJS}
		@ar rc ${NAME} ${OBJS} ${BONUS_OBJS}
		@ranlib ${NAME}
		@echo "\033[0;92mBonus added to Libft successfully.\033[0;39m"
