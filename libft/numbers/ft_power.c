/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 23:13:55 by lemarino          #+#    #+#             */
/*   Updated: 2025/07/19 23:15:58 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// Multiplies or divides nbr for itself a number of times equal to power.
//  Moltiplication if power > 0. Division if power < 0.
// Returns 1 if power=0; Returns 0 if nbr=0
int	ft_ipow(int nbr, int power)
{
	int i;
	int	n;

	i = 0;
	n = nbr;
	if (nbr == 0)
		return (0);
	if (power == 0)
		return (1);
	else if (power > 0)
	{
		while (i++ < power)
			n = n * nbr;
	}
	else if (power < 0)
	{
		while (i-- > power)
			n = n / nbr;
	}
	return (n);
}

// Multiplies or divides nbr for itself a number of times equal to power.
//  Moltiplication if power > 0. Division if power < 0.
// Returns 1 if power=0; Returns 0 if nbr=0
int	ft_fpow(float nbr, int power)
{
	int i;
	int	n;

	i = 0;
	n = nbr;
	if (nbr == 0)
		return (0);
	if (power == 0)
		return (1);
	else if (power > 0)
	{
		while (i++ < power)
			n = n * nbr;
	}
	else if (power < 0)
	{
		while (i-- > power)
			n = n / nbr;
	}
	return (n);
}
