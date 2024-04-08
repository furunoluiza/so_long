/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfuruno- <lfuruno-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:17:59 by lfuruno-          #+#    #+#             */
/*   Updated: 2023/11/10 15:27:25 by lfuruno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dest_ptr;
	char	*src_ptr;

	if (!src && !dest)
		return (0);
	dest_ptr = ((char *) dest);
	src_ptr = ((char *) src);
	if (src_ptr >= dest_ptr)
	{
		while (n > 0)
		{
			*dest_ptr++ = *src_ptr++;
			n--;
		}
	}
	else if (src_ptr < dest_ptr)
	{
		while (n > 0)
		{
			dest_ptr[n - 1] = src_ptr[n - 1];
			n--;
		}
	}
	return (dest);
}
