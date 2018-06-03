/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_final_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:40:27 by alefebvr          #+#    #+#             */
/*   Updated: 2017/12/17 17:02:00 by pihouvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_final_place(char **tetri, char *ftab, int o)
{
	int		*pos;

	if (o == ft_get_nb_tetri(tetri))
	{
		ft_putstr(ftab);
		ft_freedoubletab(tetri);
		exit(1);
	}
	pos = ft_tetri_position(tetri[o], ftab);
	if (ft_is_placeable(ftab, pos) >= 0)
	{
		ft_fill_tab(ftab, tetri[o], ft_is_placeable(ftab, pos), pos);
		free(pos);
		if (ft_final_place(tetri, ftab, o + 1) == 1)
			return (1);
		else
		{
			while (ft_back(ftab, tetri[o]) == 1)
				ft_final_place(tetri, ftab, o + 1);
			return (0);
		}
	}
	else
		free(pos);
	return (0);
}

int		ft_back(char *ftab, char *tetri)
{
	char	letter;
	int		i;
	int		*pos;

	pos = ft_tetri_position(tetri, ftab);
	i = 0;
	while (tetri[i] == '.')
		i++;
	letter = tetri[i];
	i = ft_back2(letter, ftab, pos);
	while (ftab[i + pos[0]] && ftab[i + pos[1]] && ftab[i + pos[2]] &&
			ftab[i + pos[3]])
	{
		if (ftab[i + pos[0]] == '.' && ftab[i + pos[1]] == '.' &&
				ftab[i + pos[2]] == '.' && ftab[i + pos[3]] == '.')
		{
			ft_fill_tab(ftab, tetri, i, pos);
			free(pos);
			return (1);
		}
		i++;
	}
	free(pos);
	return (0);
}

int		ft_is_placeable(char *ftab, int *pos)
{
	int i;

	i = 0;
	while (ftab[i + pos[0]] && ftab[i + pos[1]] && ftab[i + pos[2]] &&
			ftab[i + pos[3]])
	{
		if (ftab[i + pos[0]] == '.' && ftab[i + pos[1]] == '.' &&
				ftab[i + pos[2]] == '.' && ftab[i + pos[3]] == '.')
			return (i);
		i++;
	}
	return (-1);
}

void	ft_fill_tab(char *ftab, char *tetri, int place, int *pos)
{
	int		i;
	char	letter;

	i = 0;
	while (tetri[i] == '.' || tetri[i] == '\n')
		i++;
	letter = tetri[i];
	i = 0;
	while (i < 4)
	{
		ftab[place + pos[i]] = letter;
		i++;
	}
}

void	ft_final_tab(char **tetri, char *tab)
{
	char	*final_tab;
	int		i;

	final_tab = ft_get_last_tab(ft_get_nb_diese(tab));
	free(tab);
	i = ft_final_place(tetri, final_tab, 0);
	while (i == 0)
	{
		final_tab = ft_next_tab(final_tab, 0);
		i = ft_final_place(tetri, final_tab, 0);
	}
}
