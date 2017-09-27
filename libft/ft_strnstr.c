/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhaddar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 14:44:09 by yhaddar           #+#    #+#             */
/*   Updated: 2017/01/31 14:44:09 by yhaddar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	len;

	len = ft_strlen(s2);
	if (len == 0)
		return ((char *)s1);
	while (*s1 && len <= n--)
	{
		if (ft_memcmp(s1++, s2, len) == 0)
			return ((char *)s1 - 1);
	}
	return (NULL);
}
