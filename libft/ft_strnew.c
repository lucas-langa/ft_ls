/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 10:59:43 by llanga            #+#    #+#             */
/*   Updated: 2018/06/06 08:51:35 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define NULL_BYTE 1

char	*ft_strnew(size_t size)
{
	char *nw_str;

	nw_str = (char*)malloc(sizeof(char) * (size + NULL_BYTE));
	if (nw_str == NULL)
		return (NULL);
	ft_bzero((char*)nw_str, (size + NULL_BYTE));
	return (nw_str);
}
