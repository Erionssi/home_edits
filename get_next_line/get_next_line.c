/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jturunen <jturunen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:44:04 by jturunen          #+#    #+#             */
/*   Updated: 2022/01/22 13:26:07 by jturunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static char	*test_strjoin(char *s1, char *s2)
{
	char	*fresh;
	size_t	len_sum;
	size_t	i;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	len_sum = (ft_strlen(s1) + ft_strlen(s2));
	fresh = ft_strnew(len_sum);
	if (!fresh)
		return (NULL);
	i = 0;
	while (*s1 != '\0')
		fresh[i++] = *s1++;
	while (*s2 != '\0')
		fresh[i++] = *s2++;
	fresh[i] = '\0';
	return(fresh);
}

static int	nl_in_line(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
//	return (i);
	return (0);
}

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
 
//static char	*read_n_save(int fd, char *save)
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
	while (!nl_in_line(save[fd]) && reading != 0)
	{
		reading = read(fd, buff, BUFF_SIZE);
		if (reading == -1)
		{
			free(buff);
			return (-1);
		}
		buff[reading] = '\0';
		save[fd] = test_strjoin(save[fd], buff);
	}
	free(buff);
	if (ft_strlen(save[fd]) > 0)
	{
		*line = get_line(save[fd]);
		save[fd] = get_save(save[fd]);
		return (1);
	}
	return (0);
//	*line = get_line(save[fd]);
//	save[fd] = get_save(save[fd]);
//	if (reading == 0)
//	{
//		if (!save[fd] && (*line))
//			return (1);
//		return (0);
//	}
//	if (reading == 0 && !save[fd])
//		return (0);
//	return (1);
}

/* woops
function that returns a line read from a file descriptor
line is a succession of characters that end with '\n' (ascii 0x0a) or with EOF

must be prototyped as:
int	get_next_line(const int fd, char **line);

first parameter is the filedescriptor that will be used to read
second parameter is the address of a pointer to a character that will be used
to save the line read from the FD

return value can be 1, 0 or -1, has been read, when the reading has been
completed, or if error occured respectively

function has to return its result WITHOUT '\n'!!!

calling your function in a loop will then allow you to read the text available
on a FD one line at a time until end of the text, no matter the size of either
the text or one of its lines.

make sure that your function behaves well when it reads from a file,
standard output, redirection etc.

in header file you must have at least the prototype of the function,
macro that allows to choose the size of the reading buffer for the read funct.
This value will be modded during defence, IT MUST BE NAMED as BUFF_SIZE
For example: #define BUFF_SIZE 32

make sure to test it with different buff_size:s like 9999, 1, 1000000 etc

we consider that get_next_line function has undefined behaviour if,
between two calls, the same FD designs two distinct files although the reading
from the first file was not completed.

we consider also taht a call to lseek(2) will never take place between two calls
 of the function on the same FD

Finally we consider that get_next_line has an undefined behaviour when reading 
from a binary file. However you can make this behaviour coherent.

Global variables are forbidden.

Static variables are allowed.

BONUS

Get it working with single static variable

To be able to manage multiple file descriptor with your get_next_line
for example, if the FD 3, 4, and 5 are accessible for reading, then you can call
get_next_line once on 3,once on 4, once again on 3 then once on 5 etc.
without losing the readin thread on each of the FD.
*/