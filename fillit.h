/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 13:32:12 by ilian             #+#    #+#             */
/*   Updated: 2019/01/13 13:32:14 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "get_next_line.h"
# include <fcntl.h>
# include "structures.h"

char		**read_file(char *file);
int			is_valid(char **fields);
t_figure	*convert(char	**tetr_array);
t_point		*get_size(char **tetr_array);
t_point		*create_points(char **tetr_array);
void		push_point_end(t_point **start, int x, int y);
void		push_figure_end(t_figure **figures, t_point *points,
	t_point *size, char symb);
t_point		*create_point(int x, int y);
t_figure	*create_figure(t_point *points, int width, int height, char symb);
void		free_figures(t_figure *figure);
void		free_points(t_point *point);
void		print_matrix(char *result);
char		*fill(t_figure *list);
char		*new_space(size_t size);
int			ft_lstsize(t_figure *lst);
int			square_root(int x);

#endif
