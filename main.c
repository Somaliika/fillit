/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 13:32:28 by ilian             #+#    #+#             */
/*   Updated: 2019/01/13 13:32:30 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	int			i;
	char		**tetr_array;
	t_figure	*figures;

	i = 0;
	if (argc != 2)
	{
		ft_putstr("usage: fillit source_file\n");
		return (0);
	}
	if (!(tetr_array = read_file(argv[1])))
	{
		ft_putstr("error\n");
		return (0);
	}
	if (!is_valid(tetr_array))
	{
		ft_putstr("error\n");
		return (0);
	}
	figures = convert(tetr_array);
	print_matrix(fill(figures));
	return (0);
}
