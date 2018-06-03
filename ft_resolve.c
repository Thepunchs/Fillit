/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 16:08:33 by alefebvr          #+#    #+#             */
/*   Updated: 2017/12/14 21:53:40 by alefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_change(char **tetri)
{
	int		i;
	int		j;
	char	c;

	c = 'A';
	j = 0;
	i = 0;
	while (tetri[i])
	{
		while (tetri[i][j])
		{
			if (tetri[i][j] == '#')
				tetri[i][j] = c;
			j++;
		}
		j = 0;
		i++;
		c++;
	}
	return (tetri);
}

char	**ft_clean_verti(char **tab)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (tab[i])
	{
		while (tab[i][0] == '.' && tab[i][5] == '.' && tab[i][10] == '.'
			&& tab[i][15] == '.')
		{
			while (tab[i][j])
			{
				if (tab[i][j] == '#')
				{
					tab[i][j - 1] = tab[i][j];
					tab[i][j] = '.';
				}
				j++;
			}
			j = 0;
		}
		i++;
	}
	return (tab);
}

char	**ft_clean_horiz(char **tab)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (tab[i])
	{
		while (tab[i][0] == '.' && tab[i][1] == '.' && tab[i][2] == '.'
			&& tab[i][3] == '.')
		{
			while (tab[i][j])
			{
				if (tab[i][j] == '#')
				{
					tab[i][j - 5] = tab[i][j];
					tab[i][j] = '.';
				}
				j++;
			}
			j = 0;
		}
		i++;
	}
	return (tab);
}

void	ft_double(char *tab)
{
	char	**tetriminos;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tetriminos = ft_memalloc((ft_strlen(tab) / 20) + 1);
	while (tab[i] && j <= (((int)ft_strlen(tab)) / 20))
	{
		tetriminos[j] = ft_strsub(tab, i, 20);
		i++;
		i = i + 20;
		j++;
	}
	tetriminos[j] = 0;
	ft_clean_verti(tetriminos);
	ft_clean_horiz(tetriminos);
	ft_change(tetriminos);
	ft_final_tab(tetriminos, tab);
	i = 0;
	while (j > i)
		free(tetriminos[i++]);
	free(tetriminos);
}
