/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takonaga <takonaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:36:56 by takonaga          #+#    #+#             */
/*   Updated: 2022/10/21 00:26:25 by takonaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	words;
	size_t	i;

	words = 0;
	i = 0;
	while (s[i] != '\0' && s[i + 1] != '\0')
	{
		if (s[i] == c && s[i + 1] != c)
			words++;
		i++;
	}
	return (words);
}

static size_t	move_len(const char *s, char c, int start)
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

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	i;
	size_t	start;

	if (s == NULL)
		return (NULL);
	ptr = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	start = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			ptr[start] = ft_substr(s, i, move_len(s, c, i));
			if (ptr[start++] == NULL)
				return (allfree(ptr));
			i += move_len(s, c, i);
		}
		else
			i++;
	}
	ptr[start] = NULL;
	return (ptr);
}

// int main(int argc, char **argv) {
// 	if (argc == 2) {
// 		char **strs = ft_split(argv[1], ' ');
// 		if (strs == NULL) {
// 			fprintf(stderr, "Error\n");
// 			return 1;
// 		}
// 		size_t i = 0;
// 		for (; strs[i]; i++) {
// 			printf("%s\n", strs[i]);
// 			free(strs[i]);
// 		}
// 		free(strs);
// 	}
// }
