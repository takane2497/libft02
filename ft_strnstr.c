/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takonaga <takonaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 09:00:13 by takonaga          #+#    #+#             */
/*   Updated: 2022/10/17 20:31:58 by takonaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *seek, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	seek_len;

	if (len == 0 && seek != NULL)
		return (NULL);
	seek_len = ft_strlen(seek);
	i = 0;
	while (i < len && str[i] != '\0')
	{
		j = 0;
		while (j < seek_len && (i + j) < len)
		{
			if (str[i + j] != seek[j])
				break ;
			j++;
		}
		if (j == seek_len)
			return ((char *)&str[i]);
		i++;
	}
	return ((char *)str);
}

// int main(void)
// {
// 	printf("%s\n", strnstr(NULL, "aiu", 0));
// }