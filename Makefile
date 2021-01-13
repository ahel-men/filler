NAME	=	ahel-men.filler

CFLAGS	=	-Werror -Wextra -Wall

FUNCTIONS	=	file_conditions.c\
				main.c\
				ft_rescue_memory.c\
				look_4_zero.c\
				solve.c\
				ft_fill_map_with_zeros.c\
				ft_stock_asterisks_dimentions.c\
				ft_hit_map.c\
				ft_store.c\
				parse_file.c

HEADERS	=		inc/filler.h

OBJDIR	=		obj

SRCDIR	=		src

OBJS	=		$(addprefix $(OBJDIR)/,$(FUNCTIONS:%.c=%.o))

LFT		= 		libft/libft.a

all :			$(NAME)

$(OBJDIR)/%.o : $(SRCDIR)/%.c $(HEADERS)
				@echo "\033[32m\033[1m"
				@gcc $(CFLAGS) -c $< -I./inc -o $@

$(OBJDIR):
				@mkdir $(OBJDIR)

$(LFT):
				@make -C libft

$(NAME) :		$(LFT) $(OBJDIR) $(OBJS)
				@gcc $(CFLAGS) $(LFT) $(OBJS) -o $(NAME)
				@echo "MAKEFILE FILLER...[OK]"

clean :
				@make clean -C libft
				@rm -rf $(OBJDIR)
				@echo "\033[41m\033[39m\033[1mRemoving FILLER objects...[OK]\033[49m\033[93m"

fclean :		clean
				@make fclean -C libft
				@rm -rf $(NAME)

re :			fclean all
