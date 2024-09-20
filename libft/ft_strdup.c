/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:01:18 by jmenard           #+#    #+#             */
/*   Updated: 2024/05/29 14:49:27 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	int		str_len;
	char	*src_dup;
	int		i;

	i = 0;
	str_len = ft_strlen((const char *)src);
	src_dup = (char *)malloc(str_len + 1 * sizeof(char));
	if (src_dup == NULL)
		return (NULL);
	while (src[i])
	{
		src_dup[i] = src[i];
		i++;
	}
	src_dup[i] = '\0';
	return (src_dup);
}