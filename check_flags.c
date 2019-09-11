/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasahmed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 08:47:13 by wasahmed          #+#    #+#             */
/*   Updated: 2019/07/29 14:26:10 by wasahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		check_flags(t_flags *flag, char *arg)
{
	int		i;

	i = 1;
	while (arg[i] && arg[0] == '-')
	{
		if (arg[i] == 'a')
			flag->flag_a = 1;
		else if (arg[i] == 'r')
			flag->flag_r = 1;
		else if (arg[i] == 'l')
			flag->flag_l = 1;
		else if (arg[i] == 't')
			flag->flag_t = 1;
		else if (arg[i] == 'R')
			flag->flag_re = 1;
		else
		{
			ft_putstr("ls: illegal option -- ");
			ft_putstr(&arg[i]);
			ft_putchar('\n');
			ft_putstr("usage: ./ls [-Ralrt] [file ...]");
			return (0);
		}
		i++;
	}
	return (1);
}
