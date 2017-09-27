/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhaddar <yhaddar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 12:39:37 by yhaddar           #+#    #+#             */
/*   Updated: 2017/09/27 21:09:59 by yhaddar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		window_center(t_env *e)
{
	e->winx = (WIN_X / 2) - ((e->xmax * e->zoom) / 2) +
	((e->ymax * e->zoom) / 2);
	e->winy = (WIN_Y / 2) - ((e->ymax * e->zoom) / 2);
}

void			display_comments(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 10, 0, 0xFFFFFF,
		"Quit             = esc");
	mlx_string_put(e->mlx, e->win, 10, 15, 0xFFFFFF,
		"Zoom             = + / -");
	mlx_string_put(e->mlx, e->win, 10, 30, 0xFFFFFF,
		"Alter  z : + / - = z / a");
	mlx_string_put(e->mlx, e->win, 10, 45, 0xFFFFFF,
		"Negative z       = n");
	mlx_string_put(e->mlx, e->win, 10, 60, 0xFFFFFF,
		"Switch view      = i");
	mlx_string_put(e->mlx, e->win, 10, 75, 0xFFFFFF,
		"Move map         = < > ^ v");
	mlx_string_put(e->mlx, e->win, 10, 90, 0xFFFFFF,
		"Horizontal rot   = 1 / 2");
	mlx_string_put(e->mlx, e->win, 10, 105, 0xFFFFFF,
		"Vertical rot     = 3 / 6");
}

void			ft_display(t_points *tab_p, t_env *e)
{
	window_center(e);
	before_draw(tab_p, e);
	e->tab_p = tab_p;
	mlx_key_hook(e->win, keyhooks, e);
	mlx_loop(e->mlx);
}
