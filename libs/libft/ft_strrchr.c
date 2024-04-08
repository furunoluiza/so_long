/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfuruno- <lfuruno-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:28:59 by lfuruno-          #+#    #+#             */
/*   Updated: 2023/11/10 14:29:02 by lfuruno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*a;

	a = ((unsigned char *) s);
	while (*a)
		a++;
	if (c == '\0')
		return ((char *) a);
	a--;
	while (*s)
	{
		if (*a == (unsigned char) c)
			return ((char *) a);
		a--;
		s++;
	}
	return (0);
}
