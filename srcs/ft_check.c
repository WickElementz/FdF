/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/13 14:48:03 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/13 18:12:36 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/FdF.h"

char		*del_number(char *str)
{
	int		i;
	int		j;
	char	*str2;

	i = 0;
	j = 0;
	while (str[i])
	{
		while ((str[i] >= '0' && str[i] <= '9')
				|| str[i] == '-' || str[i] == '+')
			i++;
		while (str[i] == ' ')
			i++;
		break ;
	}
	j = ft_strlen(str) - i;
	str2 = malloc(sizeof(char) * (j + 1));
	j = 0;
	while (str[i])
	{
		str2[j++] = str[i++];
	}
	str2[j] = '\0';
	return (str2);
}

t_env		*index_number(t_lst *lst, t_env *index, int verif, int number)
{
	int x;
	int y;
	int i;

	y = 0;
	while (lst->next)
	{
		x = 0;
		i = verif;
		while (i-- > 0)
		{
			number = (ft_atoi(lst->s));
			lst->s = del_number(lst->s);
			index->num = number;
			index->co_x = x++;
			index->co_y = y;
			dprintf(1, "Relief: %d  ||  Coord x: %d  ||  Coord y: %d\n", index->num, index->co_x, index->co_y);
		}
		y++;
		index->next = (t_env *)malloc(sizeof(t_env));
		index = index->next;
		lst = lst->next;
	}
	return (index);
}

int			check_valide_file(t_lst *lst, int verif, int i, int nbr)
{
	while (lst->next)
	{
		i = 0;
		nbr = 1;
		while (lst->s[i])
		{
			if (lst->s[i] == ' ' || lst->s[i] == '-' || lst->s[i] == '+')
			{
				while (lst->s[i] == ' ')
					i++;
				if (lst->s[i] && lst->s[i] != '-' && lst->s[i] != '+')
					nbr++;
			}
			else if (lst->s[i] < '0' || lst->s[i] > '9')
				return (0);
			else
				i++;
		}
		if (verif == 0)
			verif = nbr;
		if (verif != nbr)
			return (0);
		lst = lst->next;
	}
	return (verif);
}

int			check(t_lst *lst)
{
	t_env	*env;
	int		verif;

	verif = 0;
	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (0);
	verif = check_valide_file(lst, 0, 0, 1);
	if (verif == 0)
		return (0);
	env = index_number(lst, env, verif, 0);
	return (1);
}
