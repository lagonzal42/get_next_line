/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 12:13:06 by lagonzal          #+#    #+#             */
/*   Updated: 2022/11/12 15:20:01 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_free_n_null(void *ptr)
{
	free(ptr);
	return(NULL);
}

int	ft_strchr(char *s, int c)
{
	int	n;

	n = 0;
	if (!s)
		return (-1);
	while (s[n] != (char)c && s[n])
		n++;
	if (s[n] == (char)c)
		return (n);
	return (-1);
}

char	*ft_read_file(int fd, char *left)
{
	int		readed;
	char	*reader;
	int		pos;

	readed = 1;
	pos = -1;
	reader = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!reader)
		return (NULL);
	while (readed > 0 && pos == -1)
	{
		readed = read(fd, reader, BUFFER_SIZE);
		if (readed == 0)
			break;
		if (readed == -1)
		{
			free(reader);
			return (NULL);
		}
		reader[readed] = '\0';
		left = ft_strjoin(left, reader);
		if (!left)
		{
			free(reader);
			return (NULL);
		}
		pos = ft_strchr(left, '\n');
	}
	free(reader);
	return(left);
}

char	*ft_depurate(char *left, int pos_lb)
{
	char	*dep;
	
	if (ft_strlen(&left[pos_lb]) == 0)
	{	
		free(left);
		return (NULL);
	}
	dep = ft_strdup(&left[pos_lb]);
	free(left);
	return (NULL);
}
char	*get_next_line(int fd)
{
	static char	*left;
	char		*ret;
	int			pos;

	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	left = ft_read_file(fd, left);
	if (!left)
		return(NULL);
	pos = ft_strchr(left, '\n');
	if (pos == -1)
	{
		if (left[0] == '\0')
		{	
			free(left);
			return (NULL);
		}
		ret = ft_strdup(left);
		free(left);
		return (ret);
	}
	ret = ft_strcpy(left, pos + 2);
	left = ft_depurate (left, pos + 2);
	return (ret);
}
