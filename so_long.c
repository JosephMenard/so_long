/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:58:06 by jmenard           #+#    #+#             */
/*   Updated: 2024/09/19 16:25:25 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_map(char *file_name, t_game *struc)
{
	int		fd;
	int		i;
	char	**map;

	i = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		error_create_map(2, NULL, fd);
	map = (char **)malloc((struc->hauteur + 1) * sizeof(char *));
	if (!map)
		error_create_map(4, map, fd);
	map[0] = get_next_line(fd);
	while (map[i])
		map[++i] = get_next_line(fd);
	map[i] = NULL;
	close(fd);
	if (i != struc->hauteur)
		error_create_map(4, map, 0);
	if (is_square(map, struc) == 1)
		error_create_map(3, map, 0);
	struc->name_map = file_name;
	struc->map = map;
}

void	so_long(t_game *struc)
{
	struc->mlx = mlx_init();
	if (!struc->mlx)
		close_window(struc, 1);
	struc->mlx_win = mlx_new_window
		(struc->mlx, 60 * (struc->largeur),
			60 * (struc->hauteur), "so_long");
	if (!struc->mlx_win)
		close_window(struc, 1);
	mlx_hook(struc->mlx_win, 2, 1L << 0, handle_keypress, struc);
	mlx_hook
	(struc->mlx_win, DestroyNotify, StructureNotifyMask, close_window, struc);
	load_images(struc);
	render_map(struc, 0, 0);
	mlx_loop_hook(struc->mlx, animation_en, struc);
	mlx_loop(struc->mlx);
}

int	main(int argc, char **argv, char **env)
{
	t_game	struc;

	if (argc != 2)
		error_count_map(5, NULL, 0);
	if (is_ber(argv[1]) == 1)
		error_count_map(6, NULL, 0);
	if (!env || !env[0])
		exit (1);
	ft_bzero(&struc, sizeof(t_game));
	count_map(argv[1], &struc);
	create_map(argv[1], &struc);
	parse_it(&struc);
	so_long(&struc);
	return (0);
}
