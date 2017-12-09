/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 19:00:57 by ndubouil          #+#    #+#             */
/*   Updated: 2017/12/09 16:18:50 by ndubouil         ###   ########.fr       */
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
		lst = ft_filetolist(av[1]);
		/*
		** Print the list
		*/
		//ft_lstiter(lst, f);
		cursor = ft_newcursor(ft_lstlen(lst));
		result = ft_makesquare(cursor->size);
		/*
		** Print the square before the backtracking
		*/
		//ft_putstr("Grille avant remplissage :\n");
		//ft_putstr(result);
		//ft_putchar('\n');
		/*
		** Backtracking
		*/
		while (!(ft_backtrack(result, *cursor, lst, 0)))
		{
			cursor->size = cursor->size + 1;
			result = ft_makesquare(cursor->size);
		}
		/*
		** Print the final square
		*/
		//ft_putstr("Grille apres le remplissage :\n");
		ft_putstr(result);
	}
	else
		ft_print_usage();
	return (0);
}
