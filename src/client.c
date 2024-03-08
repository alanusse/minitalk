/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 01:42:01 by aglanuss          #+#    #+#             */
/*   Updated: 2024/03/08 12:18:34 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	check_arguments(int argc, char **argv)
{
	int	i;

	if (argc != 3)
	{
		ft_printf("Usage: client <pid> <message>\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i]))
		{
			ft_printf("Error: invalid PID\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	if (ft_strlen(argv[2]) == 0)
	{
		ft_printf("Error: message can't be empty\n");
		exit(EXIT_FAILURE);
	}
}

static void	send_null_terminator(pid_t pid, int sleep_time)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		kill(pid, SIGUSR1);
		usleep(sleep_time);
	}
}

static void	send_signals(pid_t pid, char *str, int sleep_time)
{
	int	tmp;
	int	i;

	while (*str)
	{
		i = 7;
		while (i >= 0)
		{
			tmp = *str >> i;
			if (tmp & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(sleep_time);
			i--;
		}
		str++;
	}
	send_null_terminator(pid, sleep_time);
}

static void	send_str_len(pid_t pid, char *str, int sleep_time)
{
	int	len;

	len = ft_strlen(str);
	send_signals(pid, ft_itoa(len), sleep_time);
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*text;
	int		sleep_time;

	check_arguments(argc, argv);
	pid = ft_atoi(argv[1]);
	text = argv[2];
	sleep_time = 300;
	send_str_len(pid, text, sleep_time);
	send_signals(pid, text, sleep_time);
	return (0);
}
