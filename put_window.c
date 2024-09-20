/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:20:58 by jmenard           #+#    #+#             */
/*   Updated: 2024/09/19 16:51:29 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_game *struc)
{
	struc->img_wall
		= mlx_xpm_file_to_image
		(struc->mlx, IMG_WALL, &struc->img_l, &struc->img_h);
	struc->img_collectible
		= mlx_xpm_file_to_image
		(struc->mlx, IMG_COLLECTIBLE, &struc->img_l, &struc->img_h);
	struc->img_exit_c
		= mlx_xpm_file_to_image
		(struc->mlx, IMG_EXIT_C, &struc->img_l, &struc->img_h);
	struc->img_exit_o
		= mlx_xpm_file_to_image
		(struc->mlx, IMG_EXIT_O, &struc->img_l, &struc->img_h);
	struc->img_empty
		= mlx_xpm_file_to_image
		(struc->mlx, IMG_EMPTY, &struc->img_l, &struc->img_h);
	struc->img_died
		= mlx_xpm_file_to_image
		(struc->mlx, IMG_DIED, &struc->img_l, &struc->img_h);
	img_ennemi(struc);
	img_perso(struc);
	check_xpm(struc);
}

void	render_map(t_game *struc, int j, int i)
{
	char	str[13];

	while (j < struc->hauteur)
	{
		i = 0;
		while (i < struc->largeur)
		{
			render_map_bis(struc, j, i);
		i++;
		}
	j++;
	}
	snprintf(str, sizeof(str), "Moves = %d", struc->count_mouvement);
	mlx_string_put(struc->mlx, struc->mlx_win,
		1050, 50, 0xFFFF00, str);
}

void	render_map_bis(t_game *struc, int j, int i)
{
	if (struc->map[j][i] == '1')
		mlx_put_image_to_window
		(struc->mlx, struc->mlx_win, struc->img_wall, i * 60, j * 60);
	else if (struc->map[j][i] == 'C')
		mlx_put_image_to_window
		(struc->mlx, struc->mlx_win
		, struc->img_collectible, i * 60, j * 60);
	else if ((struc->map[j][i] == 'E'
		||struc->map[j][i] == 'U') && struc->count_collectible != 0)
		mlx_put_image_to_window
		(struc->mlx, struc->mlx_win, struc->img_exit_c, i * 60, j * 60);
	else if ((struc->map[j][i] == 'E'
		||struc->map[j][i] == 'U') && struc->count_collectible == 0)
		mlx_put_image_to_window
		(struc->mlx, struc->mlx_win, struc->img_exit_o, i * 60, j * 60);
	else
		mlx_put_image_to_window
		(struc->mlx, struc->mlx_win, struc->img_empty, i * 60, j * 60);
}

int	handle_keypress(int keycode, t_game *struc)
{
	if (struc->finish > 0)
		close_window(struc, 0);
	if (keycode == ESC_KEY)
		close_window(struc, 0);
	if (keycode == W_KEY)
		mouvements(struc, 'W');
	if (keycode == S_KEY)
		mouvements_bis(struc, 'S');
	if (keycode == A_KEY)
		mouvements_bis(struc, 'A');
	if (keycode == D_KEY)
		mouvements(struc, 'D');
	render_map(struc, 0, 0);
	return (0);
}

int	close_window(t_game *struc, int type)
{
	ft_free_img(struc);
	if (struc->mlx && struc->mlx_win)
		mlx_destroy_window(struc->mlx, struc->mlx_win);
	if (struc->mlx)
	{
		mlx_destroy_display(struc->mlx);
		free(struc->mlx);
	}
	ft_free_tab(struc->map);
	exit(type);
	return (0);
}
