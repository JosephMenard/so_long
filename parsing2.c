/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:16:43 by jmenard           #+#    #+#             */
/*   Updated: 2024/09/19 15:17:26 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_bis(t_game *struc, char letter, int j, int i)
{
	int	player;

	player = 0;
	if (struc->map[j][i++] == letter)
	{
		if (letter == 'P')
		{
			struc->player_h = j;
			struc->player_l = i - 1;
		}
		if (letter == 'X')
		{
			struc->ennemi_h = j;
			struc->ennemi_l = i - 1;
		}
		player++;
	}
	return (player);
}

void	ft_free_img(t_game *struc)
{
	int	i;

	i = 0;
	if (struc->img_collectible)
		mlx_destroy_image(struc->mlx, struc->img_collectible);
	if (struc->img_empty)
		mlx_destroy_image(struc->mlx, struc->img_empty);
	if (struc->img_exit_c)
		mlx_destroy_image(struc->mlx, struc->img_exit_c);
	if (struc->img_exit_o)
		mlx_destroy_image(struc->mlx, struc->img_exit_o);
	if (struc->img_wall)
		mlx_destroy_image(struc->mlx, struc->img_wall);
	if (struc->img_died)
		mlx_destroy_image(struc->mlx, struc->img_died);
	while (i <= 4)
	{
		if (struc->img_ennemi[i])
			mlx_destroy_image(struc->mlx, struc->img_ennemi[i]);
		if (struc->img_player[i])
			mlx_destroy_image(struc->mlx, struc->img_player[i]);
		i++;
	}
}
