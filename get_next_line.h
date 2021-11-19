
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#define BUFFER_SIZE 42

size_t	ft_strlen(const char *s);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *left_str, char *buff);
char	*ft_strchr(const char *s, int c);
char   	*get_next_line(int fd);

