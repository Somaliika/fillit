/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 17:18:28 by ilian             #+#    #+#             */
/*   Updated: 2019/01/13 17:18:30 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_points(t_point *point)
{
	if (point->next)
		free_points(point->next);
	free(point);
}

void	free_figures(t_figure *figure)
{
	if (figure->start_point)
		free_points(figure->start_point);
	if (figure->next)
		free_figures(figure->next);
	if (figure)
		free(figure);
}
