/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_last_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimhoff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 15:11:18 by mimhoff           #+#    #+#             */
/*   Updated: 2017/12/17 16:59:39 by pihouvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_get_last_tab(int nb)
{
	int		i;
	char	*tab;
	int		j;
	int		len;

	i = 2;
	j = 0;
	while (i * i < (nb))
		i++;
	len = (i * i) + 1 + i;
	tab = ft_memalloc(len);
	while (j < ((i * i) + i + 1))
	{
		tab[j] = '.';
		j++;
	}
	j = i + 1;
	while (tab[i])
	{
		tab[i] = '\n';
		i = i + j;
	}
	tab[len - 1] = '\0';
	return (tab);
}

char	*ft_next_tab(char *ftab, int i)
{
	char	*newtab;
	int		j;
	int		len;

	while (ftab[i] != '\n')
		i++;
	j = 0;
	i = i + 1;
	len = (i * i) + i;
	newtab = malloc(sizeof(char) * len + 1);
	while (j < (len + 1))
	{
		newtab[j] = '.';
		j++;
	}
	j = i + 1;
	while (newtab[i])
	{
		newtab[i] = '\n';
		i = i + j;
	}
	free(ftab);
	newtab[len] = '\0';
	return (newtab);
}

int		ft_get_nb_diese(char *tab)
{
	int		i;
	int		compt;

	i = 0;
	compt = 0;
	while (tab[i])
	{
		if (tab[i] == '#')
			compt++;
		i++;
	}
	return (compt);
}

int		ft_get_nb_tetri(char **tetri)
{
	int i;

	i = 0;
	while (tetri[i])
		i++;
	return (i);
}
