/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 01:42:01 by aglanuss          #+#    #+#             */
/*   Updated: 2024/02/20 12:20:35 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int main(int argc, char **argv)
{
	if (argc != 3)
		ft_printf("Usage: client <PID> <MESSAGE>\n");
	else
	{
		ft_printf("OK!\n");
		ft_printf("%s\n", argv[2]);
	}
	return 0;
}
