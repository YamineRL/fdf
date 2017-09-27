/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhaddar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 12:59:56 by yhaddar           #+#    #+#             */
/*   Updated: 2017/02/01 17:13:16 by yhaddar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char		*p_s1;
	const char	*p_s2 = s2;

	p_s1 = s1;
	while (n--)
	{
		*p_s1++ = *p_s2;
		if (*p_s2 == c)
			return (p_s1);
		p_s2++;
	}
	return (0);
}
