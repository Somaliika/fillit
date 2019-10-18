/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 20:55:07 by ilian             #+#    #+#             */
/*   Updated: 2019/01/27 13:45:41 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*new_space(size_t size)
{
	char	*temp;
	int		i;

	i = -1;
	temp = (char*)malloc(size + 1);
	if (temp == NULL)
		return (NULL);
	while (++i < (int)size)
		temp[i] = '.';
	temp[i] = '\0';
	return (temp);
}

int		square_root(int x)
{
	int i;
	int result;

	i = 1;
	result = 1;
	if (x == 0 || x == 1)
		return (x);
	while (result <= x)
	{
		i++;
		result = i * i;
	}
	return (i - 1);
}

void	print_matrix(char *result)
{
	int i;
	int space_size;

	if (result == NULL)
		ft_putstr("empty matrix\n");
	else
	{
		i = 0;
		space_size = square_root(ft_strlen(result));
		while (result[i] != '\0')
		{
			if (i % space_size == 0 && i != 0)
				ft_putchar('\n');
			ft_putchar(result[i]);
			i++;
		}
		ft_putchar('\n');
		free(result);
	}
}
