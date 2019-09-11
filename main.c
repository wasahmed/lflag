/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasahmed <wasahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:01:15 by wasahmed          #+#    #+#             */
/*   Updated: 2019/07/31 09:43:34 by wasahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int       main(int argc, char **argv)
{
	//t_flags flag;

	if (argc == 1)
		basicls(argc, argv);
	if (argc >= 2)
	{
		basicls(argc, argv);
		//check_flags(&flag, *argv);
	}
	return (0);
}
