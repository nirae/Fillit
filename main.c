/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 19:00:57 by ndubouil          #+#    #+#             */
/*   Updated: 2017/12/07 15:24:09 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

#define BUFF_SIZE 21

// Tableau de comparaison
unsigned int	*ft_init_tab(void)
{
	unsigned int	*tab;

	if (!(tab = ft_memalloc(sizeof(unsigned int) * 19)))
		return (NULL);
	tab[0] = 15;
	tab[1] = 99;
	tab[2] = 306;
	tab[3] = 54;
	tab[4] = 561;
	tab[5] = 275;
	tab[6] = 547;
	tab[7] = 71;
	tab[8] = 116;
	tab[9] = 23;
	tab[10] = 113;
	tab[11] = 785;
	tab[12] = 802;
	tab[13] = 39;
	tab[14] = 562;
	tab[15] = 114;
	tab[16] = 305;
	tab[17] = 4369;
	tab[18] = 51;

	return (tab);
}

// Creation du tableau final
char	*ft_makesquare(unsigned int size)
{
	char	*result;
	unsigned int		i;
	unsigned int		j;
	unsigned int		count;

	if (!(result = ft_strnew((size * size) + size )))
		return (NULL);
	i = 0;
	j = 0;
	while (j < size)
	{
		count = 0;
		while (count++ < size)
			result[i++] = '.';
		result[i++] = '\n';
		j++;
	}
	return (result);
}

// Verifie validite tetriminos et le remet en haut a gauche pret a etre place
unsigned int	ft_check_tetri(unsigned int bin_value)
{
	unsigned int	*reftab;
	int				i;
	
	i = 0;
	reftab = NULL;
	reftab = ft_init_tab();
	while (i < 19)
	{
		if (bin_value % reftab[i] == 0)
			return (reftab[i]);
		i++;
	}
	return (0);
}

// Creation struct du nouveau tetriminos
t_tetri		*ft_newtetri(int id, char *value_t)
{
	t_tetri		*result;

	if (!(result = ft_memalloc(sizeof(*result))))
		return (NULL);
	result->id = id;
	result->value = id + 'A';
	result->bin_value = ft_check_tetri(ft_atobin(value_t));
	if (result->bin_value == 0)
		return (NULL);
	return (result);
}

t_cursor	*ft_newcursor(int len)
{
	t_cursor	*result;

	if (!(result = ft_memalloc(sizeof(*result))))
		return (NULL);
	result->form = len;
	result->size = ft_sqrt(len * 4);
	result->position = 0;
	result->check = 0;
	return (result);
}

// Affiche une liste de tetriminos
void	ft_displaylist(t_list *list)
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

// Convertit le fichier passe en param en une liste de tetriminos
t_list		*ft_filetolist(char *file)
{
	int				i;
	int				fd;
	int				n_lus;
	char			temp[BUFF_SIZE];
	t_list			*lst;

	lst = NULL;
	i = 0;
	// Open
	if ((fd = open(file, O_RDONLY)) < 0)
		return (NULL);
	// Read en boucle chaque tetriminos
	while ((n_lus = read(fd, temp, BUFF_SIZE)) > 0)
	{
		temp[n_lus] = '\0';
		// Si c'est le premier tetriminos
		if (i == 0)
			lst = ft_lstnew(ft_newtetri(i, temp), sizeof(t_tetri));
		// Les autres
		else
			ft_lstaddend(&lst, ft_lstnew(ft_newtetri(i, temp), sizeof(t_tetri)));
		i++;
	}
	close(fd);
	return (lst);
}

int		main(int ac, char **av)
{
	t_cursor		*cursor;
	t_list	*lst;
	char *result;

	// Affichage
	void	(*f)(t_list *list);
	f = &ft_displaylist;
	//

	if (ac == 2)
	{
		lst = ft_filetolist(av[1]);
		// Affichage de la liste
		ft_lstiter(lst, f);
		//
		cursor = ft_newcursor(ft_lstlen(lst));
		result = ft_makesquare(cursor->size);
		// Affichage de la grille avant
		ft_putstr("Grille avant remplissage :\n");
		ft_putstr(result);
		ft_putchar('\n');
		//ft_lstiter(ft_lsti(lst, 10), f);
		//
		while (!(ft_backtracking(result, *cursor, lst, 0)))
		{
			cursor->size = cursor->size + 1;
			result = ft_makesquare(cursor->size);
		}
		// Affichage de la grille apres
		ft_putstr("Grille apres le remplissage :\n");
		ft_putstr(result);
		ft_putchar('\n');
		//
	}
	return (0);
}
