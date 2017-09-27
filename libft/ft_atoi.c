/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhaddar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 12:57:15 by yhaddar           #+#    #+#             */
/*   Updated: 2017/02/01 19:22:14 by yhaddar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		sign;
	int		rslt;

	rslt = 0;
	sign = 0;
	while (ft_isspace(*str) && *str != '\0')
		str++;
	if ((*str == '-' || *str == '+') && *str != '\0')
	{
		if (*str == '-')
			sign = 1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		rslt *= 10;
		rslt += (*str - 48);
		str++;
	}
	if (sign)
		rslt = -(rslt);
	return (rslt);
}
