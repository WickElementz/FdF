/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   scope.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/17 15:59:26 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/02 18:34:02 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/FdF.h"

/*
** Fonction splitée en 2 qui te renvoit vers le bresenham correspondant
** a l'inclinaison de la droite que tu veux tracer
*/

void	choose_bresenham_2(int x2, int y2, t_env *env)
{
	if (env->x < 0 && env->y < 0)
	{
		if (-env->x >= -env->y)
			bresenham_3(x2, y2, env);
		else if (-env->x < -env->y)
			bresenham_4(x2, y2, env);
	}
	else if (env->x > 0 && env->y > 0)
	{
		if (env->x >= env->y)
			bresenham_7(x2, y2, env);
		else if (env->x < env->y)
			bresenham_8(x2, y2, env);
	}
	else
		bresenham_line(x2, y2, env);
}

void	choose_bresenham(int x2, int y2, t_env *env)
{
	env->x = env->x1 - x2;
	env->y = env->y1 - y2;
	if (env->x < 0 && env->y > 0)
	{
		if (-env->x >= env->y)
			bresenham_2(x2, y2, env);
		else if (-env->x < env->y)
			bresenham_1(x2, y2, env);
	}
	else if (env->x > 0 && env->y < 0)
	{
		if (env->x >= -env->y)
			bresenham_6(x2, y2, env);
		else if (env->x < -env->y)
			bresenham_5(x2, y2, env);
	}
	else
		choose_bresenham_2(x2, y2, env);
}

/*
** Events liés au clavier
*/

int		key_hook(int key, t_env *env)
{
	if (key == ECHAP)
		exit(1);
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		move_map(key, env);
	if (key == RESET)
		reset_first_map(env);
	if (key == SWITCH_COLOR)
	{
		env->swc++;
		if (env->swc == 5)
			env->swc = 1;
	}
	if (key == RELIEF_PLUS)
		env->h += 10;
	if (key == RELIEF_MOINS)
		env->h -= 10;
	choose_first_seg(env);
	return (0);
}

/*
** Events liés a la souris
*/

int		mouse_hook(int button, int x, int y, t_env *env)
{
	if (button == LEFT_CLICK)
	{
		env->x1 = x;
		env->y1 = y;
	}
	if (button == RIGHT_CLICK)
		choose_bresenham(x, y, env);
	if (button == SCROLL_UP)
		env->zoom *= 1.2;
	if (button == SCROLL_DOWN)
		env->zoom /= 1.2;
	if (button != LEFT_CLICK && button != RIGHT_CLICK)
		choose_first_seg(env);
	return (0);
}

/*
** Fonction d'initialisation de la MLX
** Gestion d'event et Loop pour garder la fenetre ouverte
*/

void	mlxinit(t_env *env)
{
	env->win_ptr = mlx_new_window(env->mlx_ptr, env->size_x,
									env->size_y, "FdF");
	env->img = mlx_new_image(env->mlx_ptr, env->size_x, env->size_y);
	find_zoom(env);
	choose_first_seg(env);
	mlx_hook(env->win_ptr, 2, 1, key_hook, env);
	mlx_mouse_hook(env->win_ptr, mouse_hook, env);
	mlx_loop(env->mlx_ptr);
}
