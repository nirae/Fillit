/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 19:56:11 by ndubouil          #+#    #+#             */
/*   Updated: 2017/12/14 07:55:05 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

int				ft_backtrack(char *result, t_cursor cursor, t_list *lst, int j)
{
	if (lst == NULL)
		return (1);
	if (ft_emptyline(result, cursor) > (cursor.size * cursor.size)
			- (cursor.form * 4))
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
