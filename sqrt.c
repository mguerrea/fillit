/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sqrt.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 23:25:44 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/10 23:27:55 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_update_bounds(long long guess, int nb, int *lower, int *higher)
{
	if (guess * guess > nb)
		*higher = guess;
	else if (guess * guess < nb)
		*lower = guess;
}

int		ft_sqrt(int nb)
{
	int			lower;
	int			higher;
	long long	guess;

	if (nb <= 1)
		return (0);
	lower = 0;
	higher = nb / 2;
	guess = (lower + higher) / 2;
	while (guess * guess != nb)
	{
		guess = (lower + higher) / 2;
		ft_update_bounds(guess, nb, &lower, &higher);
		if (higher - lower == 1)
		{
			guess = higher;
			break ;
		}
		guess = (lower + higher) / 2;
	}
	return (guess);
}
