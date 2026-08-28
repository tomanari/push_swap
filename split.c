/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-a <malves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 16:13:23 by malves-a          #+#    #+#             */
/*   Updated: 2026/08/25 19:03:12 by malves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_space(char character, char separator)

{
	return (character == separator || character == '\t' || character == '\n'
		|| character == '\v' || character == '\f' || character == '\r');
}

int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (!is_space(*s, c) && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (is_space(*s, c))
			in_word = 0;
		s++;
	}
	return (count);
}

void	free_tokens(char **tokens)
{
	int	i;

	if (!tokens)
		return ;
	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

static char	**free_all(char **strs, int i)
{
	while (i >= 0)
	{
		free(strs[i]);
		i--;
	}
	free(strs);
	return (NULL);
}

static char	*get_next_word(char const **s, char c)
{
	int		len;
	int		i;
	char	*word;

	len = 0;
	while (is_space(**s, c))
		(*s)++;
	while ((*s)[len] && !is_space((*s)[len], c))
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = (*s)[i];
		i++;
	}
	word[i] = '\0';
	*s += len;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		words;
	int		i;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	strs = malloc(sizeof(char *) * (words + 1));
	if (!strs)
		return (NULL);
	i = 0;
	while (i < words)
	{
		strs[i] = get_next_word(&s, c);
		if (!strs[i])
			return (free_all(strs, i - 1));
		i++;
	}
	strs[i] = NULL;
	return (strs);
}
