/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:40:35 by oseitama          #+#    #+#             */
/*   Updated: 2022/04/09 18:35:35 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*	Helper function that reads the line and combines whats whats already	*/
/*	read and whats currently being read into str.							*/

char	*ft_read_line(int fd, char *str)
{
	int		bytes_read;
	char	buff[BUFF_SIZE + 1];

	bytes_read = read(fd, buff, BUFF_SIZE);
	while (bytes_read > 0)
	{
		buff[bytes_read] = '\0';
		str = ft_strjoin(str, buff);	// fix memory leak here.
		if (ft_strchr(buff, '\n'))
			break ;
		bytes_read = read(fd, buff, BUFF_SIZE);
	}
	return (str);
}

/*	Helper function that goes through str until either \n or \0 is found.	*/
/*	Saving up to either in line and freeing the memory in str.				*/

void	ft_save_line(char **str, char **line)
{
	size_t	len;
	char	*tmp;

	len = 0;
	tmp = NULL;
	while ((*str)[len] != '\n' && (*str)[len] != '\0')
		len++;
	if ((*str)[len] == '\n')
	{
		*line = ft_strsub(*str, 0, len);
		tmp = ft_strdup(&(*str)[len + 1]);
		free(*str);
		*str = tmp;
	}
	else if ((*str)[len] == '\0')
	{
		*line = ft_strdup(*str);
		ft_memdel((void **)str);
	}
}

/*	Main function.  Calls ft_read_line to read the buffer and then		*/
/*	ft_save_line to save the buffer to line.  Returns 1 if no errors	*/
/*	otherwise 0 or -1.													*/

int	get_next_line(const int fd, char **line)
{
	static char	*str[MAX_FD];

	if (fd < 0 || line == NULL || read(fd, 0, 0) == -1 || fd > MAX_FD)
		return (-1);
	if (!str[fd])
		str[fd] = ft_strnew(0);
	str[fd] = ft_read_line(fd, str[fd]);
	if (!str[fd])
		return (-1);
	ft_save_line(&str[fd], line);
	if (!str[fd] && **line == '\0')
	{
		free(*line);
		*line = NULL;
		return (0);
	}
	return (1);
}
