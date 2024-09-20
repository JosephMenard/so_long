/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:14:14 by jmenard           #+#    #+#             */
/*   Updated: 2024/05/27 19:34:37 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list_content;

	list_content = malloc(sizeof(struct s_list));
	if (!list_content)
		return (NULL);
	list_content->content = content;
	list_content->next = NULL;
	return (list_content);
}
