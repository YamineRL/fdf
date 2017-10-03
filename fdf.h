/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhaddar <yhaddar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 12:39:57 by yhaddar           #+#    #+#             */
/*   Updated: 2017/10/03 16:29:15 by yhaddar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include "mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>

# define BUFF_SIZE 1500
# define WIN_X 1400
# define WIN_Y 1400
# define ABS(Value) (Value < 0 ? -Value : Value)

typedef struct	s_points
{
	float		newx;
	float		newy;
	int			xx;
	int			xo;
	int			yy;
	int			yo;
	int			zz;
}				t_points;

typedef struct	s_line
{
	int			x;
	int			y;
	int			dx;
	int			dy;
	int			xinc;
	int			yinc;
	float		cp1;
	float		cp2;
}				t_line;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	int			xmax;
	int			xmin;
	float		ymax;
	int			ymin;
	int			zmax;
	int			zmin;
	int			nb;
	int			zoom;
	int			tr;
	int			td;
	int			iso;
	float		c1;
	float		c2;
	float		divpi;
	int			is_decr;
	int			winx;
	int			winy;
	int			alpha;
	float		pivo;
	int			zneg;
	t_points	*tab_p;
}				t_env;

void			relief(t_points *tab_p, t_env *e);
int				keyhooks(int keycode, t_env *e);
unsigned int	ft_get_color(int cp1, int cp2, int i, int delta);
void			display_comments(t_env *e);
t_points		*readline(char *line, t_points **tab_p, t_env *e);
void			ft_display(t_points *tab_p, t_env *e);
int				get_next_line(int const fd, char **line);
int				main(int ac, char **av);
void			before_draw(t_points *tab_p, t_env *e);
int				char_error(char c);
int				error(int ac);

#endif
