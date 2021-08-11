#include <stdio.h>
#include "libft/libft.h"

int dec_to_b(int nbr)
{
	int tmp;

	tmp = 0;
	while (nbr)
	{
		printf("%d\n", nbr);
		tmp = tmp * 10 + (nbr % 2);
		nbr = nbr / 2;
	}
	return (tmp * 10);
}

int main(int argc, char **argv)
{
	(void)argc;
	printf("nbr = %s\nnbr_b = %d\n", argv[1], dec_to_b(ft_atoi(argv[1])));
}
