/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:16:31 by jmenard           #+#    #+#             */
/*   Updated: 2024/09/19 16:44:36 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_count_map(int type, char *to_free, int fd)
{
	ft_putstr_fd("Error\n", 2);
	if (type == 2)
		ft_putstr_fd("No valid files \n", 2);
	if (type == 3)
		ft_putstr_fd("Wrong format of Map \n", 2);
	if (type == 4)
		ft_putstr_fd("Fail of Malloc \n", 2);
	if (type == 5)
		ft_putstr_fd("To much args ! just 1 map is allowed \n", 2);
	if (type == 6)
		ft_putstr_fd("The file must be a .ber \n", 2);
	if (to_free != NULL)
		free(to_free);
	if (fd > 0)
		close(fd);
	exit(1);
}

void	error_create_map(int type, char **to_free, int fd)
{
	ft_putstr_fd("Error\n", 2);
	if (type == 2)
		ft_putstr_fd("No valid files \n", 2);
	if (type == 3)
		ft_putstr_fd("Wrong format of Map \n", 2);
	if (type == 4)
		ft_putstr_fd("Fail of Malloc 2\n", 2);
	if (fd > 0)
		close(fd);
	if (to_free != NULL)
		ft_free_tab(to_free);
	exit(1);
}

void	error_parsing(int type, t_game *struc)
{
	ft_putstr_fd("Error\n", 2);
	if (type == 0)
		ft_putstr_fd("Map no surrounded by wall \n", 2);
	if (type == 1)
		ft_putstr_fd("No player on the map \n", 2);
	if (type == 2)
		ft_putstr_fd("To much player on the map \n", 2);
	if (type == 3)
		ft_putstr_fd("No exit of the map \n", 2);
	if (type == 4)
		ft_putstr_fd("To much exit of the map \n", 2);
	if (type == 5)
		ft_putstr_fd("No collectible \n", 2);
	if (type == 6)
		ft_putstr_fd("No valid path\n", 2);
	if (type == 7)
		ft_putstr_fd("To much ennemis\n", 2);
	if (type == 8)
	{
		ft_putstr_fd("Some images are not loading\n", 2);
		close_window(struc, 1);
	}
	ft_free_tab(struc->map);
	exit(1);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab != NULL)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}
