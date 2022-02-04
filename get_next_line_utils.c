#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (&((char *)s)[i]);
		i++;
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char	*sub;

	if (!s)
		return (0);
	sub = malloc(len + 1);
	i = 0;
	while (s[i + start] && len > i)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = 0;
	return ((char *)sub);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*copy;
	int		i;

	if (!ft_strlen(s))
		return (0);
	copy = malloc(ft_strlen(s) + 1);
	i = 0;
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = 0;
	return (copy);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*s;

	if (!s1 && !s2)
		return (0);
	s = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	while (s1 && s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		s[i + j] = s2[j];
		j++;
	}
	s[i + j] = 0;
	free ((void *)s1);
	return (s);
}
