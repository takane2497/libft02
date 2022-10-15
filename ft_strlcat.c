/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takonaga <takonaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 23:49:35 by takonaga          #+#    #+#             */
/*   Updated: 2022/10/10 06:39:17 by takonaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	if (dstsize <= dst_len)
		return (src_len + dstsize);
	while (src[i] != '\0' && (dst_len + i) < (dstsize - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (src_len + dst_len);
}

// int	main(void)
// {
// 	char src1[100] = "takonaga";
// 	char dest1[100] = "aaaaaa";
// 	char src2[100] = "takonaga";
// 	char dest2[100] = "aaaaaa";
// 	unsigned  int	size;

// 	size = 100;
// 	printf("mk: %zu\n", ft_strlcat(dest1, src1, size));
// 	printf("mk: %s\n", dest1);
// 	printf("or: %zu\n", strlcat(dest2, src2, size));
// 	printf("or: %s\n", dest2);

// 	return (0);
// }
