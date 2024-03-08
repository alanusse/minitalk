/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:37:41 by aglanuss          #+#    #+#             */
/*   Updated: 2024/03/08 12:18:10 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	free_str(char **str)
{
	free(*str);
	*str = NULL;
}

static void	fill_str(char **str, char c)
{
	static unsigned int	i = 0;
	char				*string;

	if (c == '\0')
		i = 0;
	else
	{
		string = *str;
		string[i] = c;
		i++;
	}
}

/**
 * step 0: fill str_len with chars.
 * step 1: reserve memory to allocate string.
 * step 2: fill reserved memory with chars received.
 * step 3: print string, free string and str_len and set step to 0.
*/
static void	char_handler(unsigned int *step, char c)
{
	static char	*str_len = NULL;
	static char	*str = NULL;

	if (c == 0)
		*step += 1;
	if (*step == 0)
		str_len = ft_joinchar(str_len, c);
	if (*step == 1)
	{
		str = (char *)malloc((ft_atoi(str_len) + 1) * sizeof(char));
		if (!str)
			exit(EXIT_FAILURE);
		str[ft_atoi(str_len)] = '\0';
		*step += 1;
	}
	else if (*step == 2)
		fill_str(&str, c);
	else if (*step == 3)
	{
		fill_str(&str, '\0');
		ft_printf("%s", str);
		free_str(&str);
		free_str(&str_len);
		*step = 0;
	}
}

static void	signal_handler(int signal)
{
	static unsigned char	buffer = 0;
	static unsigned int		bits_count = 0;
	static unsigned int		step = 0;

	if (signal == SIGUSR1)
		buffer = (buffer << 1) | 0;
	else if (signal == SIGUSR2)
		buffer = (buffer << 1) | 1;
	bits_count++;
	if (bits_count == 8)
	{
		char_handler(&step, buffer);
		bits_count = 0;
		buffer = 0;
	}
}

int	main(void)
{
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	ft_printf("Started server with PID %i\n", getpid());
	while (1)
		sleep(1);
}
