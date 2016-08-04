/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 17:35:05 by mfernand          #+#    #+#             */
/*   Updated: 2016/08/03 17:35:06 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		main(int ac, char **av)
{
	int		i;
	t_bsq	*input;

	i = 1;
	if (ac > 1)
	{
		while (i < ac)
		{
			input = get_file_input(av[i]);
			bsq(input);
			i++;
		}
	}
	else
	{
		input = get_std_input();
		bsq(input);
	}
	return (0);
}
