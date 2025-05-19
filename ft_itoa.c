/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:44:00 by wooyang           #+#    #+#             */
/*   Updated: 2025/05/14 19:25:23 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_compter(int n)
{
	int	signe;
	int	len;

	signe = 0;
	len = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		signe = 1;
		n = n * (-1);
	}
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	len = len + signe;
	return (len);
}

char	*ft_itoa(int n)
{
	int		i;
	int		len;
	int		temp;
	char	*resultat;

	i = 0;
	len = ft_compter(n);
	resultat = malloc(sizeof(char) * (len + 1));
	if (resultat == NULL)
		return (NULL);
	while (i < len)
	{
		temp = n % 10;
		if (temp < 0)
			temp = temp * -1;
		resultat[len - i -1] = temp + '0';
		n = n / 10;
		i++;
	}
	if (resultat[0] == '0' && len > 2)
		resultat[0] = '-';
	resultat[len] = '\0';
	return (resultat);
}

/*int	main(void)
{
	char	*np = ft_itoa(2411);
	char	*np2 = ft_itoa(112400);
	char	*nn = ft_itoa(-2147483648);
	char	*nn2 = ft_itoa(-0);
	char	*zero = ft_itoa(0);
	char	*n1 = ft_itoa(5);
	printf("%d\n", (-25)%10);
	printf("2411 = %s\n", np);
	printf("112400 = %s\n", np2);
	printf("-2147483648 = %s\n", nn);
	printf("-456543000 = %s\n", nn2);
	printf("0 = %s\n", zero);
	printf("5 = %s\n", n1);
	free(np);
	free(np2);
	free(nn);
	free(nn2);
	free(zero);
	free(n1);
	return (0);
}*/
