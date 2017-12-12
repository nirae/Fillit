/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filetolist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 09:22:14 by ndubouil          #+#    #+#             */
/*   Updated: 2017/12/12 14:10:49 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

static void		ft_isempty_or_toolong(int i, int n_lus, t_list **lst)
{
	if ((i == 0 && n_lus <= 0) || i > 26)
	{
		ft_freelist(lst);
		ft_print_error();
	}
}

static void		ft_tempisnl(char temp, t_list **lst)
{
	if (temp == '\n')
	{
		ft_freelist(lst);
		ft_print_error();
	}
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
	char			tp[BUFF_SIZE];
	t_list			*lst;

	lst = NULL;
	i = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
		ft_print_error();
	while ((n_lus = read(fd, tp, BUFF_SIZE)) > 0)
	{
		ft_tempisnl(tp[0], &lst);
		tp[n_lus] = '\0';
		ft_istetri(tp);
		if (i == 0)
		{
			if (!(lst = ft_lstnew(ft_newtetri(i, tp), sizeof(t_tetri))))
			{
				ft_freelist(&lst);
				ft_print_error();
			}
		}
		else
			ft_lstaddend(&lst, ft_lstnew(ft_newtetri(i, tp), sizeof(t_tetri)));
		i++;
		read(fd, tp, 1);
	}
	ft_tempisnl(tp[0], &lst);
	ft_isempty_or_toolong(i, n_lus, &lst);
	close(fd);
	return (lst);
}
