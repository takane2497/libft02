/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takonaga <takonaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 09:00:13 by takonaga          #+#    #+#             */
/*   Updated: 2022/10/13 19:13:34 by takonaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *seek, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	seek_len;

	if (!*seek)
		return ((char *)str);
	if (len == 0)
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
	return (NULL);
}

// int main(void)
// {
// 	char *a = "ABCdefg";
// 	char b[] = "C";
// 	size_t	len = 6;
// 	printf("%s\n", ft_strnstr(a, b, len));
// 	printf("%s\n", strnstr(a, b, len));
// }