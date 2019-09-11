/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basicls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasahmed <wasahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 09:45:03 by wasahmed          #+#    #+#             */
/*   Updated: 2019/07/31 09:45:04 by wasahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
int		basicls(int argc, char **av)
{
	DIR				*dir;
	struct dirent	*dp;

	t_flags flag;
	int i;
	int v;


	if (argc > 1) {
		i = 0;
		v = 0;
		while (av[++i]) {
			if (av[i][0] == '-' && ft_isprint(av[i][1])) {
				check_flags(&flag, *av);
			//	continue;
			} else{
				dir = opendir(av[i]);
				v++;
				break;
			}
		}
		if (!v)
			dir = opendir(".");
	} else {
		dir = opendir(".");
	}
	if (!dir) {
		printf("could not open dir\n");
		exit(EXIT_FAILURE);
	}
	while ((dp = readdir(dir)))
	{
		if (dp->d_name[0] != '.')
			ft_putendl(dp->d_name);
	}
	closedir(dir);
	return (0);
}
