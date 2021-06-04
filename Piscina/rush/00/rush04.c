#include<stdio.h>
void	ft_putchar(char c);

void	print_top_bottom(int x, char left, char middle, char right)
{
	if (x-- >= 1)
	{
		ft_putchar(left);
		while (x-- >= 2)
		{
			ft_putchar(middle);
		}
		ft_putchar(right);
		ft_putchar('\n');
	}
}

void	print_middle(int x, int y, char limit)
{
	int	i;

	while (y-- > 2)
	{
		ft_putchar(limit);
		i = 2;
		while (x > i++)
		{
			ft_putchar(' ');
		}
		ft_putchar(limit);
		ft_putchar('\n');
	}
}

void	rush(int x, int y)
{
	if (y >= 1)
	{
		print_top_bottom(x, 'A', 'B', 'C');
	}
	print_middle(x, y, 'B');
	if (y >= 2)
	{
		print_top_bottom(x, 'C', 'B', 'A');
	}
}
