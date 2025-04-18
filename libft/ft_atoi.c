/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcekici <mcekici@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:11:13 by mcekici           #+#    #+#             */
/*   Updated: 2024/10/16 14:11:13 by mcekici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	sign;
	int	value;

	sign = 1;
	value = 0;
	while ((*str <= 13 && *str >= 9) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str ++;
	}
	while (*str <= '9' && *str >= '0')
		value = value * 10 + (*str++ - '0');
	return (value * sign);
}
