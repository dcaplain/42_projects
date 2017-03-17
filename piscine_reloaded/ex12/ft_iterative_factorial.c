/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaplain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:04:12 by dcaplain          #+#    #+#             */
/*   Updated: 2016/11/11 14:51:19 by dcaplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int		temp;

	temp = nb - 1;
	if (nb == 0 || nb == 1)
		return (1);
	else if (nb > 1)
	{
		while (temp > 0)
		{
			nb = nb * temp;
			temp--;
		}
		return (nb);
	}
	else
		return (0);
}
