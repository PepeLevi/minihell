NAME		=	libft.a
INCLUDES	=	../include
SRCS_DIR 	=	src/
OBJS_DIR	=	obj/
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -I
RM			=	rm -f
AR			=	ar rcs

SRC_FILES = ft_atoi ft_bzero ft_calloc ft_isalnum ft_isalpha \
ft_isascii ft_isdigit ft_isprint ft_itoa ft_memchr \
ft_memcmp ft_memcpy ft_memmove ft_memset ft_putchar_fd \
ft_putendl_fd ft_putnbr_fd ft_putstr_fd ft_split ft_strchr \
ft_strdup ft_striteri ft_strjoin ft_strlcat ft_strlcpy \
ft_strlen ft_strmapi ft_strncmp ft_strnstr ft_strrchr ft_strtrim \
ft_substr ft_tolower ft_toupper

SRCS 		= 	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS 		= 	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJSF		=	.cache_exists

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(AR) $(NAME) $(OBJS)
			@ranlib $(NAME)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c | $(OBJSF)
			@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJSF):
			@mkdir -p $(OBJS_DIR)

clean:
			@$(RM) -rf $(OBJS_DIR)
			@$(RM) -f $(OBJSF)

fclean:		clean
			@$(RM) -f $(NAME)

re:			fclean all