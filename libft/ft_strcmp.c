/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhaddar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 14:41:51 by yhaddar           #+#    #+#             */
/*   Updated: 2017/01/31 14:41:58 by yhaddar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*ps1;
	unsigned char	*ps2;

	if (!s1 && !s2)
		return (0);
	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	while (*ps1)
	{
		if (*ps1 != *ps2)
			return ((*ps1 - *ps2));
		ps1++;
		ps2++;
	}
	if (*ps1 != *ps2)
		return ((*ps1 - *ps2));
	return (0);
}
