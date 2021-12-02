#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int x, y;
	char	*str = "This is a test";

	printf("-.- String Test -.-\n");
	x = printf("Real function: %s\n", str);
	printf("Real function returns: %d\n\n", x);

	y = ft_printf("Your function: %s\n", str);
	printf("Your function returns: %d\n\n", y);

	int	a = 123456789;

	printf("-.- Decimal Test -.-\n");
	x = printf("Real function: %d\n", a);
	printf("Real function returns: %d\n\n", x);

	y = ft_printf("Your function: %d\n", a);
	printf("Your function returns: %d\n\n", y);

	printf("-.- Pointer Test -.-\n");
	x = printf("Real function: %p\n", &a);
	printf("Real function returns: %d\n\n", x);

	y = ft_printf("Your function: %p\n", &a);
	printf("Your function returns: %d\n\n", y);

	printf("-.- Hexadecimal Test -.-\n");
	x = printf("Real function: %x\n", a);
	printf("Real function returns: %d\n\n", x);

	y = ft_printf("Your function: %x\n", a);
	printf("Your function returns: %d\n\n", y);

	x = printf("Real function: %X\n", a * 2);
	printf("Real function returns: %d\n\n", x);

	y = ft_printf("Your function: %X\n", a * 2);
	printf("Your function returns: %d\n\n", y);

	unsigned int	b = UINT_MAX;

	printf("-.- Unsigned Test -.-\n");
	x = printf("Real function: %u\n", b);
	printf("Real function returns: %d\n\n", x);

	y = ft_printf("Your function: %u\n", b);
	printf("Your function returns: %d\n\n", y);

	printf("-.- NULL String Test -.-\n");
	x = printf("Real function: NULL %s NULL\n", NULL);
	printf("Real function returns: %d\n\n", x);

	y = ft_printf("Your function: NULL %s NULL\n", NULL);
	printf("Your function returns: %d\n\n", y);
	return (0);
}
