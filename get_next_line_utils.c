/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 12:32:01 by lagonzal          #+#    #+#             */
/*   Updated: 2022/11/12 18:50:57 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s1)
{
	size_t	n;

	if (!s1)
		return(0);
	n = 0;
	while (s1[n])
		n++;
	return (n);
}

char	*ft_strcat(char *s1, char *s2)
{
	char	*s3;
	size_t	len1;
	size_t	len2;
	int		n;
	int		m;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if ((len1 + len2) == 0)
		return (NULL);
	s3 = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	n = -1;
	while (s1[++n])
		s3[n] = s1[n];
	m = -1;
	while (s2[++m])
	{	
		s3[n] = s2[m];
		n++;
	}
	s3[n] = '\0';
	return(s3);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;

	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s2)
		return (free(s1),NULL);
	s3 = ft_strcat(s1, s2);
	free(s1);
	if (!s3)
		return (NULL);
	//printf("first: %s\n", s3);
	return (s3);
}

char	*ft_strdup(char *orig)
{
	size_t	n;
	char	*dup;

	dup = malloc(ft_strlen(orig) + 1);	
	n = -1;
	while (orig[++n])
		dup[n] = orig[n];
	dup[n] = '\0';
	return (dup);
}

char	*ft_strcpy(char *left, size_t end)
{
	char	*ret;
	size_t		n;

	n = -1;
	ret = malloc((end) * sizeof(char));
	if (!ret)
		return (NULL);
	while (++n < end)
		ret[n] = left[n];
	ret[n] = '\0';
	return (ret);
}
