/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhaddar <yhaddar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 12:39:28 by yhaddar           #+#    #+#             */
/*   Updated: 2017/10/04 20:31:16 by yhaddar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static unsigned int	ft_get_color_suite(int cp1, int cp2, int i, int delta)
{
	unsigned int	color;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	int				coor_point;

	r = 255;
	b = 255;
	g = 255;
	coor_point = cp1 + (float)(cp2 - cp1) * i / delta;
	if (coor_point <= 191.25)
	{
		g = 4 * (float)(coor_point - 191.25);
		b = 0;
	}
	else if (coor_point > 191.5)
	{
		r = 4 * (float)(191.5 - coor_point);
		b = 0;
	}
	color = (r << 16) + (g << 8) + b;
	return (color);
}

unsigned int		ft_get_color(int cp1, int cp2, int i, int delta)
{
	unsigned int	color;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	int				coor_point;

	r = 255;
	b = 255;
	g = 255;
	coor_point = cp1 + (float)(cp2 - cp1) * i / delta;
	if (coor_point <= 63.75)
		g = 4 * (float)(63.75 - coor_point);
	else if (coor_point <= 127.5)
	{
		b = 4 * (float)(127.5 - coor_point);
		g = 0;
	}
	else
		return (ft_get_color_suite(cp1, cp2, i, delta));
	color = (r << 16) + (g << 8) + b;
	return (color);
}
