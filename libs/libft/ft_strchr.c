/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfuruno- <lfuruno-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:21:28 by lfuruno-          #+#    #+#             */
/*   Updated: 2023/11/11 12:20:19 by lfuruno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*a;

	if (c > 127)
		c %= 256;
	a = ((unsigned char *) s);
	while (*a)
		a++;
	if (c == '\0')
		return ((char *) a);
	while (*s)
	{
		if (*s == c)
			return ((char *) s);
		s++;
	}
	return (0);
}
