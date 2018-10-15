/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 21:21:45 by llanga            #+#    #+#             */
/*   Updated: 2018/06/15 11:32:40 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *space;

	space = (char*)malloc(sizeof(char*) * size);
	if (space == NULL)
		return (NULL);
	else
		ft_bzero(space, size);
	return (space);
}
