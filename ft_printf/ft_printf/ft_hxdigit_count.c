/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hxdigit_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcekici <mcekici@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 02:41:08 by mcekici           #+#    #+#             */
/*   Updated: 2024/11/05 02:41:09 by mcekici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_hxdigit_count(unsigned long hex)
{
	if (!(hex / 16))
		return (1);
	else
		return (1 + ft_hxdigit_count(hex / 16));
}
