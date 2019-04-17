/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 10:06:10 by exam              #+#    #+#             */
/*   Updated: 2019/03/19 13:17:55 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


int		count(char c)
{
	if (c == '(')
		return (0);
	if (c == '{')
		return (1);
	if (c == '[')
		return (2);
	if (c == ')')
		return (3);
	if (c == '}')
		return (4);
	if (c == ']')
		return (5);
	return (-1);		
}

int		recursive(char *str, int *i)
{
	int		p = 0;
	char	first;

	while (count(str[*i]) == -1 && str[*i])
		(*i)++;
	if (count(str[*i]) > 2)
		return (1);
	if (str[*i] == '\0')
		return (0);
	first = str[*i];
	while (str[++(*i)])
	{
		p = count(str[*i]);
		if (p == 0 || p == 1 || p == 2)
		{
			if (recursive(str, i))
				return (1);
		}
		if (p == 3 || p == 4 || p == 5)
		{
			if (count(str[*i]) == count(first) + 3)
				return (0);
			else 
				return (1);
		}
	}
	return (1);
}

int		parse(char *str)
{
	int		i = -1;
	int		oc[6] = {0};
	int		p = -2;

	while (str[++i])
	{
		p = count(str[i]);
		if (p != -1)
			oc[p] += 1;
	}
	if (oc[0] != oc[3] || oc[1] != oc[4] || oc[2] != oc[5])
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	int 	i = 0;
	int		j;

	if (ac < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (++i < ac)
	{
		j = 0;
		if (recursive(av[i], &j) || parse(av[i]))
			write(1, "Error\n", 6);
		else
			write(1, "OK\n", 3);	
	}
	return (0);
}
