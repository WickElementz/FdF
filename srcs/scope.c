/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   scope.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/17 15:59:26 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/18 18:17:50 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */
#include "../includes/FdF.h"

/*
** Fonction qui te renvoit vers le bresenham correspondant
** a l'inclinaison de la droite que tu veux tracer
*/

void check_bresenham(int x2, int y2, t_env *env)
{
	int x;
	int y;

	x = env->x1 - x2;
	y = env->y1 - y2;
	if (x < 0 && y > 0)
	{
		if (-x > y)
			bresenham_2(x2, y2, env);
		else if (-x < y)
			bresenham_1(x2, y2, env);
	}
	else if (x > 0 && y < 0)
	{
		if (x > -y)
			bresenham_6(x2, y2, env);
		else if (x < -y)
			bresenham_5(x2, y2, env);
	}
	else if (x < 0 && y < 0)
	{
		if (-x > -y)
			bresenham_3(x2, y2, env);
		else if (-x < -y)
			bresenham_4(x2, y2, env);
	}
	else if (x > 0 && y > 0)
	{
		if (x > y)
			bresenham_7(x2, y2, env);
		else if (x < y)
			bresenham_8(x2, y2, env);
	}
}

/*
** Keycode 53 = echap, donc, echap = close programme
 */

int key_hook(int key, t_env *env)
{
	if (key == 53)
		exit(1);
	return (0);
}

/*
** Clic Gauche pour definir un point de depart
** Puis Clic droit pour tracer vers un point d'arrivée
*/

int mouse_hook(int button, int x, int y, t_env *env)
{
	if (button == 1)
	{
		env->x1 = x;
		env->y1 = y;
	}
	if (button == 2)
		check_bresenham(x, y, env);
	return (0);
}

/*
** Fonction d'initialisation de la MLX 
** Gestion d'event et Loop pour garder la fenetre ouverte
 */

void mlxinit(t_env *env)
{
	env->win_ptr = mlx_new_window(env->mlx_ptr, 1200, 800, "this is a title");
	env->img = mlx_new_image(env->mlx_ptr, 1200, 800);
	mlx_hook(env->win_ptr, 2, 1, &key_hook, env);
	mlx_mouse_hook(env->win_ptr, &mouse_hook, env);
	mlx_loop(env->mlx_ptr);
}