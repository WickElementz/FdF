/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   scope.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/17 15:59:26 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/05 18:10:00 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

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

void	key_hook2(int key, t_env *env)
{
	if (key == TAB)
	{
		print_legend(env);
		if (env->leg == 1)
		{
			print_legend(env);
			env->leg = 0;
		}
		else
			env->leg = 1;
	}
	if (key == SWITCH)
	{
		if (env->swc == 0)
			env->swc = 1;
		else if (env->swc == 1)
			env->swc = 0;
		reset_map(env);
	}
	choose_seg(env);
}

int		key_hook(int key, t_env *env)
{
	if (key == ECHAP)
		exit(1);
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		move_map(key, env);
	if (key == RESET)
		reset_map(env);
	if (key == SWITCH_COLOR)
	{
		env->swc_c++;
		if (env->swc_c == 6)
			env->swc_c = 1;
	}
	if (key == PLUS)
		env->h += 0.3;
	if (key == MOINS)
		env->h -= 0.3;
	key_hook2(key, env);
	return (0);
}

/*
** Events liés a la souris
*/

int		mouse_hook(int button, int x, int y, t_env *env)
{
	if (button == RIGHT_CLICK)
	{
		env->x1 = x;
		env->y1 = y;
	}
	if (button == LEFT_CLICK)
		choose_bresenham(x, y, env);
	if (button == SCROLL_UP)
		env->zoom *= 1.2;
	if (button == SCROLL_DOWN)
		env->zoom /= 1.2;
	if (button != LEFT_CLICK && button != RIGHT_CLICK)
		choose_seg(env);
	return (0);
}
