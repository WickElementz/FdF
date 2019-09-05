/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_event.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/04 17:17:20 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/05 18:03:19 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	print_legend(t_env *env)
{
	mlx_string_put(env->mlx_ptr, env->win_ptr, 1, 1, BLUE_LEG, LEG_KEYBOARD);
	mlx_string_put(env->mlx_ptr, env->win_ptr, 1, 30, BLUE_LEG, LEG_COLOR);
	mlx_string_put(env->mlx_ptr, env->win_ptr, 1, 50, BLUE_LEG, LEG_MOVE);
	mlx_string_put(env->mlx_ptr, env->win_ptr, 1, 70, BLUE_LEG, LEG_PERSP);
	mlx_string_put(env->mlx_ptr, env->win_ptr, 1, 90, BLUE_LEG, LEG_RESET);
	mlx_string_put(env->mlx_ptr, env->win_ptr, 1, 120, BLUE_LEG, LEG_MOUSE);
	mlx_string_put(env->mlx_ptr, env->win_ptr, 1, 150, BLUE_LEG, LEG_ZOOM);
	mlx_string_put(env->mlx_ptr, env->win_ptr, 1, 170, BLUE_LEG, LEG_R_CLICK);
	mlx_string_put(env->mlx_ptr, env->win_ptr, 1, 190, BLUE_LEG, LEG_L_CLICK);
}

void	move_map(int key, t_env *env)
{
	if (key == 13)
		env->move_y -= 5;
	else if (key == 1)
		env->move_y += 5;
	else if (key == 0)
		env->move_x -= 5;
	else
		env->move_x += 5;
}

void	reset_map(t_env *env)
{
	env->move_y = 0;
	env->move_x = 0;
	env->swc_c = 1;
	env->h = 1;
	find_zoom(env);
	if (env->swc == 0)
		first_seg(env);
	else
		second_seg(env);
}

void	choose_seg(t_env *env)
{
	if (env->swc == 0)
		first_seg(env);
	else
		second_seg(env);
}

int		color(int z1, int z2, t_env *env)
{
	int					height;
	const unsigned int	color_tab[15] = {
		WHITE, RED_0, BLUE_0, YELLOW_0, GREEN_0,
		WHITE, RED_1, BLUE_1, YELLOW_1, GREEN_1,
		WHITE, RED_2, BLUE_2, YELLOW_2, GREEN_2
	};

	if ((z1 < 5 && z1 > -5) && (z2 < 5 && z2 > -5))
		height = 0;
	else if (z1 > 40 || z2 > 40 || z1 < -40 || z2 < -40)
		height = 2;
	else
		height = 1;
	return (color_tab[height * 5 + env->swc_c - 1]);
}
