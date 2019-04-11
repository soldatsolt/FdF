int		is_valid(char c, int str_base)
{
	char digits1[17] = "0123456789abcdef";
	char digits2[17] = "0123456789ABCDEF";

	while (str_base--)
		if (digits1[str_base] == c || digits2[str_base] == c)
			return (1);
	return (0);
}

int		value_of(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'z')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 10);
	return (0);
}

int		ft_atoi_base(const char *str, int str_base)
{
	int res;
	int sign;

	res = 0;
	sign = 1;
	while (*str == 32 || *str == '\n' || *str == '\t' || *str == '\v')
		++str;
	if (*str == '-')
	{
		sign = -1;
		++str;
	}
	else if (*str == '+')
		++str;
	while (is_valid(*str, str_base))
	{
		res = res * str_base + value_of(*str);
		++str;
	}
	return (res * sign);
}
