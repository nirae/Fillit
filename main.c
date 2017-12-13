/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 19:00:57 by ndubouil          #+#    #+#             */
/*   Updated: 2017/12/13 19:28:00 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	t_cursor	*cursor;
	t_list		*lst;
	char		*result;

	if (ac == 2)
	{
		ft_filetolist(av[1], &lst);
		cursor = ft_newcursor(ft_lstlen(lst), &lst);
		result = ft_makesquare(cursor, &lst);
		while (!(ft_backtrack(result, *cursor, lst, 0)))
		{
			cursor->size = cursor->size + 1;
			result = ft_makesquare(cursor, &lst);
		}
		free(cursor);
		ft_freelist(&lst);
		ft_putstr(result);
		free(result);
	}
	else
		ft_print_usage();
	return (0);
}
