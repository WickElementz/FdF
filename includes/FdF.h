/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   FdF.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/12 13:35:57 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/28 16:46:49 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"
# include "./GNL/get_next_line.h"
# include "minilibx_macOS/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

/*
** Definition d'un chemin plus direct a notre liste chainée dans notre structure
*/

# define INDEX env->index

/*
** Definition des codes couleurs pour Bresenham
*/

# define TEAL 0x25FDE9
# define ROSE 0xFD6C9E
# define RED 0xFF0000
# define YELLOW 0xFFFF00
# define WHITE 0xFFFFFF
# define BLUE 0x0000FF
# define ORANGE 0xED7F10
# define GREEN 0x00FF00
# define DARKGREEN 0x01796F

/*
** Définition de raccourci pour les keycodes
** (Augmente la lisibilité du code)
*/

# define ECHAP 53
# define LEFT_CLICK 1
# define RIGHT_CLICK 2
# define SCROLL_UP 4
# define SCROLL_DOWN 5

/*
** Liste chainée utilisée pour stocker notre fichier
*/

typedef struct      s_lst
{
	struct s_lst    *next;
	char            *s;
}                    t_lst;

/*
** Liste chainée utilisée pour indexer notre fichier
*/

typedef struct      s_index
{
	int             z;
	int             x;
	int             y;
	struct s_index  *next;
}                   t_index;

/*
** Variable d'environnement utilisée pour stocker toutes les valeurs importantes
** ainsi que les ptr sur void utilisées par la MLX
** x1 & y1 = Coordonnée de départ de mon tracé
** e & e1 & e2 = Float utilisés par Bresenham
** size_x & size_y = Taille de la fenêtre
** zoom = Definie la taille de mon tracé de base
** number_x & number_y = Nombres de droites a tracer en X et en Y
** mlx_ptr, win_ptr, img = Identifiants utilisés par la MLX
*/

typedef struct      s_env
{
	t_index			*index;
	int				x1;
	int				y1;
	float			e;
	float			e1;
	float			e2;
	int				size_x;
	int				size_y;
	int				zoom;
	int				number_x;
	int				number_y;
	void            *mlx_ptr;
	void            *win_ptr;
	void			*img;
}                   t_env;

t_env				*check(t_lst *list, t_env *env);
t_lst				*free_list(t_lst *list);
t_env				*free_env(t_env *env);
t_index				*free_index(t_index	*index);
t_index				*init_index(void);
t_env				*init_env(void);
t_lst				*init_lst(void);
void				bresenham_1(int x, int y, t_env *env);
void				bresenham_2(int x, int y, t_env *env);
void				bresenham_3(int x, int y, t_env *env);
void				bresenham_4(int x, int y, t_env *env);
void				bresenham_5(int x, int y, t_env *env);
void				bresenham_6(int x, int y, t_env *env);
void				bresenham_7(int x, int y, t_env *env);
void				bresenham_8(int x, int y, t_env *env);
void				bresenham_line(int x, int y, t_env *env);
void				check_bresenham(int x2, int y2, t_env *env);
void				trace(t_env *env);
void				choose_trade(t_env *env, t_index *index, t_index *up);
void				find_zoom(t_env *env);
void				mlxinit(t_env *env);
void 				error(void);

#endif