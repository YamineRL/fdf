/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhaddar <yhaddar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 12:39:45 by yhaddar           #+#    #+#             */
/*   Updated: 2017/10/03 17:10:54 by yhaddar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		char_error(char c)
{
	if (c < '0' || c > '9')
	{
		ft_putstr("map values incompatible\n");
		exit(0);
	}
	return (1);
}

int		error(int ac)
{
	if (ac != 2)
	{
		ft_putstr("usage: ./fdf file_name\n");
		exit(0);
	}
	return (1);
}
