/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:55:08 by jmenard           #+#    #+#             */
/*   Updated: 2024/09/18 15:38:33 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	gestion_ennemi(t_game *struc)
// {
// }

void	moove_ennemi(t_game *struc)
{
	int	nb;

	nb = rand() % 4;
	if (nb >= 2)
		moove_ennemi_bis(struc, nb);
	if (nb == 0)
	{
		if (check_mov_en(struc, struc->ennemi_l, struc->ennemi_h + 1) == 1)
			return ;
		struc->map[struc->ennemi_h + 1][struc->ennemi_l] = 'X';
		struc->map[struc->ennemi_h][struc->ennemi_l] = '0';
		struc->ennemi_h++;
	}
	if (nb == 1)
	{
		if (check_mov_en(struc, struc->ennemi_l, struc->ennemi_h - 1) == 1)
			return ;
		struc->map[struc->ennemi_h - 1][struc->ennemi_l] = 'X';
		struc->map[struc->ennemi_h][struc->ennemi_l] = '0';
		struc->ennemi_h--;
	}
}

void	moove_ennemi_bis(t_game *struc, int nb)
{
	if (nb == 2)
	{
		if (check_mov_en(struc, struc->ennemi_l + 1, struc->ennemi_h) == 1)
			return ;
		struc->map[struc->ennemi_h][struc->ennemi_l + 1] = 'X';
		struc->map[struc->ennemi_h][struc->ennemi_l] = '0';
		struc->ennemi_l++;
	}
	if (nb == 3)
	{
		if (check_mov_en(struc, struc->ennemi_l - 1, struc->ennemi_h) == 1)
			return ;
		struc->map[struc->ennemi_h][struc->ennemi_l - 1] = 'X';
		struc->map[struc->ennemi_h][struc->ennemi_l] = '0';
		struc->ennemi_l--;
	}
}

int	check_mov_en(t_game *struc, int largeur, int hauteur)
{
	if (struc->map[hauteur][largeur] == '1'
	|| struc->map[hauteur][largeur] == 'E'
	|| struc->map[hauteur][largeur] == 'C'
	|| struc->map[hauteur][largeur] == 'U')
		return (1);
	if (struc->map[hauteur][largeur] == 'P')
	{
		struc->finish = 2;
		return (2);
	}
	return (0);
}

void	img_ennemi(t_game *struc)
{
	struc->img_ennemi[0]
		= mlx_xpm_file_to_image
		(struc->mlx, IMG_ENNEMI_0, &struc->img_l, &struc->img_h);
	struc->img_ennemi[1]
		= mlx_xpm_file_to_image
		(struc->mlx, IMG_ENNEMI_1, &struc->img_l, &struc->img_h);
	struc->img_ennemi[2]
		= mlx_xpm_file_to_image
		(struc->mlx, IMG_ENNEMI_2, &struc->img_l, &struc->img_h);
	struc->img_ennemi[3]
		= mlx_xpm_file_to_image
		(struc->mlx, IMG_ENNEMI_3, &struc->img_l, &struc->img_h);
	struc->img_ennemi[4]
		= mlx_xpm_file_to_image
		(struc->mlx, IMG_ENNEMI_4, &struc->img_l, &struc->img_h);
}
