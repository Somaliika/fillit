/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 13:33:20 by ilian             #+#    #+#             */
/*   Updated: 2019/01/13 13:33:28 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	is_correct_chars(char **field)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (field[i][j])
		{
			if (field[i][j] != '.' && field[i][j] != '#')
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	count_neubors(char **field, int i, int j)
{
	int count;

	count = 0;
	if (j - 1 >= 0 && field[i][j - 1] == '#')
		count++;
	if (j + 1 < 4 && field[i][j + 1] == '#')
		count++;
	if (i - 1 >= 0 && field[i - 1][j] == '#')
		count++;
	if (i + 1 < 4 && field[i + 1][j] == '#')
		count++;
	return (count);
}

int	is_valid_figure(char **field)
{
	int i;
	int j;
	int count;
	int neubors;

	i = 0;
	j = 0;
	count = 0;
	neubors = 0;
	while (i < 4)
	{
		while (field[i][j])
		{
			if (field[i][j] == '#')
			{
				neubors += count_neubors(field, i, j);
				count++;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (count == 4 && (neubors == 6 || neubors == 8));
}

int	is_valid_size(char **fields)
{
	int i;
	int len;
	int j;

	i = 0;
	j = 0;
	while (fields[i])
	{
		len = ft_strlen(fields[i]);
		if (len == 0)
		{
			if (j != 4)
				return (0);
			j = -1;
		}
		else if (len != 4)
			return (0);
		i++;
		j++;
	}
	if (j != 4)
		return (0);
	return (1);
}

int	is_valid(char **fields)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (!is_valid_size(fields))
		return (0);
	while (fields[i])
	{
		if (!is_correct_chars(&fields[i]))
			return (0);
		if (!is_valid_figure(&fields[i]))
			return (0);
		i += 4;
		count++;
		if (fields[i])
			i++;
	}
	if (count < 1 || count > 26)
		return (0);
	return (1);
}
