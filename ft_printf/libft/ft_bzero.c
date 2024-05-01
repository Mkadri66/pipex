/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:27:13 by mkadri            #+#    #+#             */
/*   Updated: 2023/10/14 18:36:39 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t str_size)
{
	unsigned int	i;

	i = 0;
	while (i < str_size)
	{
		((unsigned char *) str)[i] = 0;
		i++;
	}
}