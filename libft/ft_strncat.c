/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhaddar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 14:43:18 by yhaddar           #+#    #+#             */
/*   Updated: 2017/02/01 17:53:54 by yhaddar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	i = s1_len;
	while (s2[i - s1_len] && i - s1_len < n)
	{
		s1[i] = s2[i - s1_len];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
