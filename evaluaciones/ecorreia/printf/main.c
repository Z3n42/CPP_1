#include "ft_printf.h"
int main(void)
{
	printf("SIZE: %d\n", ft_printf("%d %d %x %X %s %p %% %u\n", 2147483647, -2147483648, -1, -1, NULL, -1, -1 ));
	printf("SIZE: %d\n", printf("%d %d %x %X %s %p %% %u\n", 2147483647, -2147483648, -1, -1, NULL, -1, -1));
}
