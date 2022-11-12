/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:51:02 by lagonzal          #+#    #+#             */
/*   Updated: 2022/11/12 13:37:03 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"

size_t	ft_strlen(char *s1)
{
	size_t	n;

	n = 0;
	while (s1[n])
		n++;
	return (n);
}

char	*ft_strcpy(char *s1, size_t n)
{
	size_t 	i;
	char	*ret;

	i = -1;
	ret = malloc ((n +1) * sizeof(char));
	if (!ret)
		return(NULL);
	while (s1[++i] && i < n - 2)
		ret[i] = s1[i];
	ret[i] = '\0';
	return (ret);
}

char	*ft_strdup(char *str)
{
	int	n;
	char	*dup;

	n = ft_strlen(str);
	dup = malloc((n + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	n = -1;
	while (str[++n])
		dup[n] = str[n];
	dup[n] = '\0';
	return(dup);
}
char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	size_t	n;
	size_t	m;

	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	s3 = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	n = 0;
	m = 0;
	while (s1[m] != '\0')
		s3[n++] = s1[m++];
	m = 0;
	while (s2[m] != '\0')
		s3[n++] = s2[m++];
	s3[n] = '\0';
	free(s1);
	return (s3);
}
