/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasahmed <wasahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 07:33:02 by wasahmed          #+#    #+#             */
/*   Updated: 2019/07/31 09:44:24 by wasahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <unistd.h>
# include <dirent.h>  // for struct dirent, DIR, opendir, readdir, closedir
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef	struct	s_flags
{
	int		flag_l;
	int		flag_a;
	int		flag_t;
	int		flag_r;
	int		flag_re;
}				t_flags;

int		basicls(int argc, char **argv);
int		check_flags(t_flags *flag, char *arg);

#endif
