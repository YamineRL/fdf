/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhaddar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 14:42:50 by yhaddar           #+#    #+#             */
/*   Updated: 2017/01/31 14:42:51 by yhaddar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	size_orig;

	size_orig = size;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	while (*dst && size)
	{
		dst++;
		size--;
	}
	if (!size)
		return (size_orig + len_src);
	while (*src && size-- > 1)
		*dst++ = *src++;
	*dst = '\0';
	return (len_dst + len_src);
}
