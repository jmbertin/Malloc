# Libft
Libft is a project undertaken as part of the 42 school curriculum. It's a C library that recreates certain standard functions from the libc, as well as a few additional and bonus functions that prove to be extremely useful for subsequent projects.

## Compilation
The library is compiled using the flags -Wall -Wextra -Werror. To compile, run:

``make``

To include the bonus functions, use:

``make bonus``

This will generate a libft.a library.

----

## Implemented Functions
### Basic Functions
**Memory manipulation**: ft_memset, ft_bzero, ft_memcpy, ft_memmove, ft_memchr, ft_memcmp

**String manipulation**: ft_strlen, ft_strchr, ft_strrchr, ft_strncmp, ft_strlcpy, ft_strlcat, ft_strnstr, ft_strdup, ft_strjoin, ft_split, ft_itoa, ft_substr, ft_strtrim, ft_strmapi, ft_striteri

**Character checks**: ft_isalpha, ft_isdigit, ft_isalnum, ft_isascii, ft_isprint

**Character conversion**: ft_toupper, ft_tolower

**Numeric conversion**: ft_atoi

**Memory allocation**: ft_calloc

**Writing**: ft_putchar_fd, ft_putnbr_fd, ft_putstr_fd, ft_putendl_fd, ft_printf

### Bonus Functions (linked list related)
**List manipulation**: ft_lstnew, ft_lstadd_front, ft_lstsize, ft_lstlast, ft_lstadd_back, ft_lstdelone, ft_lstclear, ft_lstiter, ft_lstmap

----

## Usage
To use this library in a project, include the appropriate header:

``#include "libft.h"``

When compiling your project, link the library:

``gcc your_file.c -L. -lft``

----

## Cleanup

**To remove the .o object files**:

``make clean``


**To remove both the object files and the compiled library**:

``make fclean``

**To recompile the library from scratch**:

``make re``

----

## Contribution
If you encounter any bugs or wish to add features, please feel free to open an issue or submit a pull request.
