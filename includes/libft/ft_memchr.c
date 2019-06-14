/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 12:38:32 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 14:41:02 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *strsrc;

	strsrc = (unsigned char *)s;
	while (n > 0 && *strsrc != (unsigned char)c)
	{
		n--;
		strsrc++;
	}
	if (n == 0)
		return (NULL);
	else
		return (strsrc);
}
