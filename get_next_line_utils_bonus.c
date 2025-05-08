/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:34:17 by schennal          #+#    #+#             */
/*   Updated: 2023/03/06 19:36:01 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		slen;
	int		i;
	char	*copy;	

	i = 0;
	slen = ft_strlen(s1);
	copy = (char *)malloc(sizeof(char) * slen + 1);
	if (!copy)
		return (0);
	while (s1[i] != 0 && i < slen)
	{
		copy[i] = s1[i];
		i++;
	}
	copy[slen] = '\0';
	return (copy);
}

char	*ft_strchr(const char *s, int c)
{
	if (c == '\0')
		return ((char *)(s + ft_strlen(s)));
	while (*s)
	{
		if (*s == (char) c)
			return ((char *)s);
		s++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		s1len;
	int		s2len;
	int		totlen;
	char	*answer;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	totlen = s1len + s2len;
	answer = (char *)malloc(sizeof(char) * totlen + 1);
	if (!answer)
		return (0);
	while (s1[i] != 0 && i < s1len)
	{
		answer[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2 != 0 && i < s2len && s1len < totlen)
		answer[s1len++] = s2[i++];
	answer[s1len] = '\0';
	return (answer);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (str == 0)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}
