/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 12:52:53 by hkhalil           #+#    #+#             */
/*   Updated: 2021/11/23 13:19:13 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*sub;

	if (!s)
		return (0);
	if (ft_strlen(s) <= start || !len)
		sub = malloc(1);
    else if (ft_strlen(s) <= len + start)
		sub = malloc(ft_strlen(s) - start + 1);
    else
    	sub = malloc(len + 1);
	if (!sub)
		return (0);
	i = 0;
	if (ft_strlen(s) > start)
	{
		while (s[i + start] && len > 0)
		{
			sub[i] = s[start + i];
			i++;
			len--;
		}
	}
	sub[i] = 0;

   // free((char *)s);
	return (sub);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*s;

	if (!s1 && !s2)
		return (0);
	s = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s)
		return (0);
	i = 0;
    if (s1)
    {
	    while (s1[i])
	    {
		    s[i] = s1[i];
		    i++;
	    }
    }
	j = 0;
    if (s2)
    {
	    while (s2[j])
	    {
	    	s[i + j] = s2[j];
	    	j++;
	    }
    }
	s[i + j] = 0;
    free((char *)s1);
    free((char *)s2);
	return (s);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest || !src)
		return (0);
	if (dest == src)
		return (dest);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
