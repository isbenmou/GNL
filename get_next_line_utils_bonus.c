#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	int		len = 0;
	char	*dup;

	while (s[len])
		len++;
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	for (int i = 0; i < len; i++)
		dup[i] = s[i];
	dup[len] = '\0';
	return (dup);
}

size_t	ft_strlen(const char *s)
{
	size_t	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1 = ft_strlen(s1);
	size_t	len2 = ft_strlen(s2);
	char	*new;
	size_t	i = 0;
	size_t	j = 0;

	new = malloc(len1 + len2 + 1);
	if (!new)
		return (NULL);
	while (i < len1)
	{
		new[i] = s1[i];
		i++;
	}
	while (j < len2)
	{
		new[i + j] = s2[j];
		j++;
	}
	new[i + j] = '\0';
	return (new);
}
