/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 16:14:29 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/18 14:22:42 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	res;

	i = 0;
	j = 0;
	res = ft_strlen(src);
	while (dest[j] && j < n)
		j++;
	res = res + j;
	if (j != n)
	{
		while (j < n - 1 && src[i])
			dest[j++] = src[i++];
		dest[j] = '\0';
	}
	return (res);
}
