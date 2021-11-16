#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*c_dst;
	unsigned char	*c_src;

	c_dst = (unsigned char *)dst;
	c_src = (unsigned char *)src;
	if (!c_dst && !c_src)
		return (NULL);
	while (n--)
		*c_dst++ = *c_src++;
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*cpy_dst;
	unsigned char	*cpy_src;

	cpy_dst = (unsigned char *)dst;
	cpy_src = (unsigned char *)src;
	if (!cpy_dst && !cpy_src)
		return (NULL);
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
	{
		while (len-- > 0)
			cpy_dst[len] = cpy_src[len];
	}
	return (dst);
}

void	ft_bzero( void *s, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n--)
		*str++ = '\0';
}

char	*ft_strdup(char *s)

{
	char	*dest;
	int		i;

	dest = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}


char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != (char)c)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (!s1)
		return (NULL);
	if (!s2)
		return (ft_strdup((char *)s1));
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	ft_memmove(str, s1, ft_strlen(s1));
	ft_memmove(str + ft_strlen(s1), s2, ft_strlen(s2));
	ft_bzero(str + ft_strlen(s1) + ft_strlen(s2), 1);
	return (str);
}
