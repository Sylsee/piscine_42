#include <stdio.h>

int	ft_atoi(char *nb)
{
	int i;
	int sign;
	int result;

	i = 0;
	sign = 1;
	result = 0;
	while (nb[i] == ' ' || (nb[i] >= 8 && nb[i] <= 13))
		i++;
	while (nb[i] == '-' || nb[i] == '+')
	{
		if (nb[i] == '-')
			sign *= -1;
		i++;
	}
	while (nb[i] >= '0' && nb[i] <= '9')
	{
		result = result * 10 + nb[i] - '0';
		i++;
	}
	return (result * sign);
}

int	main(int argc, char **argv)
{
	(void)argc;
	printf("%d\n", ft_atoi(argv[1]));
	return (0);
}
