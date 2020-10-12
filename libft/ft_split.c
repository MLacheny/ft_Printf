/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacheny <mlacheny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 16:16:59 by mlacheny          #+#    #+#             */
/*   Updated: 2020/06/11 19:05:52 by mlacheny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*ft_wordup(char *start, char *end)
{
	char	*word;
	int		i;

	if (!(word = malloc(sizeof(*word) * (end - start + 1))))
		return (0);
	i = 0;
	while (i < (end - start))
	{
		word[i] = start[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	*ft_count_letters(int *i, char const *str, char sep)
{
	int		j;
	int		fl;

	fl = 1;
	while (str[*i] != sep && str[*i] != '\0')
	{
		if (fl == 1)
		{
			j = *i;
			fl = 0;
		}
		*i = *i + 1;
	}
	return (ft_wordup((char *)str + j, (char *)str + *i));
}

static int	ft_count_words(char const *str, char sep)
{
	int i;
	int nb_words;
	int fl;

	nb_words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		fl = 1;
		while (str[i] != sep && str[i] != '\0')
		{
			if (fl == 1)
			{
				fl = 0;
				nb_words++;
			}
			i++;
		}
		while (str[i] == sep && str[i] != '\0')
			i++;
	}
	nb_words++;
	return (nb_words);
}

static char	**ft_free_words(char **words, int nb_words)
{
	int i;

	i = -1;
	while (++i < nb_words)
		free(words[i]);
	free(words);
	words = 0;
	return (words);
}

char		**ft_split(char const *str, char sep)
{
	int		i;
	int		nb_words;
	char	**words;
	char	*word;

	if (!(words = malloc(sizeof(*words) * ft_count_words(str, sep))))
		return (0);
	i = 0;
	nb_words = 0;
	while (str[i] != '\0')
	{
		while (str[i] == sep && str[i] != '\0')
			i++;
		nb_words++;
		if (str[i])
		{
			if (!(word = ft_count_letters(&i, str, sep)))
				return (ft_free_words(words, nb_words - 1));
			words[nb_words - 1] = word;
		}
		else
			nb_words--;
	}
	words[nb_words] = 0;
	return (words);
}
