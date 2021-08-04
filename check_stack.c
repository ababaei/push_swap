int check_limit(char *arg)
{
	
}

int check_char(char *arg)
{
	int i;
	int flag_sign;

	i = 0;
	flag_sign = 0;
	while (arg[i])
	{
		if ((arg[i] != '-' || arg[i] != '+')
				&& (arg[i] <= '0' && arg[i] >= '9'))
			return (0);
		if (arg[i] == '+')
		{
			if (flag_sign)
				return (0);
			flag_sign = 1;
		}
		i++;
	}
	return (1);
}

int isStackOk(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (check_char(argv[i]) == 0)
			return (0);
		if (check_limit(argv[i]) == 0)
			return (0);
		if (check_double(argv[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
