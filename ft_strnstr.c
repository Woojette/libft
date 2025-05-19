/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:29:56 by wooyang           #+#    #+#             */
/*   Updated: 2025/05/02 17:46:51 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	compteur;

	compteur = 0;
	i = 0;
	j = 0;

	if (!little[i])
			return ((char *)big);
	while (big[i] && (i < len))
	{
		while (j < ft_strlen(little) && i + j < len)
		{
			// printf("i: %zu, j: %zu, little: %c, big: %c\n", i, j, little[j], big[i + j]);
			if (big[i + j] != little[j])
				break;
			j++;
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
		j = 0;
		compteur = 0;
		// printf("\n");
	}
	return (NULL);
}