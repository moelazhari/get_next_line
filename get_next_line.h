
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

//#define BUFFER_SIZE 42

void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	ft_bzero( void *s, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strdup(char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char   	*get_next_line(int fd);