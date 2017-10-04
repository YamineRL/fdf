/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhaddar <yhaddar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 12:40:06 by yhaddar           #+#    #+#             */
/*   Updated: 2017/10/04 19:52:12 by yhaddar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			initmax(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "Fdf The Great");
	e->xmax = 0;
	e->ymax = 0;
	e->xmin = 0;
	e->ymin = 0;
	e->nb = 0;
	e->divpi = M_PI / 6;
	e->c1 = (float)sin(e->divpi);
	e->c2 = (float)cos(e->divpi);
	e->winx = 1000;
	e->winy = 100;
	e->iso = 1;
	e->alpha = 10;
	e->zoom = 20;
	e->zmin = 0;
	e->zmax = 0;
	e->pivo = 1;
	e->zneg = 1;
}

static int			ft_realloc(int fd, t_points **tab_p)
{
	char	**split;
	int		i;
	char	*line;
	int		j;

	j = 0;
	while (get_next_line(fd, &line) == 1)
	{
		i = 0;
		split = ft_strsplit(line, ' ');
		while (split[i])
			i++;
		j += i;
		free(line);
	}
	if (!(*tab_p = (t_points*)malloc(sizeof(t_points) * (j + 1))))
		return (0);
	close(fd);
	return (j);
}

t_points			*readline(char *line, t_points **tab_p, t_env *e)
{
	int			i;
	char		**linesplit;
	static int	y = 0;
	static int	p = 0;

	i = 0;
	linesplit = ft_strsplit(line, ' ');
	while (linesplit[i] != NULL)
	{
		(*tab_p)[p].xx = i;
		(*tab_p)[p].yy = y;
		if (((*tab_p)[p].zz = ft_atoi(linesplit[i])) <= e->zmin)
			e->zmin = (*tab_p)[p].zz;
		if (((*tab_p)[p].zz = ft_atoi(linesplit[i])) >= e->zmax)
			e->zmax = (*tab_p)[p].zz;
		i++;
		p++;
	}
	e->xmax = i;
	e->nb += i;
	y++;
	if (y > e->ymax)
		e->ymax = y;
	return (*tab_p);
}

int					main(int ac, char **av)
{
	int			fd;
	char		*line;
	t_points	*tab_p;
	size_t		j;
	t_env		e;

	j = 0;
	initmax(&e);
	error(ac);
	fd = open(av[1], O_RDONLY);
	j = ft_realloc(fd, &tab_p);
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
		readline(line, &tab_p, &e);
	if (e.xmax == 0 || e.nb / e.xmax != e.ymax || fd < 0)
	{
		ft_putstr("error map\n");
		return (0);
	}
	close(fd);
	ft_display(tab_p, &e);
	free(tab_p);
	return (1);
}
