/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 12:08:48 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 15:46:53 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	if (!s)
		return (0);
	if (!(str = ft_strnew(len)))
		return (0);
	i = 0;
	while (i < start)
		i++;
	j = 0;
	while (s[i] && len > 0)
	{
		str[j] = s[i];
		j++;
		i++;
		len--;
	}
	return (str);
}
