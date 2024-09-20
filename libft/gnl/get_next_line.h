/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:30:00 by jmenard           #+#    #+#             */
/*   Updated: 2024/09/13 13:33:16 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE H

# include<unistd.h>
# include<fcntl.h>
# include<stdlib.h>
# include<stdio.h>
# include<string.h>
# include<stdarg.h>
# include<limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*line_read(int fd, char *buffer);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		isline(char *buffer);
int		isline_bis(char *buffer);
int		ft_strle(const char *str);
char	*ft_newstr(char const *s1, char const *s2, int s1_len, int s2_len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*do_malloc(char *buf);

#endif