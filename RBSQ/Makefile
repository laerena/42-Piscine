
NAME := bsq

SRCDIR := srcs
INCDIR := includes
OBJDIR := obj

SRCS := main.c solver.c check_array.c ft_split.c utils.c utils2.c parser.c solve.c grid_ut.c
SRC  := $(addprefix $(SRCDIR)/,$(SRCS))

OBJS := $(addprefix $(OBJDIR)/,$(SRCS:.c=.o))


CC := cc
CFLAGS := -Wall -Wextra -Werror -I$(INCDIR)


all: $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re