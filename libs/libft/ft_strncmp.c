/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfuruno- <lfuruno-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:28:04 by lfuruno-          #+#    #+#             */
/*   Updated: 2023/11/10 15:31:00 by lfuruno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*p;
	unsigned char	*ptr;

	p = ((unsigned char *)s1);
	ptr = ((unsigned char *) s2);
	while ((*p || *ptr) && n > 0)
	{
		if (*p != *ptr)
			return (*p - *ptr);
		p++;
		ptr++;
		n--;
	}
	return (0);
}
