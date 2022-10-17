/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takonaga <takonaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 02:07:50 by takonaga          #+#    #+#             */
/*   Updated: 2022/10/17 20:27:25 by takonaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*substr;

	if (s == NULL)
		len = 0;
	else
	{
		s_len = (ft_strlen(s));
		if (s_len <= start)
			len = 0;
		else if (len > s_len - start)
			len = s_len - start;
	}
	len++;
	substr = (char *)malloc(sizeof(char) * len);
	if (substr == NULL)
		return (NULL);
	if (len == 1)
		*substr = '\0';
	else
		ft_strlcpy(substr, s + start, len);
	return (substr);
}
