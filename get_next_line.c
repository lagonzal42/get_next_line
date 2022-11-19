/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 12:13:06 by lagonzal          #+#    #+#             */
/*   Updated: 2022/11/19 16:26:53 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char	*ft_clean(char *s)
{
	free(s);
	s = NULL;
	return(s);
}

int	ft_strchr(char *s, char c)
{
	int	n;

	n = 0;
	if (!s)
		return (-1);
	while (s[n] != c && s[n] != '\0')
		n++;
	if (s[n] == c)
		return (n);
	return(-1);
}

char	*ft_read_file(int fd, char *left)
{
	int		readed;
	char	*reader;

	readed = 1;
	reader = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!reader)
		return (NULL);
	while (readed > 0 && ft_strchr(left, '\n') == -1)
	{
		readed = read(fd, reader, BUFFER_SIZE);
		if (readed == -1)
		{	
			free(reader);
			return (ft_clean(left));
		}
		reader[readed] = '\0';
		left = ft_strjoin(left, reader);
		if (!left)
			return (free(reader), ft_clean(left));
	}
	return(free(reader), left);
}

char	*ft_depurate(char *left, int pos_lb)
{
	char	*dep;
	
	if ((int)(ft_strlen(left)) <= pos_lb)
	{
		free(left);
		left = NULL;
		return (left);
	}
	dep = ft_strdup(&left[pos_lb]);
	return (free(left), dep);
}
char	*get_next_line(int fd)
{
	static char	*left;
	char		*ret;
	int			pos;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	left = ft_read_file(fd, left);
	if (!left)
		return(NULL);
	ret = NULL;
	pos = ft_strchr(left, '\n');
	if (pos == -1)
	{
		if (left[0] != '\0')
			ret = ft_strdup(left);
		free(left);
		left = NULL;
		return (ret);
	}
	ret = ft_strcpy(left, pos + 1);
	left = ft_depurate (left, pos + 1);
	return (ret);
}

/*int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char *str;
	str = get_next_line(fd);
	while (str)
	{
		printf("%s\n", str);
		free (str);
		str = get_next_line(fd);
	}
	//char *s = get_next_line(fd);
	//printf("%s\n", s);
	return(0);
}*/
