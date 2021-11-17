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
		if(bayts <= 0)
		{
			free(buf);
			return (NULL);
		}
		forfree = str;
		buf[bayts] = '\0';
		str = ft_strjoin(str, buf);
		free(forfree);
	}
	i = 0;
	forfree = str;
	if (ft_strchr(str, '\n'))
	{
		while (str[i] != '\n' && str[i])
			i++;
		line = ft_substr(str, 0, i + 1);
		str = ft_strdup(str + i + 1);
		free(forfree);
	}
	else
	{
		line = ft_strdup(str);
		free(str);
		str = NULL;
	}
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
}*/