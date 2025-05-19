/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:09:45 by wooyang           #+#    #+#             */
/*   Updated: 2025/05/12 17:38:15 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	len;
	char	*resultat;

	i = 0;
	j = 0;
	k = 0;
	len = ft_strlen(s1);
	resultat = malloc(sizeof(char) * (len + 1));
	if (resultat == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		while (set[j] != '\0' && s1[i] != set[j])
			j++;
		if (set[j] == '\0')
			resultat[k++] = s1[i];
		i++;
		j = 0;
	}
	resultat[k] = '\0';
	return (resultat);
}
/*
int	main(void)
{
	char	texte[] = "\tb\to\tn jo\tu\tr";
	char	set[] = "r \t";
	char	*resultat = ft_strtrim(texte, set);
	printf("avant : %s\n", texte);
	printf("apres : %s\n", resultat);
	return (0);
}*/
