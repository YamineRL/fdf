/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhaddar <yhaddar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 12:39:41 by yhaddar           #+#    #+#             */
/*   Updated: 2017/09/27 21:09:57 by yhaddar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			draw_line_x(t_line *line, t_env *e)
{
	int		i;
	int		cumul;

	cumul = line->dx / 2;
	i = 1;
	e->is_decr = line->dx > 0 ? 1 : -1;
	while (i <= line->dx)
	{
		line->x += line->xinc;
		cumul += line->dy;
		if (cumul >= line->dx)
		{
			cumul -= line->dx;
			line->y += line->yinc;
		}
		mlx_pixel_put(e->mlx, e->win, e->winx + line->x, e->winy + line->y,
			ft_get_color(line->cp1, line->cp2, e->is_decr * i, line->dx));
		i++;
	}
}

static void			draw_line_y(t_line *line, t_env *e)
{
	int	j;
	int	cumul;

	j = 1;
	cumul = line->dy / 2;
	e->is_decr = line->dy > 0 ? 1 : -1;
	while (j <= line->dy)
	{
		line->y += line->yinc;
		cumul += line->dx;
		if (cumul >= line->dy)
		{
			cumul -= line->dy;
			line->x += line->xinc;
		}
		mlx_pixel_put(e->mlx, e->win, e->winx + line->x, e->winy + line->y,
			ft_get_color(line->cp1, line->cp2, e->is_decr * j, line->dx));
		j++;
	}
}

static void			join_point(t_env *e, t_points *p1, t_points *p2)
{
	t_line		line;
	static int	nb = 0;

	e->is_decr = 0;
	line.x = p1->newx;
	line.y = p1->newy;
	line.dx = p2->newx - p1->newx;
	line.dy = p2->newy - p1->newy;
	line.xinc = (line.dx >= 0) ? 1 : -1;
	line.yinc = (line.dy >= 0) ? 1 : -1;
	line.dx = ABS(line.dx);
	line.dy = ABS(line.dy);
	line.cp1 = (float)255 / (float)(e->zmax - e->zmin) *
	(float)(p1->zz - e->zmin);
	line.cp2 = (float)255 / (float)(e->zmax - e->zmin) *
	(float)(p2->zz - e->zmin);
	if (line.dx >= line.dy)
		draw_line_x(&line, e);
	else
		draw_line_y(&line, e);
	nb++;
}

static void			before_draw_bis(t_points *tab_p, t_env *e, int i)
{
	join_point(e, &tab_p[i], &tab_p[i + 1]);
	join_point(e, &tab_p[i], &tab_p[i + e->xmax]);
	if (tab_p[i].zz == tab_p[i + e->xmax + 1].zz)
		join_point(e, &tab_p[i], &tab_p[i + e->xmax + 1]);
	if (tab_p[i].xx > e->xmin && tab_p[i].zz == tab_p[i + e->xmax - 1].zz)
		join_point(e, &tab_p[i], &tab_p[i + e->xmax - 1]);
}

void				before_draw(t_points *tab_p, t_env *e)
{
	int			i;
	t_line		line;

	i = 0;
	display_comments(e);
	relief(tab_p, e);
	while (i < e->nb)
	{
		if (tab_p[i].yy == (e->ymax - 1) && tab_p[i].xx != (e->xmax - 1))
			join_point(e, &tab_p[i], &tab_p[i + 1]);
		else if (tab_p[i].xx == (e->xmax - 1) && tab_p[i].yy != (e->ymax - 1))
		{
			join_point(e, &tab_p[i], &tab_p[i + e->xmax]);
			if (tab_p[i].zz == tab_p[i + e->xmax - 1].zz)
				join_point(e, &tab_p[i], &tab_p[i + e->xmax - 1]);
		}
		else if (tab_p[i].xx != (e->xmax - 1) && tab_p[i].yy != (e->ymax - 1))
			before_draw_bis(tab_p, e, i);
		line.x = tab_p[i].newx;
		line.y = tab_p[i].newy;
		i++;
	}
}
