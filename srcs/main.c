/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/12 11:35:50 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/05 17:27:18 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
	first_seg(env);
	mlx_hook(env->win_ptr, 2, 1, key_hook, env);
	mlx_mouse_hook(env->win_ptr, mouse_hook, env);
	mlx_loop(env->mlx_ptr);
}

/*
** Fonction remplissant notre liste chainée "lst" par le contenu du fichier
*/

t_lst	*fill(t_lst *lst, int fd)
{
	int		ret;
	t_lst	*tmp;
	char	*line;

	tmp = lst;
	while ((ret = get_next_line(fd, &line) > 0))
	{
		lst->s = line;
		lst->next = init_lst();
		lst = lst->next;
	}
	return (tmp);
}

int		main(int ac, char **av)
{
	t_lst	*lst;
	int		fd;
	t_env	*env;

	if (ac != 2)
		err_arg();
	if ((fd = open(av[1], O_RDONLY)) < 1)
		err_open();
	if (read(fd, NULL, 0) == -1)
		err_read();
	env = init_env();
	lst = init_lst();
	lst = fill(lst, fd);
	env = check(lst, env);
	env->mlx_ptr = mlx_init();
	mlxinit(env);
	free_list(lst);
	free_env(env);
	return (0);
}
