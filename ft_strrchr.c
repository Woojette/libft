/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 19:07:28 by wooyang           #+#    #+#             */
/*   Updated: 2025/05/14 16:09:45 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int val)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (val == '\0' && str[i] == '\0')
		return ((char *)&str[i]);

	i = i - 1;
	while (i >= 0)
	{
		if (str[i] == val)
			return ((char *)&str[i]);
		i--;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	hihihi[] = "hihihi";
	char	*hihihi_strchr = strchr(hihihi, 'h');
	char	*hihihi_strrchr_ft = ft_strrchr(hihihi, 'h');
	char    *hihihi_strrchr_vrai = strrchr(hihihi, 'h');
	char	*hihihi_ab_strrchr_ft = ft_strrchr(hihihi, 'o');
	char    *hihihi_ab_strrchr_vrai = strrchr(hihihi, 'o');
	printf("strchr = %s\n\n", hihihi_strchr);
	printf("strrchr = %s (ft)\n", hihihi_strrchr_ft);
	printf("strrchr = %s (vrai)\n\n", hihihi_strrchr_vrai);
	printf("ab = %s (ft)\n", hihihi_ab_strrchr_ft);
	printf("ab = %s (vrai)\n\n", hihihi_ab_strrchr_vrai);
	return (0);
}*/
