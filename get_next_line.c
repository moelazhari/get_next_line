/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:57:13 by mazhari           #+#    #+#             */
/*   Updated: 2021/11/19 01:00:18 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char *fill_str(int fd, char *str)
{
	char *buf;
	int bayts;
	
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	bayts = 1;
	while (!ft_strchr(str, '\n') && bayts != 0)
	{
		bayts = read(fd, buf, BUFFER_SIZE);
		if (bayts == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[bayts] = '\0';
		str = ft_strjoin(str, buf);
	}
	free(buf);
	return (str);
}

char *fill_line(char *str)
{
	char *line;
	int i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
	if(!line)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char *fill_new_str(char *str)
{
	int i;
	int j;
	char *new_str;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!new_str)
		return (NULL);
	i++;
	j = 0;
	while (str[i] != '\n' && str[i])
		new_str[j++] = str[i++];
	new_str[j] = '\0';
	free(str);
	return (new_str);
}
char *get_next_line(int fd)
{
	char *line;
	static char *str;
	
	str = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if(!str)
		str = ft_strdup("");
	str = fill_str(fd, str);
	if (!str)
		return (NULL);
	line = fill_line(str);
	str = fill_new_str(str);
	return (line);
}

int main()
{
	int fd;
	char *line;

	fd = open("klist.txt", O_RDWR);
	if (fd < 0)
		return (printf("ERR"));
	while (line = get_next_line(fd))
		printf("%s", line);
	return (0);
}
