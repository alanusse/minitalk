/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:37:41 by aglanuss          #+#    #+#             */
/*   Updated: 2024/03/09 18:48:32 by aglanuss         ###   ########.fr       */
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
static void	char_handler(unsigned int *step, char c, siginfo_t *info)
{
	static char	*str_len = NULL;
	static char	*str = NULL;

	if (*step == 0)
		str_len = ft_joinchar(str_len, c);
	if (*step == 1)
	{
		str = (char *)malloc((ft_atoi(str_len) + 1) * sizeof(char));
		if (!str)
			exit(EXIT_FAILURE);
		str[ft_atoi(str_len)] = '\0';
		free_str(&str_len);
		*step += 1;
	}
	else if (*step == 2)
		fill_str(&str, c);
	else if (*step == 3)
	{
		fill_str(&str, '\0');
		ft_printf("%s", str);
		free_str(&str);
		*step = 0;
		kill(info->si_pid, SIGUSR2);
	}
}

static void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static unsigned char	buffer = 0;
	static unsigned int		bits_count = 0;
	static unsigned int		step = 0;

	(void)context;
	if (sig == SIGUSR1)
		buffer = (buffer << 1) | 0;
	else if (sig == SIGUSR2)
		buffer = (buffer << 1) | 1;
	bits_count++;
	if (bits_count == 8)
	{
		if (buffer == 0)
			step++;
		char_handler(&step, buffer, info);
		bits_count = 0;
		buffer = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("\e[1;34mMinitalk\e[0m\n");
	ft_printf("\e[1;37mStarted server with \e[1;32mPID %i\e[0m\n", getpid());
	ft_printf("\e[0;33mWaiting for signals...\e[0m\n\n");
	while (1)
		sleep(1);
}
