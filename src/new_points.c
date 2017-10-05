/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_points.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhaddar <yhaddar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 12:40:09 by yhaddar           #+#    #+#             */
/*   Updated: 2017/10/05 16:58:40 by yhaddar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		relief(t_points *tab_p, t_env *e)
{
	int			i;
	float		x;
	float		y;
	int			z;

	i = 0;
	while (i <= e->nb)
	{
		x = e->zoom * tab_p[i].xx;
		y = e->zoom * tab_p[i].yy;
		z = (e->zoom / e->alpha) * tab_p[i].zz * e->zneg;
		if (e->iso == 1)
		{
			tab_p[i].newx = e->c1 * x - e->c2 * y;
			tab_p[i].newy = e->pivo * (e->c1 / 2 * x + e->c2 / 2 * y) - z;
		}
		else
		{
			tab_p[i].newx = x - e->c1 * z;
			tab_p[i].newy = y - e->c1 / 2 * z;
		}
		i++;
	}
}
