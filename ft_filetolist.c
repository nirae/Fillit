/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filetolist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 09:22:14 by ndubouil          #+#    #+#             */
/*   Updated: 2017/12/14 12:02:19 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

static t_list	*ft_lnew(t_list **lst, int i, char *tp)
{
	t_list	*result;
	t_tetri *tetri;

	if (!(tetri = ft_newtetri(i, tp)))
		ft_error(lst);
	if (!(result = ft_lstnew(tetri, sizeof(*tetri))))
		ft_error(lst);
	free(tetri);
	return (result);
}

static void		ft_isempty_or_toolong(int i, int n_lus, t_list **lst)
{
	if ((i == 0 && n_lus <= 0) || i > 26)
		ft_error(lst);
}

static void		ft_tempisnl(char temp, t_list **lst)
{
	if (temp == '\n')
		ft_error(lst);
}

void			ft_filetolist(char *file, t_list **lst)
{
	int				i;
	int				fd;
	int				n_lus;
	char			tp[BUFF_SIZE];

	i = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
		ft_print_error();
	while ((n_lus = read(fd, tp, BUFF_SIZE)) > 0)
	{
		ft_tempisnl(tp[0], lst);
		tp[n_lus] = '\0';
		ft_istetri(tp);
		if (i == 0)
			*lst = ft_lnew(lst, i, tp);
		else
			ft_lstaddend(lst, ft_lnew(lst, i, tp));
		i++;
		read(fd, tp, 1);
	}
	ft_tempisnl(tp[0], lst);
	ft_isempty_or_toolong(i, n_lus, lst);
	close(fd);
}
