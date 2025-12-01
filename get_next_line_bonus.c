#include "get_next_line_bonus.h"

static char *create_line(char *s)
{
    char *newline = ft_strchr(s, '\n');
    char *line;
    size_t len_line;

    if (!newline)
        return ft_strdup(s);

    len_line = (newline - s) + 1;
    line = malloc(len_line + 1);
    if (!line)
        return NULL;

    ft_memcpy(line, s, len_line);
    line[len_line] = '\0';
    return line;
}

static char *update_storage(char *s)
{
    char *newline = ft_strchr(s, '\n');
    char *rest;

    if (!newline)
    {
        free(s);
        return NULL;
    }

    rest = ft_strdup(newline + 1);
    free(s);
    return (*rest) ? rest : (free(rest), NULL);
}

static char *extract_line(char **storage)
{
    char *s = *storage;
    char *line;

    if (!s || !*s)
        return NULL;

    line = create_line(s);
    *storage = update_storage(s);
    return line;
}

char *get_next_line(int fd)
{
    static char *storage[1024];
    char *buf;
    ssize_t rd;

    if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
        return NULL;

    buf = malloc(BUFFER_SIZE + 1);
    if (!buf)
        return NULL;

    while (!ft_strchr(storage[fd], '\n'))
    {
        rd = read(fd, buf, BUFFER_SIZE);
        if (rd <= 0)
            break;
        buf[rd] = '\0';
        storage[fd] = ft_strjoin(storage[fd], buf);
        if (!storage[fd])
            break;
    }
    free(buf);
    return extract_line(&storage[fd]);
}
