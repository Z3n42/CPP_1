MAINDIR = mains
MVDIR = srcs/moves
MVLDIR = srcs/moves/moves_launcher
UTDIR = srcs/utils
SLDIR = srcs/solutions

SOURCES =	$(MAINDIR)/push_swap.c		\
			$(MAINDIR)/some_args.c		\
			$(MAINDIR)/unique_args.c	\
			$(MVDIR)/moves_p.c			\
			$(MVDIR)/moves_r.c			\
			$(MVDIR)/moves_rr.c			\
			$(MVDIR)/moves_s.c			\
			$(MVLDIR)/launch_p.c		\
			$(MVLDIR)/launch_r.c		\
			$(MVLDIR)/launch_rr.c		\
			$(MVLDIR)/launch_s.c		\
			$(UTDIR)/utils.c			\
			$(UTDIR)/ft_atoi_special.c	\
			$(SLDIR)/solutions.c		\
			$(SLDIR)/sol_three_nums.c	\
			$(SLDIR)/sol_five_nums.c	\
			$(SLDIR)/sol_hundred_nums.c	\
			$(SLDIR)/sol_hundred_two.c	\
			$(SLDIR)/sol_b.c			\

name =	push_swap

all:	
	$(MAKE) -C includes/libft
	$(MAKE) -C includes/ft_printf
	gcc	$(SOURCES) -Wall -Werror -Wextra includes/libft/libft.a includes/ft_printf/libftprintf.a -o $(name)
	
	
clean: 
	rm -rf push_swap.dSYM
	$(MAKE) fclean -C includes/libft
	$(MAKE) fclean -C includes/ft_printf
	
fclean:
	rm -rf $(name)
	rm -rf push_swap.dSYM
	$(MAKE) fclean -C includes/libft
	$(MAKE) fclean -C includes/ft_printf

.PHONY:
	all:
	gcc $(SOURCES) includes/push_swap.h includes/libft/libft.a includes/ft_printf/libftprintf.a -o $(name)
