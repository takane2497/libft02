/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takonaga <takonaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 08:18:54 by takonaga          #+#    #+#             */
/*   Updated: 2022/10/12 20:52:37 by takonaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	converter(int n)
{
	if (n == 0)
		return (0);
	else if (n > 0)
		return (1);
	else
		return (-1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0 || (s1 == '\0' && s2 == '\0'))
		return (0);
	i = 0;
	while (s1[i] != '\0' && s1[i] != '\0' && s1[i] == s2[i] && i < n - 1)
		i++;
	return (converter((unsigned char)s1[i] - (unsigned char)s2[i]));
}

// int main(void)
// {
// 	printf("%d\n", ft_strncmp("1235", "1235", 3));
// 	printf("%d\n", strncmp("1235", "1235", 3));
// }