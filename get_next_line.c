/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferncarv <ferncarv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:36:21 by ferncarv          #+#    #+#             */
/*   Updated: 2022/07/07 06:26:07 by ferncarv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*count_line(char *str)
{
    int     i;
	char	*aux;

    i = 0;
	if (!str[i])
		return (0);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	aux = malloc((i + 2) * sizeof(char));
	if (!aux)
		return (0);
	while (str[i] != '\n' && str[i] != '\0')
	{
		aux[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		aux[i++] = '\n';
	aux[i] = '\0';
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
	if (!str[i])
	{
		free(aux);
		return (0);
	}
	j_p = 0;
	aux = malloc((ft_strlen(str) - i + 1) * sizeof(char));
	if (!aux)
		return (0);
	i++;
	while (str[i] != '\0')
		aux[j_p++] = str[i++];
	aux[j_p] = '\0';
	free(str);
	return (aux);
}

static char	*get_read(int fd, char *str)
{

