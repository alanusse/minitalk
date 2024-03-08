/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:12:54 by aglanuss          #+#    #+#             */
/*   Updated: 2024/03/08 12:15:52 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

char	*ft_joinchar(char *str, char c)
{
	char		*ptr;
	size_t		i;

	ptr = (char *)malloc((ft_strlen(str) + 2) * sizeof(char));
	if (!ptr)
		exit(EXIT_FAILURE);
	i = 0;
	while (str && str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = c;
	ptr[++i] = '\0';
	free(str);
	return (ptr);
}
