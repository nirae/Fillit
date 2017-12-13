/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 19:00:57 by ndubouil          #+#    #+#             */
/*   Updated: 2017/12/13 18:20:24 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Print a tetriminos in a t_list
*/
static	void	ft_displaylist(t_list *list)
{
	ft_putstr("ID : ");
	ft_putnbr(((t_tetri *)list->content)->id);
	ft_putstr(", Valeur : ");
	ft_putchar(((t_tetri *)list->content)->value);
	ft_putstr(", Valeur binaire : ");
	ft_putnbr(((t_tetri *)list->content)->bin_value);
	if (list->next == NULL)
		ft_putstr(" NULL");
	ft_putchar('\n');
}

int		main(int ac, char **av)
{
	t_cursor		*cursor;
	t_list	*lst;
	char *result;

	/*
	** For print the list
	*/
	void	(*f)(t_list *list);
	f = &ft_displaylist;

	if (ac == 2)
	{
		ft_filetolist(av[1], &lst);
		/*
		** Print the list
		*/
		//ft_lstiter(lst, f);
		if (!(cursor = ft_newcursor(ft_lstlen(lst))))
			ft_error(&lst);
		if (!(result = ft_makesquare(cursor->size)))
			ft_error(&lst);
				while (!(ft_backtrack(result, *cursor, lst, 0)))
		{
			cursor->size = cursor->size + 1;
			if (!(result = ft_makesquare(cursor->size)))
			{
				free(cursor);
				ft_error(&lst);
			}
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
