/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 23:26:36 by ilian             #+#    #+#             */
/*   Updated: 2019/01/27 13:45:33 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			find_empty_place(t_figure *f, char *space, int size, int min)
{
	int i;

	i = 0;
	(void)f;
	(void)size;
	while (space[i] != '\0')
	{
		if (i >= min && space[i] == '.')
			return (i);
		i++;
	}
	return (-1);
}

char		*put_figure_in_space(t_figure *figure, char *space, int space_size,
	int *sp)
{
	t_point *cur;
	int		i;
	char	*tmp;

	if (*sp == -1)
		return (NULL);
	tmp = ft_strdup(space);
	cur = figure->start_point;
	i = *sp;
	while (cur)
	{
		i += cur->y_offset * space_size + cur->x_offset;
		if (tmp[i] != '.' || BEAT_LEFT_BOUNDARY(cur->x_offset, i, space_size) ||
			BEAT_RIGHT_BOUNDARY(cur->x_offset, i, space_size))
		{
			*sp = find_empty_place(figure, space, space_size, *sp + 1);
			free(tmp);
			return (put_figure_in_space(figure, space, space_size, sp));
		}
		tmp[i] = figure->symbol;
		cur = cur->next;
	}
	return (tmp);
}

char		*fill_changing_position(t_figure *current, char *space, int size)
{
	int		i;
	char	*result;
	char	*tmp;

	i = -1;
	while (++i < size * size)
	{
		result = put_figure_in_space(current, space, size, &i);
		if (!result)
			return (NULL);
		if (current->next)
		{
			tmp = result;
			result = fill_changing_position(current->next, tmp, size);
			free(tmp);
		}
		if (result)
			return (result);
	}
	return (NULL);
}

char		*fill(t_figure *list)
{
	int		min_size;
	int		max_size;
	char	*result;
	char	*space;

	min_size = square_root(MIN_SQUARE * ft_lstsize(list));
	if (MIN_SQUARE * ft_lstsize(list) % min_size != 0)
		min_size++;
	max_size = square_root(MAX_SQUARE * ft_lstsize(list));
	if (MAX_SQUARE * ft_lstsize(list) % max_size != 0)
		max_size++;
	while (min_size <= max_size)
	{
		space = new_space(min_size * min_size);
		result = fill_changing_position(list, space, min_size);
		free(space);
		if (result)
			return (result);
		min_size++;
	}
	return (NULL);
}
