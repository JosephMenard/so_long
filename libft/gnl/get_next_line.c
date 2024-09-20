/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:29:38 by jmenard           #+#    #+#             */
/*   Updated: 2024/09/13 13:34:01 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

int	isline(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	isline_bis(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		if (buffer[i + 1] == '\0')
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

char	*line_read(int fd, char *buffer)
{
	char	*buffer_temp;
	char	*buffer_bis;
	int		read_len;

	read_len = 2;
	buffer_temp = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buffer_temp)
		return (NULL);
	if (!buffer)
		buffer = do_malloc(buffer);
	if (!buffer)
		return (free(buffer_temp), NULL);
	while (read_len > 0)
	{
		read_len = read(fd, buffer_temp, BUFFER_SIZE);
		if (read_len == -1)
			return (free(buffer_temp), NULL);
		buffer_temp[read_len] = '\0';
		buffer_bis = buffer;
		buffer = ft_strjoin(buffer_bis, buffer_temp);
		free(buffer_bis);
		if (isline(buffer_temp) >= 0 || read_len <= 0 || !buffer)
			break ;
	}
	return (free(buffer_temp), buffer);
}

char	*do_malloc(char *buf)
{
	buf = malloc(1 * sizeof(char));
	if (!buf)
		return (NULL);
	buf[0] = '\0';
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*ret;
	char		*bis;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(buf), buf = NULL);
	bis = line_read(fd, buf);
	if (!bis)
		return (NULL);
	ret = ft_substr(bis, 0, isline_bis(bis) + 1);
	if (!ret)
		return (free(bis), free(buf), buf = NULL);
	buf = ft_substr(bis, ft_strle(ret), ft_strle(bis) - ft_strle(ret));
	if (!buf)
		return (free(ret), free(bis), free(buf), buf = NULL);
	if (ret[0] == '\0')
		return (free(ret), free(buf), free(bis), buf = NULL);
	return (free(bis), ret);
}

// int	main(void)
// {
// 	int		fd;
// 	int		i;
// 	char	*result;

// 	i = 1;
// 	fd = open("get_next_line.c", O_RDONLY);
// 	while (i <= 172)
// 	{
// 		result = get_next_line(fd);
// 		printf("%d -> %s", i, result);
// 		free(result);
// 		i++;
// 	}
// 	close(fd);
// 	return (0);
// }

// 	result = get_next_line(fd);
// 	printf("%d -> %s", i, result);
// 	free(result);
// 	printf("\n");
// 	fd = open("read_error.txt", O_RDONLY);
// 	i++;
// 	while (i <= 8)
// 	{
// 		result = get_next_line(fd);
// 		printf("%d -> %s", i, result);
// 		free(result);
// 		if (i == 7)
// 			printf("\n");
// 		i++;
// 	}
// 	close(fd);
// 	printf("\n=================================================\n");
// 	i = 1;
// 	fd = open("test.txt", O_RDONLY);
// 	while (i <= 54)
// 	{
// 		result = get_next_line(fd);
// 		printf("%d -> %s", i, result);
// 		free(result);
// 		i++;
// 	}
// 	close(fd);
// 	printf("\n=================================================\n");
// 	i = 1;
// 	fd = open("test3.txt", O_RDONLY);
// 	while (i <= 20)
// 	{
// 		result = get_next_line(fd);
// 		printf("%d -> %s", i, result);
// 		free(result);
// 		i++;
// 	}
// 	close(fd);
// 	printf("\n");
// 	return (0);
// }
