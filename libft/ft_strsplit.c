/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhaddar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 14:44:26 by yhaddar           #+#    #+#             */
/*   Updated: 2017/02/06 19:12:23 by yhaddar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (s[i] != c)
		count = 1;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1])
			count++;
		i++;
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**ptr;
	t_point	p;

	if (s == NULL)
		return (NULL);
	if (!(ptr = (char **)malloc(sizeof(char*) * (word_count(s, c) + 1))))
		return (NULL);
	p.i = 0;
	p.h = 0;
	while (s[p.i])
	{
		while (s[p.i] == c && s[p.i])
			p.i++;
		p.j = 0;
		while (s[p.i + p.j] != c && s[p.i + p.j])
			p.j++;
		ptr[p.h] = ft_strndup(&s[p.i], (size_t)p.j);
		p.i = p.i + p.j;
		if (p.h == word_count(s, c))
			break ;
		p.h++;
	}
	ptr[p.h] = NULL;
	return (ptr);
}
