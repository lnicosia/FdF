/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:00:36 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/03 13:24:55 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_check_base1(char *base)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int		ft_strlen1(char *str, char *base)
{
	int strlen;
	int j;
	int check;

	strlen = 0;
	while (*str)
	{
		check = 0;
		j = -1;
		while (base[++j])
		{
			if (*str == base[j])
			{
				check++;
				strlen++;
			}
		}
		if (!check)
			if (*str == '+' || *str == '-' || *str == ' ')
				return (strlen);
		if (!check)
			return (0);
		str++;
	}
	return (strlen);
}

int		ft_iterative_power(int nb, int power)
{
	int i;
	int base;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	base = nb;
	i = 1;
	while (i < power)
	{
		nb = nb * base;
		i++;
	}
	return (nb);
}

int		ft_add(char *str, int baselen, char *base)
{
	int res;
	int j;
	int strlen;
	int check;
	int k;

	res = 0;
	k = 0;
	strlen = ft_strlen1(str, base);
	while (*str)
	{
		j = -1;
		check = 0;
		while (base[++j])
		{
			if (*str == base[j])
			{
				res = res + j * ft_iterative_power(baselen, strlen - k - 1);
			}
		}
		str++;
		k++;
	}
	return (res);
}

int		ft_atoi_base(char *str, char *base)
{
	int		res;
	int		baselen;
	int		neg;
	int		i;

	if (!str)
		return (0);
	neg = 1;
	res = 0;
	i = 0;
	baselen = ft_check_base1(base);
	if (baselen < 2)
		return (0);
	while (*str == ' ' || (*str > 8 && *str < 14))
		str++;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	res = ft_add(str, baselen, base);
	return (neg * res);
}
