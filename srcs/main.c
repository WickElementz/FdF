/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/12 11:35:50 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/24 15:39:02 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/FdF.h"

/*
** Fonction remplissant notre liste chainée "lst" par le contenu du fichier, ligne par ligne
*/

t_lst   *fill(t_lst *lst, int fd)
{
	int     ret;
	t_lst   *tmp;
	char    *line;

	tmp = lst;
	while ((ret = get_next_line(fd, &line) > 0))
	{
		lst->s = line;
		lst->next = init_lst();
		lst = lst->next;
	}
	return (tmp);
}

int     main(int ac, char **av)
{ 
	t_lst   *lst;
	int     fd;
	t_env   *env;

	if (ac != 2)
	{
		ft_putstr("Usage: ./fdf input_file\n");
		return (0);
	}
	if ((fd = open(av[1], O_RDONLY)) < 1)
		error();
	if (read(fd, NULL, 0) == -1)
		error();
	env = init_env();
	lst = init_lst();
	lst = fill(lst, fd);
	env = check(lst, env);
	env->mlx_ptr = mlx_init();
	mlxinit(env);
	free_list(lst);
	free_env(env);
	return(0);
}