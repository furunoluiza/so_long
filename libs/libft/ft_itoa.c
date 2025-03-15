/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfuruno- <lfuruno-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:13:27 by lfuruno-          #+#    #+#             */
/*   Updated: 2023/11/10 14:14:27 by lfuruno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_contmem(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	if (n == 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	long	numb;
	char	*p;

	numb = n;
	i = ft_contmem(numb);
	p = malloc ((i + 1) * sizeof(char));
	if (!p)
		return (NULL);
	if (numb < 0)
	{
		numb *= -1;
		p[0] = '-';
	}
	p[i] = '\0';
	i--;
	if (numb == 0)
		p[i] = numb + 48;
	while (numb > 0)
	{
		p[i] = (numb % 10) + 48;
		numb = numb / 10;
		i--;
	}
	return (p);
}
