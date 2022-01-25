/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jturunen <jturunen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:44:04 by jturunen          #+#    #+#             */
/*   Updated: 2022/01/25 16:34:07 by jturunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static char *get_line(char *save)
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

static char *get_save(char *save)
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
 
int	get_next_line(const int fd, char **line)
{
	static char	*save[257];
	char		*buff;
	int			reading;

	reading = 1;
	if (fd < 0 || !line || BUFF_SIZE <= 0 || fd > 256)
		return (-1);
	buff = malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!buff)
		return (-1);
	while (!ft_strchr(save[fd], '\n') && reading != 0)
	{
		reading = read(fd, buff, BUFF_SIZE);
		if (reading == -1)
		{
			free(buff);
			return (-1);
		}
		buff[reading] = '\0';
		save[fd] = ft_strjoin(save[fd], buff);
	}
	free(buff);
	if (ft_strlen(save[fd]) > 0)
	{
		*line = get_line(save[fd]);
		save[fd] = get_save(save[fd]);
		return (1);
	}
	*line = get_line(save[fd]);
	return (0);
}
