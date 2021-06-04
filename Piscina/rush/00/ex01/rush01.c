void	ft_putchar(char c);

void	print_top_bottom(int x, char left, char middle, char right)
{
	int	i;

	i = 1;
	ft_putchar(left);
	while (i < x - 1)
	{
		ft_putchar(middle);
		i++;
	}
	ft_putchar(right);
	ft_putchar('\n');
}

void	print_middle(int x, int y, char side)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (i < y - 1)
	{
		ft_putchar(side);
		while (j < x - 1)
		{
			ft_putchar(' ');
			j++;
		}
		j = 1;
		ft_putchar(side);
		ft_putchar('\n');
		i++;
	}
}

void	rush(int x, int y)
{
	if (y >= 1)
	{
		print_top_bottom(x, '/', '*', '\\');
	}
	print_middle(x, y, '*');
	if (y >= 2)
	{
		print_top_bottom(x, '\\', '*', '/');
	}
}
