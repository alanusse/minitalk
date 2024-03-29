/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 23:13:20 by aglanuss          #+#    #+#             */
/*   Updated: 2024/03/08 12:13:40 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <stdlib.h>
# include <errno.h>

int		ft_strlen(char *str);
int		ft_isdigit(char c);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
char	*ft_joinchar(char *str, char c);

#endif