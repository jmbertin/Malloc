ifeq ($(HOSTTYPE),)
HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

LIBNAME := libmalloc_$(HOSTTYPE).so
SYMLINK := libmalloc.so

SRC =	malloc.c \
		malloc_utils.c \
		free.c \
		free_utils.c \
		realloc.c \
		show_alloc_mem.c

LIBFT_A = libft.a
LIBFT_DIR = Libft/
LIBFT  = $(addprefix $(LIBFT_DIR), $(LIBFT_A))

OBJS = $(SRC:.c=.o)
DEPS = $(SRC:.c=.d)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fPIC
INCLUDE = -I includes/

all: $(LIBNAME)

$(LIBNAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	$(CC) -shared -o $(LIBNAME) $(OBJS) ${INCLUDE} $(LIBFT)
	ln -sf $(LIBNAME) $(SYMLINK)

%.o: %.c
	$(CC) $(CFLAGS) ${INCLUDE} -c $< -o $@
	$(CC) -MM $(CFLAGS) $< > $*.d

-include $(DEPS)

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -f ${OBJS} ${DEPS}
	@echo "\033[0;92m${LIBNAME} objects files cleaned.\033[0;39m"

fclean : clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f ${LIBNAME} ${SYMLINK}
	@echo "\033[0;92m${LIBNAME} cleaned.\033[0;39m"

re : fclean all
	@echo "\033[0;92m${LIBNAME} cleaned and rebuilded.\033[0;39m"

.PHONY: all clean fclean re
