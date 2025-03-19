/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 23:15:00 by marvin            #+#    #+#             */
/*   Updated: 2025/03/19 23:15:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*jointstr;
	size_t	i;
	size_t	j;

	i = 0;
	j = -1;
	jointstr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2))
			+ 1);
	if (!s1 || !s2)
		return (NULL);
	if (!jointstr)
		return (NULL);
	while (s1[++j])
		jointstr[i++] = s1[j];
	j = -1;
	while (s2[++j])
		jointstr[i++] = s2[j];
	jointstr[i] = '\0';
	return (jointstr);
}
