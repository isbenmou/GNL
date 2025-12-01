#include "get_next_line_bonus.h"

size_t  ft_strlen(const char *s)
{
    size_t i = 0;
    if (!s)
        return 0;
    while (s[i])
        i++;
    return i;
}

void    *ft_memcpy(void *dst, const void *src, size_t n)
{
    size_t i;

    if (!dst && !src)
        return NULL;
    i = 0;
    while (i < n)
    {
        ((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
        i++;
    }
    return dst;
}

char    *ft_strdup(const char *s)
{
    size_t len = ft_strlen(s);
    char   *dup = malloc(len + 1);

    if (!dup)
        return NULL;
    ft_memcpy(dup, s, len);
    dup[len] = '\0';
    return dup;
}

char    *ft_strchr(const char *s, int c)
{
    if (!s)
        return NULL;
    while (*s)
    {
        if (*s == (char)c)
            return ((char *)s);
        s++;
    }
    if (c == '\0')
        return ((char *)s);
    return NULL;
}

char    *ft_strjoin(char *s1, char *s2)
{
    char    *res;
    size_t  len1 = s1 ? ft_strlen(s1) : 0;
    size_t  len2 = ft_strlen(s2);

    res = malloc(len1 + len2 + 1);
    if (!res)
        return NULL;
    if (s1)
    {
        ft_memcpy(res, s1, len1);
        free(s1);
    }
    ft_memcpy(res + len1, s2, len2);
    res[len1 + len2] = '\0';
    return res;
}
