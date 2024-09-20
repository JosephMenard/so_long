/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:37:20 by jmenard           #+#    #+#             */
/*   Updated: 2024/09/19 14:11:24 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	animation_en(t_game *struc)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 11000)
		{
			if (struc->ennemi_h != 0)
			{
				mlx_put_image_to_window(struc->mlx,
					struc->mlx_win, struc->img_ennemi[i],
					struc->ennemi_l * 60, struc->ennemi_h * 60);
			}
			mlx_put_image_to_window(struc->mlx,
				struc->mlx_win, struc->img_player[i],
				struc->player_l * 60, struc->player_h * 60);
			j++;
		}
		i++;
	}
	anim_en_bis(struc);
	return (1);
}

void	anim_en_bis(t_game *struc)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (struc->ennemi_h != 0 && struc->finish == 0)
	{
		while (j < 5000)
			j++;
		while (i < struc->count_angry + 1)
		{
			moove_ennemi(struc);
			render_map(struc, 0, 0);
			i++;
		}
	}
	else if (struc->finish == 2)
	{
		mlx_put_image_to_window(struc->mlx, struc->mlx_win,
			struc->img_died,
			60 * (struc->largeur / 3), 60 * (struc->hauteur / 3));
	}
	if (struc->count_collectible == 0)
		struc->count_angry += 5;
}

void	img_perso(t_game *struc)
{
	struc->img_player[0]
		= mlx_xpm_file_to_image
		(struc->mlx, IMG_USER_1, &struc->img_l, &struc->img_h);
	struc->img_player[1]
		= mlx_xpm_file_to_image
		(struc->mlx, IMG_USER_2, &struc->img_l, &struc->img_h);
	struc->img_player[2]
		= mlx_xpm_file_to_image
		(struc->mlx, IMG_USER_3, &struc->img_l, &struc->img_h);
	struc->img_player[3]
		= mlx_xpm_file_to_image
		(struc->mlx, IMG_USER_4, &struc->img_l, &struc->img_h);
	struc->img_player[4]
		= mlx_xpm_file_to_image
		(struc->mlx, IMG_USER_4, &struc->img_l, &struc->img_h);
}
