/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:58:44 by jmenard           #+#    #+#             */
/*   Updated: 2024/09/19 16:36:04 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG H

# include<unistd.h>
# include<fcntl.h>
# include<stdlib.h>
# include<stdio.h>
# include<string.h>
# include<stdarg.h>
# include<limits.h>
# include"./libft/libft.h"
# include"./minilibx-linux/mlx.h"
# include"X11/X.h"
# include"X11/keysym.h"

# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define ESC_KEY 65307
# define IMG_WALL "ressources/murs.xpm"
# define IMG_EXIT_O "ressources/porte_ouverte.xpm"
# define IMG_EXIT_C "ressources/porte_fermer.xpm"
# define IMG_EMPTY "ressources/sol.xpm"
# define IMG_COLLECTIBLE "ressources/collectible.xpm"
# define IMG_ENNEMI_0 "ressources/ennemi_0.xpm"
# define IMG_ENNEMI_1 "ressources/ennemi_1.xpm"
# define IMG_ENNEMI_2 "ressources/ennemi_2.xpm"
# define IMG_ENNEMI_3 "ressources/ennemi_3.xpm"
# define IMG_ENNEMI_4 "ressources/ennemi_4.xpm"
# define IMG_DIED "ressources/u_died_3.xpm"
# define IMG_USER_1 "ressources/perso1.xpm"
# define IMG_USER_2 "ressources/perso2.xpm"
# define IMG_USER_3 "ressources/perso3.xpm"
# define IMG_USER_4 "ressources/perso4.xpm"

typedef struct s_game
{
	void	*img_wall;
	void	*img_player[5];
	void	*img_collectible;
	void	*img_exit_c;
	void	*img_exit_o;
	void	*img_empty;
	void	*img_ennemi[5];
	void	*img_died;
	void	*mlx_win;
	void	*mlx;
	char	*name_map;
	char	**map;
	int		hauteur;
	int		largeur;
	int		player_h;
	int		player_l;
	int		ennemi_h;
	int		ennemi_l;
	int		img_h;
	int		img_l;
	int		count_mouvement;
	int		count_collectible;
	int		count_angry;
	int		finish;
}	t_game;

//error.c
void	error_count_map(int type, char *malloc, int fd);
void	error_create_map(int type, char **to_free, int fd);
void	error_parsing(int type, t_game *struc);
void	ft_free_tab(char **tab);

//checking.c
int		is_ber(char *file_name);
int		is_square(char **map, t_game *struc);
void	count_map(char *file_name, t_game *struc);
int		check_char(char **map);
void	check_xpm(t_game *struc);

//so_long.c
void	create_map(char *file_name, t_game *struc);
void	so_long(t_game *struc);

//parsing.c
void	parse_it(t_game *struc);
void	parse_bis(t_game *struc);
int		check_wall(t_game *struc);
int		check_p_e(t_game *struc, char letter);
void	fluid_fill(t_game *struc, int i, int j);

//parsing2.c
int		check_bis(t_game *struc, char letter, int j, int i);
void	ft_free_img(t_game *struc);

//utils.c
void	print_stack(t_game *struc);
void	print_map(char **map);
void	render_door(t_game *struc, int h, int l);

//put_window.c
void	load_images(t_game *struc);
void	render_map(t_game *struc, int j, int i);
void	render_map_bis(t_game *struc, int j, int i);
int		handle_keypress(int keycode, t_game *struc);
int		close_window(t_game *struc, int type);

//mouvements.c
void	mouvements(t_game *struc, char letter);
void	mouvements_bis(t_game *struc, char letter);
int		check_mov(t_game *struc, int largeur, int hauteur, int c);

//ennemi.c
void	moove_ennemi_bis(t_game *struc, int nb);
int		check_mov_en(t_game *struc, int largeur, int hauteur);
void	moove_ennemi(t_game *struc);
void	img_ennemi(t_game *struc);

//animation.c
int		animation_en(t_game *struc);
void	anim_en_bis(t_game *struc);
void	img_perso(t_game *struc);

#endif