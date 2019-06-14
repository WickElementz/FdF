/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <jominodi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/13 14:48:03 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/14 18:50:45 by jominodi    ###    #+. /#+    ###.fr     */
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
		str2[j++] = str[i++];
	str2[j] = '\0';
	free(str);
	return (str2);
}

t_env		*index_number(t_lst *lst, t_env *env, int verif, int number)
{
	int		x;
	int		y;
	int		i;
	t_index	*tmp;
	t_lst	*beg;

	y = 0;
	beg = lst;
	tmp = INDEX;
	while (beg->next && !(x = 0))
	{
		i = verif;
		while (i-- > 0)
		{
			number = (ft_atoi(beg->s));
			beg->s = del_number(beg->s);
			tmp->num = number;
			tmp->co_x = x++;
			tmp->co_y = y;
			tmp->next = init_index();
			tmp = tmp->next;
		}
		y++;
		beg = beg->next;
	}
	return (env);
}

int			check_valid_file(t_lst *lst, int verif, int i, int nbr)
{
	while (lst->next)
	{
		i = 0;
		nbr = 0;
		while ((lst->s[i] && lst->s[i] >= '0' && lst->s[i] <= '9')
				|| lst->s[i] == ' ' || lst->s[i] == '-' || lst->s[i] == '+')
		{
			while (lst->s[i] && lst->s[i] != ' ')
				i++;
			while (lst->s[i] && lst->s[i] == ' ')
				i++;
			nbr++;
		}
	//	dprintf(1, "Verif: %d || nbr: %d\n", verif, nbr);
		if (verif == 0)
			verif = nbr;
		if (verif != nbr)
			return (0);
		lst = lst->next;
	}
	return (verif);
}

t_env			*check(t_lst *lst, int verif, t_env *env)
{
	if (!(verif = check_valid_file(lst, verif, 101, 101)))
	{
		dprintf(1, "Invalid File\n");
		return (NULL);
	}
	dprintf(1, "Valid File\n");
	env = index_number(lst, env, verif, 0);
	while (INDEX->next)
	{
		dprintf(1, "Relief: %d || Coord x: %d || Coord y: %d\n", INDEX->num, INDEX->co_x, INDEX->co_y);
		INDEX = INDEX->next;
	}
	return (env);
}
