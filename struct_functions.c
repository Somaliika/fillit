/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 13:32:49 by ilian             #+#    #+#             */
/*   Updated: 2019/01/13 13:32:51 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_lstsize(t_figure *lst)
{
	int i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

t_point		*create_point(int x, int y)
{
	t_point	*point;

	point = (t_point*)malloc(sizeof(t_point));
	point->x_offset = x;
	point->y_offset = y;
	point->next = NULL;
	return (point);
}

t_figure	*create_figure(t_point *points, int width, int height, char symb)
{
	t_figure	*figure;

	figure = (t_figure *)malloc(sizeof(t_figure));
	figure->start_point = points;
	figure->width = width;
	figure->height = height;
	figure->symbol = symb;
	figure->next = NULL;
	return (figure);
}
