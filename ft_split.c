/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 19:19:58 by wooyang           #+#    #+#             */
/*   Updated: 2025/05/14 15:09:44 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_compter(char const *str, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i -1] == c)
			j++;
		i++;
	}
	return (j);
}

size_t	ft_pareil(size_t i, char const *s, char c)
{
	while (s[i] == c)
		i++;
	return (i);
}

void	ft_free(char **resultat, size_t j)
{
	while (j >= 0)
	{
		free(resultat[j]);
		j--;
	}
	free(resultat);
}

char	**ft_split(char const *s, char c)
{
	char	**resultat;
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	resultat = malloc(sizeof(char *) * (ft_compter(s, c) + 1));
	if (resultat == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		i = ft_pareil(i, s, c);
		start = i;
		while (s[i] != c && s[i])
			i++;
		if (i > start)
		{
			resultat[j] = ft_substr(s, start, i - start);
			if (resultat[j] == NULL)
				return (ft_free(resultat, j), NULL);
			j++;
		}
	}
	return (resultat[j] = NULL, resultat);
}
/*
int	main(void)
{
//	int	n = ft_compter("poooivroo", 'o');
	size_t	i = 0;
	char	texte1[] = "po     i      v r o  n a";
	char	**resultat = ft_split(texte1, ' ');
	while (resultat[i])
	{
		printf("%s\n", resultat[i]);
		i++;
	}
	printf("%s\n", resultat[i]);
//	printf("%s\n", n);
	return (0);
}*/
