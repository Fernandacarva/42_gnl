/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferncarv <ferncarv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:36:21 by ferncarv          #+#    #+#             */
/*   Updated: 2022/07/11 18:17:59 by ferncarv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*count_line(char *str)
{
	int		i;
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
	static char	*str[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	n_by = 1;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (n_by > 0 && ft_strchr(str[fd], '\n') == 0)
	{
		n_by = read(fd, buffer, BUFFER_SIZE);
		if (n_by == -1)
			free(buffer);
		if (n_by == -1)
			return (NULL);
		buffer[n_by] = '\0';
		str[fd] = ft_strjoin(str[fd], buffer);
	}
	free(buffer);
	line = count_line(str[fd]);
	str[fd] = get_rest(str[fd]);
	return (line);
}
