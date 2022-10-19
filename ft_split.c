/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takonaga <takonaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:36:56 by takonaga          #+#    #+#             */
/*   Updated: 2022/10/19 21:10:06 by takonaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	size_t	words;
	size_t	i;

	words = 0;
	i = 0;
	if (c < 0)
		return (0);
	if (s[0] != c)
		words++;
	while (s[i] != '\0' && s[i + 1] != '\0')
	{
		if (s[i] == c && s[i + 1] != c)
			words++;
		i++;
	}
	return (words);
}

static int	move_len(const char *s, char c, int start)
{
	size_t	i;

	i = 0;
	while (s[start + i] != c && s[start + i] != '\0')
		i++;
	return (i);
}

static char	**allfree(char **ptr)
{
	size_t	i;

	i = 0;
	while (ptr[i] != NULL)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (NULL);
}

void	*ft_xmalloc(size_t bytes)
{
	void	*temp;

	temp = malloc(bytes);
	if (temp == 0)
		return (NULL);
	return (temp);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	i;
	size_t	start;

	if (s != NULL)
		return (NULL);
	ptr = (char **)ft_xmalloc(sizeof(char *) * (count_words(s, c) + 1));
	i = 0;
	start = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			ptr[start] = ft_substr(s, i, move_len(s, c, i));
			if (ptr[start++] == NULL)
				return (ft_allfree(**ptr));
			i += move_len(s, c, i);
			start++;
		}
		else
			i++;
	}
	ptr[start] = NULL;
	return (ptr);
}

