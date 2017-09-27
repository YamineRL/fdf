/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhaddar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 13:00:19 by yhaddar           #+#    #+#             */
/*   Updated: 2017/01/31 13:00:21 by yhaddar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const	unsigned char	*str1 = (unsigned char*)s1;
	const	unsigned char	*str2 = (unsigned char*)s2;

	while (n--)
	{
		if (*str1 != *str2)
			return ((*str1 - *str2));
		str1++;
		str2++;
	}
	return (0);
}
