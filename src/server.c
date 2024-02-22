/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:37:41 by aglanuss          #+#    #+#             */
/*   Updated: 2024/02/22 12:33:00 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

char	*g_text;

void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("0\n");
	else if (signal == SIGUSR2)
		ft_printf("1\n");
}

int	main(void)
{
	g_text = NULL;
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	ft_printf("Started server with PID %i\n", getpid());
	while (1)
		sleep(1);
}
