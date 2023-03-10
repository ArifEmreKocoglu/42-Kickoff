/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:14:51 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/01/10 12:07:25 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int				nm;
	long long int	tmp;

	nm = 1;
	tmp = 0;
	while (*s == ' ' || *s == '\n' || *s == '\t' || *s == '\v' \
			|| *s == '\f' || *s == '\r')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			nm = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		tmp = (tmp * 10) + (*s - '0') * nm;
		s++;
		if (tmp > 2147483647)
			return (-1);
		if (tmp < -2147483648)
			return (0);
	}
	return (tmp);
}

/*int main()
{
	printf("%d", ft_atoi("   -12"));
	return(0);
}*/