/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:15:49 by alefebvr          #+#    #+#             */
/*   Updated: 2017/12/13 18:01:28 by alefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_secure_me(char *tab, int i, int s)
{
	if (s == 1)
	{
		if ((tab[i + 1] == '\n' && tab[i + 2] == '\n') || (tab[i + 2] == '\n'
					&& tab[i + 3] == '\n') || (tab[i + 3] == '\n'
						&& tab[i + 4] == '\n'))
			return (1);
	}
	if (s == 2)
	{
		if ((tab[i - 1] == '\n' && tab[i - 2] == '\n') || (tab[i - 2] == '\n'
					&& tab[i - 3] == '\n') || (tab[i - 3] == '\n'
						&& tab[i - 4] == '\n'))
			return (1);
	}
	return (0);
}

static int		ft_valid_un(char *tab, int j, int k, int l)
{
	int		i;
	int		m;

	i = 0;
	while (tab[i])
	{
		if (tab[i] != '\n' && tab[i] != '#' && tab[i] != '.' && tab[i] != '\0')
			return (0);
		if (tab[i] == '.')
			j++;
		if (tab[i] == '#')
			k++;
		if (tab[i] == '\n')
			l++;
		if (l % 5 == 4 && k % 4 == 0 && tab[i] != '\n')
			return (0);
		i++;
	}
	m = 1;
	if (i > 430)
		m++;
	if (j != (k * 3) || (k != (l - ((i / 20) - m))))
		return (0);
	return (1);
}

static int		ft_valid_deux(char *tab, int i, int j, int compt)
{
	while (tab[i])
	{
		j = 0;
		while (j++ < 20)
		{
			if (tab[i] == '#' && tab[i + 1] == '#')
				compt++;
			if (tab[i] == '#' && tab[i - 1] == '#')
				compt++;
			if (tab[i] == '#' && tab[i + 5] == '#')
				if (!(ft_secure_me(tab, i, 1)))
					compt++;
			if (tab[i] == '#' && tab[i - 5] == '#')
				if (!(ft_secure_me(tab, i, 2)))
					compt++;
			i++;
		}
		if (compt != 6 && compt != 8)
			return (0);
		compt = 0;
		if (tab[i] == '\n' && tab[i + 1] == '\0')
			return (0);
		i++;
	}
	return (1);
}

int				ft_valid_trois(char *tab)
{
	if (ft_valid_deux(tab, 0, 0, 0) && ft_valid_un(tab, 0, 0, 0))
		return (1);
	return (0);
}
