/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:49:50 by lagonzal          #+#    #+#             */
/*   Updated: 2022/11/11 20:59:07 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	ft_strchr(char *s, int c)
{
	int	n;

	n = 0;
	while (s[n] != (char)c && s[n] != '\0')
		n++;
	if (s[n] == (char)c)
		return (n);
	return (-1);
}

char	*ft_depurate(char *orig, int pos)
{
	char	*dep;
	int	len;

	len = ft_strlen(orig);
	if (len - pos <= 1)
	{
		free(orig);
		return (NULL);
	}
	dep = ft_strdup(&orig[pos + 1]);
	if (!dep)
		return (NULL);
	free(orig);
	return (dep);
}

char	*ft_read_file(int fd, char *save)
{
	int		end;
	char	*readed;
	int		pos;

	end = 1;
	pos = -1;
	readed = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if(!readed)
		return (NULL);
	while (end > 0 && pos == -1)
	{
		end = read(fd,readed, BUFFER_SIZE);
		if (end < 0)
		{
			free(readed);
			return (NULL);
		}
		readed[end] = '\0';
		save = ft_strjoin(save, readed);
		if (!save)
		{
			free(readed);
			return(NULL);
		}
		pos = ft_strchr(save, '\n');
	}
	free(readed);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*ret;
	int	pos;

	if (fd <= 0 || BUFFER_SIZE <= 0) 
		return (NULL);
	save = ft_read_file(fd, save);
	if (!save)
		return (NULL);
	pos = ft_strchr(save, '\n');
	if (ft_strlen(save) == 0)
	{	
		free(save);
		return (NULL);
	}
	if (pos == -1)
	{	
		ret = ft_strcpy(save, ft_strlen(save) + 2);
		free(save);
		return(ret);
	}
	else
	{	
		ret = ft_strcpy(save, pos + 2);
		save = ft_depurate(save, pos);
	}
	return(ret);
}

/*int	main (void)
{
	int	fd;
	char	*line;
	fd = open("1char.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	return (0);
}*/
