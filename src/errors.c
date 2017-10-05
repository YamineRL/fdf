/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhaddar <yhaddar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 12:39:45 by yhaddar           #+#    #+#             */
/*   Updated: 2017/10/05 16:58:07 by yhaddar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int				error(int ac)
{
	if (ac != 2)
	{
		ft_putstr("usage: ./fdf file_name\n");
		exit(0);
	}
	return (1);
}

static int		read_file(t_env *env)
{
	char	buff[BUFF_SIZE + 1];
	char	*tmp;
	int		ret;

	while ((ret = read(env->fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = ft_strjoin(env->file, buff);
		free(env->file);
		env->file = ft_strdup(tmp);
		free(tmp);
	}
	if (ret == -1)
		return (0);
	close(env->fd);
	return (1);
}

int				check_file(t_env *env)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	if (!(read_file(env)))
		return (-1);
	while (env->file[i] != '\0')
	{
		if (env->file[i] == '\n' && env->file[i + 1] == '\n')
			return (-1);
		if (env->file[i] == '\n' || env->file[i] == '\0')
			y++;
		if (!(ft_isdigit(env->file[i])) && env->file[i] != ' ' &&
				env->file[i] != '\n' && env->file[i] != '-')
			return (-1);
		i++;
	}
	return (1);
}
