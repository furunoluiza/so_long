/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfuruno- <lfuruno-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:16:22 by lfuruno-          #+#    #+#             */
/*   Updated: 2023/11/10 15:28:42 by lfuruno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n > 0)
	{
		if ((*(unsigned char *) s) == ((unsigned char) c))
			return ((void *) s);
		s++;
		n--;
	}
	return (NULL);
}
