/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:34:57 by schennal          #+#    #+#             */
/*   Updated: 2023/03/06 19:35:31 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int			ft_strlen(const char *s);

char		*ft_strdup(const char *s1);

char		*ft_strchr(const char *s, int c);

char		*ft_strjoin(char const *s1, char const *s2);

char		*ft_substr(char const *s, unsigned int start, size_t len);

char		*get_next_line(int fd);

#endif