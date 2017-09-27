/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhaddar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 14:44:20 by yhaddar           #+#    #+#             */
/*   Updated: 2017/02/01 17:48:01 by yhaddar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		slen;

	slen = ft_strlen(s) + 1;
	while (slen--)
	{
		if (s[slen] == (char)c)
			return ((char *)s + slen);
	}
	if (s[slen] == (char)c)
		return ((char *)s + slen);
	return (NULL);
}
