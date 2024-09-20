/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 15:56:13 by jmenard           #+#    #+#             */
/*   Updated: 2024/09/17 18:32:48 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_it(t_game *struc)
{	
	if (check_wall(struc) == 1)
		error_parsing(0, struc);
	if (check_p_e(struc, 'P') < 1)
		error_parsing(1, struc);
	else if (check_p_e(struc, 'P') > 1)
		error_parsing(2, struc);
	if (check_p_e(struc, 'E') < 1)
		error_parsing(3, struc);
	else if (check_p_e(struc, 'E') > 1)
		error_parsing(4, struc);
	if (check_p_e(struc, 'C') < 1)
		error_parsing(5, struc);
	parse_bis(struc);
}

void	parse_bis(t_game *struc)
{
	if (check_p_e(struc, 'X') > 1)
		error_parsing(7, struc);
	if (check_p_e(struc, 'C') >= 1)
		struc->count_collectible = check_p_e(struc, 'C');
	fluid_fill(struc, struc->player_l, struc->player_h);
	if (check_p_e(struc, 'C') != 0)
		error_parsing(6, struc);
	if (check_p_e(struc, 'E') != 0)
		error_parsing(6, struc);
	if (check_p_e(struc, 'P') != 0)
		error_parsing(6, struc);
	ft_free_tab(struc->map);
	create_map(struc->name_map, struc);
}

int	check_wall(t_game *struc)
{	
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (struc->map[0][i])
	{
		if (struc->map[0][i++] != '1' && struc->map[0][i] != '\0')
			return (1);
	}
	while (struc->map[j + 1])
	{
		if (struc->map[j][0] != '1' || struc->map[j][struc->largeur - 1] != '1')
			return (1);
		j++;
	}
	i = 0;
	while (struc->map[j][i])
	{
		if (struc->map[j][i] != '1' && struc->map[j][i] != '\0')
			return (1);
		i++;
	}
	return (0);
}

int	check_p_e(t_game *struc, char letter)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	j = 0;
	player = 0;
	while (struc->map[j])
	{
		i = 0;
		while (struc->map[j][i])
		{
			player += check_bis(struc, letter, j, i);
			i++;
		}
		j++;
	}
	return (player);
}

void	fluid_fill(t_game *struc, int i, int j)
{
	if (i < 0 || j < 0 || i > struc->largeur - 1 || j > struc->hauteur - 1
		|| struc->map[j][i] == '1' || struc->map[j][i] == '@')
		return ;
	else
	{
		struc->map[j][i] = '@';
		if (i < struc->largeur - 1)
			fluid_fill(struc, i + 1, j);
		if (j < struc->hauteur - 1)
			fluid_fill(struc, i, j + 1);
		if (i > 1)
			fluid_fill(struc, i - 1, j);
		if (j > 1)
			fluid_fill(struc, i, j - 1);
	}
}
