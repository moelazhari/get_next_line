/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:57:13 by mazhari           #+#    #+#             */
/*   Updated: 2021/11/16 16:44:50 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

char	*get_next_line(int fd)
{
	size_t	bayts;
	char	*line;
	char	*buf;
 	static char	*str;
	char	*forfree;
	int		i;
	
	str = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buf)
		return (NULL);
	if(read(fd, buf, 0) < 0)
	{
		free(buf);
		return (NULL);
	}
	if (str == NULL)
		str = ft_strdup("");
	if(!str)
	{
		free(str);
		return (NULL);
	}
	bayts = 1;
	while (!ft_strchr(str, '\n') && bayts != 0)
	{
		bayts =	 read(fd, buf, BUFFER_SIZE);
		if(bayts < 0)
		{
			free(buf);
			return (NULL);
		}
		forfree = str;
		buf[bayts] = '\0';
		str = ft_strjoin(str, buf);
		free(forfree);
	}
	if(bayts == 0 || !str)
	{	
		free(str);
		return (NULL);
	}
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	line = (char *)malloc(i + 2 * sizeof(char));
	if(!line)
		return (NULL);
	i = 0;	
	while (str[i] != '\n' && str[i])
	{
		line[i] = str[i]; 
		i++;
	}
	if (line[i] == '\n')
		i++;
	line[i] = '\0';
	return (line);
}