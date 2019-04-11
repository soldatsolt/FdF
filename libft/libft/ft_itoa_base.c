#include <stdlib.h>

char	receive_value(int num)
{
	char 	res;
	char 	digits[16] = "0123456789ABCDEF";

	res = digits[num];
	return (res);
}

int		ft_len_del(int value, int base, int flag)
{
	int del;
	int count;

	del = 1;
	count = 1;
	while (value / base >= del)
	{
		del *= base;
		++count;
	}
	if (flag == 1)
		return (count);
	else if (flag == 2)
		return (del);
	return (-1);
}

char	*ft_itoa_base(int value, int base)
{
	int	i;
	int sign;
	int len;
	char *str;

	i = 0;
	sign = 0;
	len = 0;
	if (value < 0 && base == 10)
	{
		sign = 1;
		++len;
		value *= -1;
	}
	else if (value < 0 && base != 10)
		return (NULL);
	len += ft_len_del(value, base, 1);
	str = (char*)malloc(sizeof(char) * len + 1);
	str[len] = '\0';
	if (sign == 1)
		str[i++] = '-';
	sign = ft_len_del(value, base, 2);
	while (i < len)
	{
		str[i++] = receive_value(value / sign);
		value = value % sign;
		sign = sign / base;
	}
	return (str);
}
