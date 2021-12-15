/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 12:41:13 by mazhari           #+#    #+#             */
/*   Updated: 2021/11/20 12:41:23 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*fill_line(char **str, char *line)
{
	char	*forfree;
	int		i;

	i = 0;
	forfree = *str;
	while ((*str)[i] != '\n' && (*str)[i] != '\0')
		i++;
	if (ft_strchr(*str, '\n'))
	{
		line = ft_substr(*str, 0, i + 1);
		*str = ft_strdup(*str + i + 1);
	}
	else
	{
		line = ft_strdup(*str);
		*str = NULL;
	}
	free(forfree);
	return (line);
}

int	fill_str(int fd, char **str)
{	
	char	*buf;
	char	*forfree;
	int		bayts;

	buf = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buf)
		return (-1);
	if (read(fd, buf, 0) < 0)
	{
		free(buf);
		return (-1);
	}
	bayts = 1;
	while (!ft_strchr(*str, '\n') && bayts)
	{
		bayts = read(fd, buf, BUFFER_SIZE);
		buf[bayts] = '\0';
		forfree = *str;
		*str = ft_strjoin(*str, buf);
		free(forfree);
	}
	free(buf);
	return (bayts);
}

char	*get_next_line(int fd)
{
	static char	*str[1024];
	char		*line;
	int			bayts;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	if (!str[fd])
		str[fd] = ft_strdup("");
	bayts = fill_str(fd, &str[fd]);
	line = fill_line(&str[fd], line);
	if (bayts <= 0 && !line[0])
	{
		free (line);
		return (NULL);
	}
	return (line);
}
