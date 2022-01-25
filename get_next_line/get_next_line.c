/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jturunen <jturunen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:44:04 by jturunen          #+#    #+#             */
/*   Updated: 2022/01/25 17:29:10 by jturunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static char	*get_line(char *save)
{
	int		i;
	char	*line;

	i = 0;
	if (!save)
		return (0);
	while (save[i] && save[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (0);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*get_save(char *save)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	if (!save)
		return (0);
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (0);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!str)
		return (0);
	i++;
	j = 0;
	while (save[i])
		str[j++] = save[i++];
	str[j] = '\0';
	free(save);
	return (str);
}

static char	*read_and_save(int fd, char *save)
{
	char	*buff;
	int		file_read;

	file_read = 1;
	buff = malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!buff)
		return (0);
	while (!ft_strchr(save, '\n') && file_read != 0)
	{
		file_read = read(fd, buff, BUFF_SIZE);
		if (file_read == -1)
		{
			free(buff);
			return (0);
		}
		buff[file_read] = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buff);
	return (save);
}

int	get_next_line(const int fd, char **line)
{
	static char	*save[MAX_FD];

	if (fd < 0 || !line || BUFF_SIZE <= 0 || fd >= MAX_FD)
		return (-1);
	save[fd] = read_and_save(fd, save[fd]);
	if (!save[fd])
		return (-1);
	if (ft_strlen(save[fd]) > 0)
	{
		*line = get_line(save[fd]);
		save[fd] = get_save(save[fd]);
		return (1);
	}
	*line = get_line(save[fd]);
	return (0);
}
