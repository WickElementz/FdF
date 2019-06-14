/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 17:06:49 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 10:00:42 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./libft.h"

static char	**malloc_tab(char *str, char **tab, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (str[i] == c && str[i])
		i++;
	while (str[i] != '\0')
	{
		k = 0;
		while (str[i] != c && str[i])
		{
			i++;
			k++;
		}
		while (str[i] == c && str[i])
			i++;
		if (!(tab[j] = (char*)malloc(sizeof(char) * (k + 1))))
			return (NULL);
		j++;
	}
	if (tab == NULL)
		return (NULL);
	return (tab);
}

static char	**pushletter(char *str, char **tab, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (str[i] == c && str[i])
		i++;
	while (str[i] != '\0')
	{
		k = 0;
		while (str[i] != c && str[i])
		{
			tab[j][k] = str[i];
			i++;
			k++;
		}
		while (str[i] == c && str[i])
			i++;
		tab[j][k] = '\0';
		j++;
	}
	tab[j] = NULL;
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**tab;
	char	*str;

	if (!s || !c)
		return (NULL);
	i = 0;
	j = 0;
	str = (char *)s;
	while (str[i] == c)
		i++;
	while (str[i] != '\0')
	{
		while (str[i] != c && str[i])
			i++;
		while (str[i] == c && str[i])
			i++;
		j++;
	}
	if (!(tab = (char**)malloc(sizeof(char*) * (j + 1))))
		return (0);
	if (!(tab = malloc_tab(str, tab, c)))
		return (NULL);
	return (pushletter(str, tab, c));
}
