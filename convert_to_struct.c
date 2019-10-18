/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 13:31:59 by ilian             #+#    #+#             */
/*   Updated: 2019/01/13 13:32:01 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_figure	*convert(char **tetr_array)
{
	int			i;
	t_point		*size;
	t_point		*points;
	t_figure	*figures;
	char		s;

	i = 0;
	figures = NULL;
	s = 'A';
	while (tetr_array[i])
	{
		points = create_points(&tetr_array[i]);
		size = get_size(&tetr_array[i]);
		size->x_offset += 1;
		size->y_offset += 1;
		push_figure_end(&figures, points, size, s);
		free(size);
		i += 4;
		if (tetr_array[i])
			i++;
		s++;
	}
	return (figures);
}

t_point		*get_size(char **tetr_array)
{
	int		i;
	int		j;
	t_point	*dif;
	t_point	*size;

	dif = create_point(-1, -1);
	dif->next = create_point(-1, -1);
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (tetr_array[i][++j])
		{
			if (tetr_array[i][j] != '#')
				continue ;
			(dif->y_offset == -1 || dif->y_offset > i) && (dif->y_offset = i);
			(dif->x_offset == -1 || dif->x_offset > j) && (dif->x_offset = j);
			(dif->next->y_offset < i) && (dif->next->y_offset = i);
			(dif->next->x_offset < j) && (dif->next->x_offset = j);
		}
	}
	size = create_point(dif->next->x_offset - dif->x_offset,
		dif->next->y_offset - dif->y_offset);
	free_points(dif);
	return (size);
}

t_point		*create_points(char **tetr_array)
{
	int		i;
	int		j;
	int		prevx;
	int		prevy;
	t_point	*points;

	i = -1;
	points = NULL;
	while (++i < 4)
	{
		j = -1;
		while (tetr_array[i][++j])
		{
			if (tetr_array[i][j] != '#')
				continue ;
			(!points) ? (points = create_point(0, 0)) :
			push_point_end(&points, j - prevx, i - prevy);
			prevy = i;
			prevx = j;
		}
	}
	return (points);
}

void		push_point_end(t_point **start, int x, int y)
{
	t_point *tmp;

	tmp = *start;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = create_point(x, y);
}

void		push_figure_end(t_figure **figures, t_point *points,
	t_point *size, char symb)
{
	t_figure *tmp;

	if (!*figures)
	{
		*figures = create_figure(points, size->x_offset, size->y_offset, symb);
		return ;
	}
	tmp = *figures;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = create_figure(points, size->x_offset, size->y_offset, symb);
}
