/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvements.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:32:01 by jmenard           #+#    #+#             */
/*   Updated: 2024/09/19 14:34:00 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mouvements(t_game *struc, char letter)
{
	if (letter == 'W')
	{
		if (check_mov(struc, struc->player_l, struc->player_h - 1, 1) == 1)
			return ;
		else if (check_mov(struc, struc->player_l, struc->player_h - 1, 0) == 2)
			struc->map[struc->player_h - 1][struc->player_l] = 'U';
		else
			struc->map[struc->player_h - 1][struc->player_l] = 'P';
		if (struc->map[struc->player_h][struc->player_l] != 'U')
			struc->map[struc->player_h][struc->player_l] = '0';
		struc->player_h--;
	}
	if (letter == 'D')
	{
		if (check_mov(struc, struc->player_l + 1, struc->player_h, 1) == 1)
			return ;
		else if (check_mov(struc, struc->player_l + 1, struc->player_h, 0) == 2)
			struc->map[struc->player_h][struc->player_l + 1] = 'U';
		else
			struc->map[struc->player_h][struc->player_l + 1] = 'P';
		if (struc->map[struc->player_h][struc->player_l] != 'U')
			struc->map[struc->player_h][struc->player_l] = '0';
		struc->player_l++;
	}
	struc->count_mouvement++;
}

void	mouvements_bis(t_game *struc, char letter)
{
	if (letter == 'S')
	{
		if (check_mov(struc, struc->player_l, struc->player_h + 1, 1) == 1)
			return ;
		else if (check_mov(struc, struc->player_l, struc->player_h + 1, 0) == 2)
			struc->map[struc->player_h + 1][struc->player_l] = 'U';
		else
			struc->map[struc->player_h + 1][struc->player_l] = 'P';
		if (struc->map[struc->player_h][struc->player_l] != 'U')
			struc->map[struc->player_h][struc->player_l] = '0';
		struc->player_h++;
	}
	if (letter == 'A')
	{
		if (check_mov(struc, struc->player_l - 1, struc->player_h, 1) == 1)
			return ;
		else if (check_mov(struc, struc->player_l - 1, struc->player_h, 0) == 2)
			struc->map[struc->player_h][struc->player_l - 1] = 'U';
		else
			struc->map[struc->player_h][struc->player_l - 1] = 'P';
		if (struc->map[struc->player_h][struc->player_l] != 'U')
			struc->map[struc->player_h][struc->player_l] = '0';
		struc->player_l--;
	}
	struc->count_mouvement++;
}

int	check_mov(t_game *struc, int l, int h, int c)
{
	if (struc->map[h][l] == 'X')
		struc->finish = 1;
	if (struc->map[h][l] == 'E' || struc->map[h][l] == 'U')
	{
		if (struc->count_collectible == 0)
		{
			render_door(struc, h, l);
			struc->finish = 1;
			render_map(struc, 0, 0);
		}
		else if (struc->count_collectible > 0)
			return (2);
	}
	if (struc->map[h][l] == '1')
		return (1);
	if (struc->map[h][l] == 'C' && c == 1)
	{
		struc->count_collectible--;
		struc->count_angry++;
	}
	return (0);
}
