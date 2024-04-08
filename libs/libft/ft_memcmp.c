/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfuruno- <lfuruno-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:16:47 by lfuruno-          #+#    #+#             */
/*   Updated: 2023/11/10 15:32:44 by lfuruno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n > 0)
	{
		if ((*(unsigned char *) s1) != (*(unsigned char *) s2))
			return ((*(unsigned char *) s1) - (*(unsigned char *) s2));
		s1++;
		s2++;
		n--;
	}
	return (0);
}
