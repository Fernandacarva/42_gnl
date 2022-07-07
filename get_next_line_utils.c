/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferncarv <ferncarv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:26:21 by ferncarv          #+#    #+#             */
/*   Updated: 2022/07/06 18:25:24 by ferncarv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != c)
	{
		if (!*s)
			return ((char *) '\0');
		s++;
	}	
	return ((char *)s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			aux1;
	size_t			aux2;
	size_t			sum;
	char			*str;

	if (!s1 || !s2)
		return (NULL);
	sum = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(sum);
	aux1 = 0;
	aux2 = 0;
	if (str == NULL)
		return (NULL);
	while (s1[aux1] != '\0')
	{
		str[aux1] = s1[aux1];
		aux1++;
	}
	while (s2[aux2] != '\0')
	{
		str[aux1 + aux2] = s2[aux2];
		aux2++;
	}
	str[aux1 + aux2] = '\0';
	return (str);
}

