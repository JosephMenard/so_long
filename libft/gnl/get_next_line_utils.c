/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:29:50 by jmenard           #+#    #+#             */
/*   Updated: 2024/09/13 13:32:51 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned long int		j;
	char					*new_str;

	j = 0;
	if (start >= (unsigned long int)ft_strle((s)))
	{
		new_str = (char *)malloc(1 * sizeof(char));
		if (!new_str)
			return (NULL);
		new_str[0] = '\0';
		return (new_str);
	}
	if (len > (unsigned long int)ft_strle(s) - start)
		len = (unsigned long int)ft_strle(s) - start;
	new_str = (char *)malloc(len + 1 * sizeof(char));
	if (!new_str)
		return (NULL);
	while (j < len && s[start + j])
	{
		new_str[j] = s[start + j];
		j++;
	}
	new_str[j] = '\0';
	return (new_str);
}

int	ft_strle(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_newstr(char const *s1, char const *s2, int s1_len, int s2_len)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	new_str = (char *)malloc(s1_len + s2_len + 1 * sizeof(char));
	if (!new_str)
		return (NULL);
	while (i < s1_len)
	{
		new_str[i] = s1[i];
		i++;
	}
	while (j < s2_len)
	{
		new_str[i] = s2[j];
		j++;
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	char	*buffer;

	s1_len = ft_strle(s1);
	s2_len = ft_strle(s2);
	buffer = ft_newstr(s1, s2, s1_len, s2_len);
	if (!buffer)
		return (NULL);
	return (buffer);
}
