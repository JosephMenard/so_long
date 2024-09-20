/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:15:36 by jmenard           #+#    #+#             */
/*   Updated: 2024/09/19 12:12:55 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_ber(char *file_name)
{
	size_t	len;
	char	*ret;

	len = ft_strlen(file_name);
	if (len < 5 || (file_name[0] == '.' && file_name[1] != '/'))
		return (1);
	ret = ft_strnstr(file_name, ".ber", len + 1);
	if (!ret)
		return (1);
	return (0);
}

int	is_square(char **map, t_game *struc)
{
	int	i;
	int	l;
	int	j;

	i = 0;
	while (map[i])
	{
		l = ft_strlen(map[i]);
		if (map[i][l - 1] == '\n')
			l--;
		if (l != struc->largeur)
			return (1);
		i++;
	}
	i = 0;
	j = 0;
	if (check_char(map) == 1)
		return (1);
	return (0);
}

void	count_map(char *file_name, t_game *struc)
{
	char	*temp;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		error_count_map(2, NULL, fd);
	temp = malloc(1 * sizeof(char *));
	if (!temp)
		error_count_map(4, temp, fd);
	while (read(fd, temp, 1) != 0)
	{
		if (temp[0] == '\n' || temp[0] == '\0')
		{
			struc->hauteur = struc->hauteur + 1;
			struc->largeur = 0;
		}
		struc->largeur = struc->largeur + 1;
	}
	struc->largeur = struc->largeur - 1;
	struc->hauteur = struc->hauteur + 1;
	if (struc->largeur <= 3 || struc->hauteur <= 3)
		error_count_map(3, temp, fd);
	close(fd);
	free(temp);
}

int	check_char(char **map)
{
	int	j;
	int	i;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] != '0' && map[j][i] != '1' && map[j][i] != 'C'
			&& map[j][i] != 'E' && map[j][i] != 'P'
			&& map[j][i] != '\n' && map[j][i] != 'X')
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

void	check_xpm(t_game *struc)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!struc->img_wall)
		i++;
	if (!struc->img_empty)
		i = 2;
	if (!struc->img_exit_o)
		i = 3;
	if (!struc->img_exit_c)
		i = 4;
	if (!struc->img_collectible)
		i = 5;
	if (!struc->img_died)
		i = 6;
	while (j < 4)
	{
		if (!struc->img_ennemi[j] || !struc->img_player[j])
			i = 7;
		j++;
	}
	if (i > 0)
		error_parsing(8, struc);
}
