/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhaddar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 12:59:48 by yhaddar           #+#    #+#             */
/*   Updated: 2017/01/31 17:22:55 by yhaddar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*addr;

	if (!size)
		return (NULL);
	addr = malloc(sizeof(*addr) * size);
	if (!addr)
		return (NULL);
	ft_bzero(addr, size);
	return (addr);
}
