/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 13:32:38 by ilian             #+#    #+#             */
/*   Updated: 2019/01/13 13:32:40 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		array_size(char *file)
{
	char	*line;
	int		size;
	int		fd;
	int		read_res;

	size = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (-1);
	size = 0;
	while ((read_res = get_next_line(fd, &line)) == 1)
	{
		free(line);
		size++;
	}
	if (read_res == -1)
		return (-1);
	close(fd);
	return (size);
}

char	**read_file(char *file)
{
	int		fd;
	char	*line;
	int		read_res;
	int		i;
	char	**tetr_array;

	i = array_size(file);
	if (i == -1)
		return (NULL);
	tetr_array = (char **)malloc((i + 1) * sizeof(char *));
	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (NULL);
	while ((read_res = get_next_line(fd, &line)) == 1)
		tetr_array[i++] = line;
	close(fd);
	if (read_res == -1)
		return (NULL);
	tetr_array[i] = NULL;
	return (tetr_array);
}
