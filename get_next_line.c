#include "get_next_line.h"
#include <stdio.h>

char *str_update(char *str)
{
	int i = 0;
	while(str[i] && str[i] != '\n')
		i++;
	char *tmp = ft_strdup(str + i + 1);
	free(str);
	return tmp;
}

char *get_line(char *str)
{
	int i = 0;
	int j = 0;
	while(str[j] && str[j] != '\n')
		j++;
	if(str[j] == '\n')
		j++;
	char *new = malloc(j + 1);
	if(new == NULL)
		return NULL;
	while(i < j)
	{
		new[i] = str[i];
	i++;
	}
	if(str[i] == '\n')
		new[i++] = '\n'; 
	new[i] = '\0';
return new;
}

int check(char *str, char c)
{
	int i = 0;
	while(str[i])
	{
		if(str[i] == c)
			return 1;
	i++;
	}
return 0;
}

char *read_file(int fd, char **str)
{
	char *buff;
	char *tmp;
	int n = 0;
	buff = malloc(BUFFER_SIZE+1);
	if(buff == NULL)
		return NULL;
	buff[0] = '\0';
	n = read(fd, buff, BUFFER_SIZE);
	tmp = *str;
	while(n > 0)
	{
		buff[n] = '\0';
		*str = ft_strjoin(*str, buff);
		if(check(buff, '\n') == 1)
			break;
		n = read(fd, buff, BUFFER_SIZE);
	}
	if(n <= 0 && str[0][0] == '\0')
	{
		free(buff);
		return NULL;
	}
	free(tmp);
	free(buff);
return *str;
}

char *get_next_line(int fd)
{
	char *tmp;
	static char *str = NULL;
	if(fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	if(str == NULL)
		str = ft_strdup("");
	str = read_file(fd, &str);
	if(str == NULL)
		return NULL;
	tmp = get_line(str);
	str = str_update(str);
return tmp;
}
	
