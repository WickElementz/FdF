/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 10:51:14 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 15:47:22 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strrchr(const char *str, int n)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] == n)
			k = i + 1;
		i++;
	}
	if (n == '\0')
		k = i + 1;
	if (k != 0)
		return (&((char*)str)[k - 1]);
	else
		return (NULL);
}
