/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:32:26 by schennal          #+#    #+#             */
/*   Updated: 2023/03/07 21:57:42 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>

static char	*ft_readline(int fd, char *buf, char *string)
{
	int		retval;
	char	*temp;

	retval = 1;
	while (retval != 0)
	{
		retval = read(fd, buf, BUFFER_SIZE);
		if (retval == -1)
			return (0);
		else if (retval == 0)
			break ;
		buf[retval] = '\0';
		if (!string)
			string = ft_strdup("");
		temp = string;
		string = ft_strjoin(temp, buf);
		free(temp);
		temp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (string);
}

static char	*ft_linebreaker(char *mystr)
{
	size_t	i;
	char	*line_to_op;

	i = 0;
	while (mystr[i] != '\n' && mystr[i] != '\0')
		i++;
	line_to_op = ft_substr(mystr, i + 1, ft_strlen(mystr) - i);
	if (*line_to_op == '\0')
	{
		free(line_to_op);
		line_to_op = NULL;
	}
	mystr[i + 1] = '\0';
	return (line_to_op);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char	*str1[1024];
	size_t		bufsize;

	bufsize = (size_t)BUFFER_SIZE;
	if (fd < 0 || bufsize <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (bufsize + 1));
	if (!buf)
		return (NULL);
	line = ft_readline(fd, buf, str1[fd]);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	str1[fd] = ft_linebreaker(line);
	return (line);
}

int	main(void)
{
	char	*line;
	int		i;
	int		fd;
	fd = open("test.txt", O_RDONLY);
	i = 1;
	while (i <= 7)
	{
		line = get_next_line(fd);
		printf("From test.txt line = %d: %s\n", i, line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
