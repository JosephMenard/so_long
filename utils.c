/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:21:42 by jmenard           #+#    #+#             */
/*   Updated: 2024/09/19 14:42:52 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_stack(t_game *struc)
{
	printf("name_map ; %s \n", struc->name_map);
	printf("largeur ; %d \n", struc->largeur);
	printf("hauteur ; %d \n", struc->hauteur);
	printf("player_h ; %d \n", struc->player_h);
	printf("player_l ; %d \n", struc->player_l);
	printf("collectible ; %d \n", struc->count_collectible);
	printf("mouvements ; %d \n", struc->count_mouvement);
	printf("is finish ? ; %d \n", struc->finish);
	printf("ennemi_h ; %d \n", struc->ennemi_h);
	printf("ennemi_l ; %d \n", struc->ennemi_l);
	printf("finish ; %d \n", struc->finish);
	print_map(struc->map);
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	printf("MAP ; \n");
	while (map[i])
	{
		printf("%s", map[i]);
		i++;
	}
	printf("\n");
}

void	render_door(t_game *struc, int h, int l)
{
	if (struc->map[h - 1][l] != '1')
		struc->map[h - 1][l] = '0';
	if (struc->map[h + 1][l] != '1')
		struc->map[h + 1][l] = '0';
	if (struc->map[h][l - 1] != '1')
		struc->map[h][l - 1] = '0';
	if (struc->map[h][l + 1] != '1')
		struc->map[h][l + 1] = '0';
	struc->map[h][l] = 'P';
}
