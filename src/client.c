/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 01:42:01 by aglanuss          #+#    #+#             */
/*   Updated: 2024/02/20 23:34:58 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	check_arguments(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("Usage: client <pid> <message>\n");
		exit(EXIT_FAILURE);
	}
	while (*argv[1])
	{
		if (!ft_isdigit(*argv[1]))
		{
			ft_printf("Error: invalid PID\n");
			exit(EXIT_FAILURE);
		}
		argv[1]++;
	}
	if (ft_strlen(argv[2]) == 0)
	{
		ft_printf("Error: message can't be empty\n");
		exit(EXIT_FAILURE);
	}
}

int main(int argc, char **argv)
{
	check_arguments(argc, argv);
	ft_printf("OK!\n");
	ft_printf("%s\n", argv[2]);
	return 0;
}
