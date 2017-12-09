/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 19:56:11 by ndubouil          #+#    #+#             */
/*   Updated: 2017/12/09 15:44:53 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
/*

** Params : result string, struct of cursor
** Return : number of empty squares that can't be used on one line
*/
static int		ft_emptyline(char *result, t_cursor cursor)
{
	int		i;
	int		j;
	int		emptysize;
	int		isempty;

	i = cursor.size + 1;
	j = cursor.size + 1;
	isempty = 0;
	while (i < cursor.check && i / j < cursor.size - 1)
	{
		emptysize = 0;
		while (result[i] == '.' && emptysize < 4 &&
				result[i - j] != '.' && result[i++ + j] != '.')
			++emptysize;
		if (emptysize < 4)
			isempty = isempty + emptysize;
		++i;
	}
	return (isempty);
}

/*
** Params : result string, struct of cursor
** Return : number of empty squares that can't be used on one column
*/
static int		ft_emptycol(char *result, t_cursor cursor)
{
	int		i;
	int		k;
	int		emptysize;
	int		isempty;

	i = 1;
	isempty = 0;
	while (i < cursor.check && i <= cursor.size)
	{
		k = i;
		emptysize = 0;
		while (result[k] == '.' && emptysize < 4 && result[k - 1] != '.'
				&& result[k + 1] != '.')
		{
			++emptysize;
			k = k + cursor.size + 1;
		}
		if (emptysize < 4)
			isempty = isempty + emptysize;
		++i;
	}
	return (isempty);
}

/*
** Params : result string, struct of cursor, counter
** Return : nothing
** Delete one tetriminos on the result square
*/
static void		ft_deleteit(char *result, t_cursor cursor, int j)
{
	cursor.pos = 0;
	while (result[cursor.pos] != 0)
	{
		if (result[cursor.pos] == 'A' + j)
			result[cursor.pos] = '.';
		++cursor.pos;
	}
}

/*
** Principal Function
** Params : result string, struct of cursor, t_list of tetriminos, counter
** Return : 1 or 0
** Backtracking for resolve the square of tetriminos
*/
int				ft_backtrack(char *result, t_cursor cursor, t_list *lst, int j)
{
	if (lst == NULL)
		return (1);
	if (ft_emptyline(result, cursor) + ft_emptycol(result, cursor)
			> (cursor.size * cursor.size) - (cursor.form * 4))
		return (0);
	while (!(ft_isfilled(result, ((t_tetri *)(lst->content)), cursor))
			&& result[cursor.pos] != 0)
		++cursor.pos;
	if (result[cursor.pos] != 0)
	{
		ft_fillit(result, ((t_tetri *)(lst->content)), cursor);
		cursor.check = cursor.pos;
		cursor.pos = 0;
		if (ft_backtrack(result, cursor, lst->next, j + 1) == 1)
			return (1);
		cursor.pos = cursor.check;
		ft_deleteit(result, cursor, j);
		++cursor.pos;
		return (ft_backtrack(result, cursor, lst, j));
	}
	return (0);
}
