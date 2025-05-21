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

size_t	ft_debut(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1[0] == '\0')
		return 0;
	while (s1 != NULL && s1[i] != '\0')
	{
		while (set[j] != '\0' && s1[i] != set[j])
			j++;
		if (set[j] == '\0')
			return (i);
		j = 0;
		i++;
	}
	if (i == ft_strlen(s1))
		return (1);
	return (i);
}

size_t		ft_fin(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (s1[0] == '\0')
		return 0;
	j = ft_strlen(s1) - 1;

	while (j > 0)
	{
		while (set[i] != '\0' && s1[j] != set[i])
			i++;
		if (set[i] == '\0')
			return (j);
		i = 0;
		j--;
	}
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	k;
	size_t	d;
	size_t	f;
	size_t	len;
	char	*resultat;

	k = 0;
	len = ft_strlen(s1);
	d = ft_debut(s1, set);
	// printf("d:%zu\n", d);
	f = ft_fin(s1, set);
	// printf("f:%zu\n", f);
	resultat = malloc(sizeof(char) * (f - d  + 2));
	if (resultat == NULL)
		return (NULL);
	while (d <= f)
	{
		resultat[k] = s1[d];
		k++;
		d++;
	}
	resultat[k] = '\0';
	return (resultat);
}

// int	main(void)
// {
// 	char	texte[] = "  \t \t \n   \n\n\n\t";
// 	char	set[] = "\n \t";
// 	char	*resultat = ft_strtrim(texte, set);
// 	printf("avant : %s\n", texte);
// 	printf("apres : %s\n", resultat);
// 	return (0);
// }
