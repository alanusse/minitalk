/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 01:08:35 by aglanuss          #+#    #+#             */
/*   Updated: 2024/02/22 01:47:45 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

static int	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	if (dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < (dstsize - 1) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

static char	*ft_strdup(char *s1)
{
	char	*dup;
	int		len;

	len = ft_strlen(s1);
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (!dup)
	{
		errno = ENOMEM;
		return (NULL);
	}
	dup[len] = '\0';
	ft_strlcpy(dup, s1, len + 1);
	return (dup);
}

static int	count_digits(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count = 1;
	while (n > 0 || n < 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	ptr = (char *)malloc((count_digits(n) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ptr[count_digits(n)] = '\0';
	i = count_digits(n) - 1;
	if (n < 0)
	{
		ptr[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		ptr[i] = '0' + (n % 10);
		n /= 10;
		i--;
	}
	return (ptr);
}
