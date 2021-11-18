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

int	fill_str(int fd, char **str)
{	
	char *buf;
	char *forfree;
	int	bayts;

	buf = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buf)
		return (-1);
	if(read(fd, buf, 0) < 0)
	{
		free(buf);
		return (-1);
	}
	bayts = 1;
	while (!ft_strchr(*str, '\n') && bayts != 0)
	{
		bayts =	 read(fd, buf, BUFFER_SIZE);
		if(bayts < 0)
		{
			free(buf);
			return (-1);
		}
		forfree = *str;
		buf[bayts] = '\0';
		*str = ft_strjoin(*str, buf);
		free(forfree);
	}
	return (bayts);
}

void fill_line(char *str, char **line)
{
	char *forfree;
	int i;

	i = 0;
	forfree = str;
	if (ft_strchr(str, '\n'))
	{
		while (str[i] != '\n' && str[i])
			i++;
		*line = ft_substr(str, 0, i + 1);
		str = ft_strdup(str + i + 1);
		free(forfree);
	}
	else
	{
		*line = ft_strdup(str);
		free(str);
		str = NULL;
	}
}

char	*get_next_line(int fd)
{
	char	*line;
 	static char	*str;
	int	bayts;
	
	str = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);	
	if (str == NULL)
		str = ft_strdup("");
	if(!str)
		return (NULL);
	bayts = fill_str(fd, &str);
	if(bayts < 0)
	{
		free(str);
		return (NULL);
	}
	fill_line(str, &line);
	if (bayts == 0 && line[0] == '\0')
		return (0);
	return (line);
}
/*
int main()
{
    int        fd;
    char    *line;

    fd = open("klist.txt", O_RDWR);
    if (fd < 0)
        return (printf("ERR"));
	
	while((line = get_next_line(fd)))
	{
    	printf("%s\n", line);
		printf("\n");
	}
    return (0);
}
*/