/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhaddar <yhaddar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 12:40:03 by yhaddar           #+#    #+#             */
/*   Updated: 2017/10/06 22:30:04 by yhaddar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int		keyhooks_2(int keycode, t_env *e)
{
	if ((e->zoom > 5 && keycode == 78) || keycode == 69)
		e->zoom = keycode == 78 ? e->zoom - 2 : e->zoom + 2;
	if (keycode == 53)
		exit(0);
	if (keycode == 34)
	{
		if (e->iso == 1)
			e->iso = 0;
		else if (e->iso == 0)
			e->iso = 1;
	}
	if (keycode == 116 && e->alpha >= 2)
		e->alpha -= 1;
	if (keycode == 121 && e->alpha <= 11)
		e->alpha += 1;
	mlx_clear_window(e->mlx, e->win);
	before_draw(e->tab_p, e);
	return (0);
}

int				keyhooks(int keycode, t_env *e)
{
	if (keycode == 45)
	{
		if (e->zneg == 1)
			e->zneg = -1;
		else if (e->zneg == -1)
			e->zneg = 1;
	}
	if (keycode == 123 || keycode == 124)
		e->winx = keycode == 124 ? e->winx - 50 : e->winx + 50;
	if (keycode == 125 || keycode == 126)
		e->winy = keycode == 125 ? e->winy - 50 : e->winy + 50;
	if (keycode == 85 || keycode == 88)
		e->pivo = keycode == 85 ? e->pivo + 0.1 : e->pivo - 0.1;
	if (keycode == 84 || keycode == 83)
	{
		e->divpi = keycode == 84 ? e->divpi + M_PI / 21 : e->divpi - M_PI / 21;
		e->c1 = (float)sin(e->divpi);
		e->c2 = (float)cos(e->divpi);
	}
	keyhooks_2(keycode, e);
	return (0);
}
