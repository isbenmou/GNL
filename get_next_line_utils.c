#include "get_next_line.h"

int ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		i++;
return i;
}

char	*ft_strcat(char *dest, const char *src, size_t i)
{
	size_t	j;

	j = 0;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;
	char	*new_str;

	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = malloc(s1_len + s2_len + 1);
	if (new_str == NULL)
		return (NULL);
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	return (ft_strcat(new_str, s2, i));
}

char *ft_strdup(char *str)
{
	int i = 0;
	char *new = malloc(ft_strlen(str) + 1);
    if(new == NULL)
        return NULL;
	while(str[i])
	{
		new[i] = str[i];
	i++;
	}
	new[i] = '\0';
return str;
}
