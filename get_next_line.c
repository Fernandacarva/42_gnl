/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferncarv <ferncarv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:36:21 by ferncarv          #+#    #+#             */
/*   Updated: 2022/07/11 17:13:40 by ferncarv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *count_line(char *str)
{
    int     i;
	char	*aux;
	int		j;

	j = 0;
    i = 0;
	
	if (!str[i])
		return (0);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	aux = malloc((i + 1) * sizeof(char));
	if (!aux)
		return (0);
	aux[i] = '\0';
	while (j < i)
	{
		aux[j] = str[j];
		j++;
	}
	return (aux);
}

static char	*get_rest(char	*str)
{
	char	*aux;
	int		i;
	int		j_p;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (0);
	}
	j_p = 0;
	aux = malloc((ft_strlen(str) - i + 1) * sizeof(char));
	if (!aux)
		return (0);
	while (str[i] != '\0')
		aux[j_p++] = str[i++];
	aux[j_p] = '\0';
	free(str);
	return (aux);
}

char	*get_next_line(int fd)
{
	int			n_by;
	char		*buffer;
	static char	*str;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	n_by = 1;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (n_by > 0 && ft_strchr(str, '\n') == 0)
	{ 
		n_by = read(fd, buffer, BUFFER_SIZE);
		if (n_by == -1)
		{	free(buffer);
			return (NULL);
		}
		buffer[n_by] = '\0';
	   	str = ft_strjoin(str, buffer);

	}
	free(buffer);
	line = count_line(str);
	str = get_rest(str);
	return (line);
}
