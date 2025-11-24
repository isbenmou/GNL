#include "get_next_line_bonus.h"

char	*read_file(int fd, char *stash)
{
	char	*buff;
	char	*tmp;
	int		n;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	n = 1;
	while (n > 0)
	{
		n = read(fd, buff, BUFFER_SIZE);
		if (n < 0)
			return (free(buff), NULL);
		buff[n] = '\0';
		tmp = stash;
		stash = ft_strjoin(stash, buff);
		free(tmp);
		if (!stash)
			return (free(buff), NULL);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	return (stash);
}

char	*extract_line(char *stash)
{
	int		i;
	char	*line;

	if (!stash[0])
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*update_stash(char *stash)
{
	int		i;
	int		j;
	char	*new_stash;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	i++;
	new_stash = malloc(ft_strlen(stash) - i + 1);
	if (!new_stash)
		return (NULL);
	j = 0;
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[OPEN_MAX] = {0};
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash[fd])
		stash[fd] = ft_strdup("");
	stash[fd] = read_file(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = extract_line(stash[fd]);
	stash[fd] = update_stash(stash[fd]);
	return (line);
}
