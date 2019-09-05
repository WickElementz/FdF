/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/12 13:35:57 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/05 18:00:50 by jominodi    ###    #+. /#+    ###.fr     */
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
** Define pour la légende
*/

# define LEGEND "Appuyez sur TAB pour afficher / masquer la legende"
# define EXIT "Appuyez sur ECHAP pour fermer le programme"
# define LEG_KEYBOARD "Clavier:"
# define LEG_MOVE "W / A / S / D pour bouger la map"
# define LEG_COLOR "C pour changer la couleur de la map"
# define LEG_PERSP "Espace = change de perspective"
# define LEG_RESET "R = Reeinitialise la map"
# define LEG_MOUSE "Souris:"
# define LEG_ZOOM "Molette souris pour zoom / dezoom"
# define LEG_R_CLICK "Clic droit: selectionne un point A"
# define LEG_L_CLICK "Clic gauche: Trace une droite entre le point A et celui ci"

/*
** Definition des codes couleurs pour Les tracés
*/

# define RED_0		0x8A4040
# define RED_1		0xA93B3B
# define RED_2		0xD62525
# define BLUE_0		0x3D6980
# define BLUE_1		0x3B8BB4
# define BLUE_2		0x20A3E5
# define YELLOW_0	0x6F6A3A
# define YELLOW_1	0xAA9F38
# define YELLOW_2	0xE1CE20
# define GREEN_0	0x407847
# define GREEN_1	0x3AA948
# define GREEN_2	0x23E63B
# define WHITE		0xFFFFFF
# define BLUE_LEG	0x22A4C4
# define BROWN		0x996747

/*
** Définition de raccourci pour les keycodes
** (Augmente la lisibilité du code)
*/

# define ECHAP 53
# define LEFT_CLICK 1
# define RIGHT_CLICK 2
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define DASH 78
# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define SWITCH 49
# define RESET 15
# define SWITCH_COLOR 8
# define PLUS 69
# define MOINS 78
# define TAB 48

/*
** Liste chainée utilisée pour stocker notre fichier
*/

typedef struct		s_lst
{
	struct s_lst	*next;
	char			*s;
}					t_lst;

/*
** Liste chainée utilisée pour indexer notre fichier
*/

typedef struct		s_index
{
	int				z;
	int				x;
	int				y;
	struct s_index	*next;
}					t_index;

/*
** Variable d'environnement utilisée pour stocker toutes les valeurs importantes
** ainsi que les ptr sur void utilisées par la MLX
** x1 & y1 = Coordonnée de départ en x et y de mon tracé
** x & y = Utilisé pour savoir quel bresenham utiliser
** size_x & size_y = Taille de la fenêtre
** move_x & move_y = Utilisé pour le deplacement de la map
** len_x & len_y = Nombres de droites a tracer en X et en Y
** zoom = Definie la taille de mon tracé de base
** swc_c = Switch couleur
** swc = Switch perspective
** h = gere la puissance du relief
** leg = gere l'affichage / desaffichage de la legende
** color = Choisit la couleur a tracer
** e & e1 & e2 = Float utilisés par Bresenham
** mlx_ptr, win_ptr, img = Identifiants utilisés par la MLX
*/

typedef struct		s_env
{
	t_index			*index;
	int				x1;
	int				y1;
	int				x;
	int				y;
	int				size_x;
	int				size_y;
	int				move_x;
	int				move_y;
	int				len_x;
	int				len_y;
	int				swc_c;
	int				swc;
	int				leg;
	unsigned int	color;
	float			h;
	float			zoom;
	float			e;
	float			e1;
	float			e2;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img;
}					t_env;

int					color(int z1, int z2, t_env *env);
int					color_z(int z1, int z2, t_env *env);
int					key_hook(int key, t_env *env);
int					mouse_hook(int button, int x, int y, t_env *env);
void				bresenham_1(int x, int y, t_env *env);
void				bresenham_2(int x, int y, t_env *env);
void				bresenham_3(int x, int y, t_env *env);
void				bresenham_4(int x, int y, t_env *env);
void				bresenham_5(int x, int y, t_env *env);
void				bresenham_6(int x, int y, t_env *env);
void				bresenham_7(int x, int y, t_env *env);
void				bresenham_8(int x, int y, t_env *env);
void				bresenham_line(int x, int y, t_env *env);
void				choose_bresenham(int x2, int y2, t_env *env);
void				first_seg(t_env *env);
void				second_seg(t_env *env);
void				move_map(int key, t_env *env);
void				value_h(t_env *env, int s_x, int s_y);
void				print_legend(t_env *env);
void				find_zoom(t_env *env);
void				choose_seg(t_env *env);
void				mlxinit(t_env *env);
void				err_arg(void);
void				err_open(void);
void				err_read(void);
void				err_invalid_file(t_lst *lst, t_env *env);
void				reset_map(t_env *env);
t_env				*check(t_lst *list, t_env *env);
t_lst				*free_list(t_lst *list);
t_env				*free_env(t_env *env);
t_index				*free_index(t_index	*index);
t_index				*init_index(void);
t_env				*init_env(void);
t_lst				*init_lst(void);

#endif
