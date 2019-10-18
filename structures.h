/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 23:33:47 by ilian             #+#    #+#             */
/*   Updated: 2019/01/13 13:33:01 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H
# include "libft.h"
# define MIN_SQUARE 4
# define MAX_SQUARE 9
# define BEAT_LEFT_BOUNDARY(x, i, size) (x < 0 && (i - x) % size + x < 0)
# define BEAT_RIGHT_BOUNDARY(x, i, size) (x > 0 && i % size == 0)

typedef struct	s_point
{
	int				x_offset;
	int				y_offset;
	struct s_point	*next;

}				t_point;

typedef struct	s_figure
{
	t_point			*start_point;
	int				width;
	int				height;
	char			symbol;
	struct s_figure	*next;

}				t_figure;

#endif
