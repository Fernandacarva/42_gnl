/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferncarv <ferncarv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:26:21 by ferncarv          #+#    #+#             */
/*   Updated: 2022/07/11 18:41:42 by ferncarv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

int	ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s != c)
	{
		if (!*s)
			return (0);
		s++;
	}	
	return (1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t			aux1;
	size_t			aux2;
	char			*str;

	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	aux1 = -1;
	aux2 = 0;
	if (str == NULL)
		return (NULL);
	while (++aux1, s1[aux1] != '\0')
		str[aux1] = s1[aux1];
	while (s2[aux2] != '\0')
	{
		str[aux1 + aux2] = s2[aux2];
		aux2++;
	}
	str[aux1 + aux2] = '\0';
	free(s1);
	return (str);
}
