/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filetolist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 09:22:14 by ndubouil          #+#    #+#             */
/*   Updated: 2017/12/09 11:09:09 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

static void		ft_isempty_or_toolong(int i, int n_lus)
{
	if ((i == 0 && n_lus <= 0) || i > 26)
		ft_print_error();
}

static void		ft_tempisnl(char temp)
{
	if (temp == '\n')
		ft_print_error();
}

/*
 ** Params : file of tetriminos
 ** Return : t_list of a struct of tetriminos
 ** Convert the file in a t_list of struct of tetriminos
 ** Open -> Read while the file is not finish and put in t_list for all of tetriminos -> Close
 */
t_list			*ft_filetolist(char *file)
{
	int				i;
	int				fd;
	int				n_lus;
	char			temp[BUFF_SIZE];
	t_list			*lst;

	lst = NULL;
	i = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
		ft_print_error();
	while ((n_lus = read(fd, temp, BUFF_SIZE)) > 0)
	{
		ft_tempisnl(temp[0]);
		temp[n_lus] = '\0';
		if (i == 0)
			lst = ft_lstnew(ft_newtetri(i, temp), sizeof(t_tetri));
		else
			ft_lstaddend(&lst, ft_lstnew(ft_newtetri(i, temp), sizeof(t_tetri)));
		i++;
		read(fd, temp, 1);
	}
	ft_tempisnl(temp[0]);
	ft_isempty_or_toolong(i, n_lus);
	close(fd);
	return (lst);
}
