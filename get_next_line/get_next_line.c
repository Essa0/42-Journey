#include "get_next_line.h"

static char	*extract_line(char *buffer)
{
	int		i;
	int		j;
	char	*newstr;

	i = 0;
	j = 0;
	if (!buffer || !buffer[0])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i += 1;
	newstr = malloc(i + 1);
	if (!newstr)
		return (NULL);
	while (j < i)
	{
		newstr[j] = buffer[j];
		j++;
	}
	newstr[j] = '\0';
	return (newstr);
}

static char	*update_leftover(char *leftover)
{
	char	*str;
	char	*newlf;

	if (!leftover)
		return (NULL);
	newlf = ft_strchr(leftover, '\n');
	if (!newlf)
	{
		free(leftover);
		return (NULL);
	}
	str = ft_strdup(newlf + 1);
	free(leftover);
	if (!str || str[0] == '\0')
	{
		free(str);
		return (NULL);
	}
	return (str);
}

static char	*join_buffer(char *leftover, char *buffer)
{
	char	*join;

	if (leftover)
	{
		join = ft_strjoin(leftover, buffer);
		free(leftover);
		return (join);
	}
	else
		return (ft_strdup(buffer));
}

static char	*read_file(int fd, char *leftover)
{
	char	*buffer;
	int		n;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (leftover);
	n = 1;
	while (n > 0)
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n < 0)
		{
			free(buffer);
			free(leftover);
			return (NULL);
		}
		if (n == 0)
			break ;
		buffer[n] = '\0';
		leftover = join_buffer(leftover, buffer);
		if (ft_strchr(leftover, '\n'))
			break ;
	}
	free(buffer);
	return (leftover);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	leftover = read_file(fd, leftover);
	if (!leftover)
		return (NULL);
	line = extract_line(leftover);
	leftover = update_leftover(leftover);
	return (line);
}