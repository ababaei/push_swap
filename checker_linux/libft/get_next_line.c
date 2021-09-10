/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababaei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 09:29:04 by ababaei           #+#    #+#             */
/*   Updated: 2021/01/29 16:47:03 by ababaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				get_next_line(int fd, char **line)
{
	static char	*tmp = NULL;
	char		*buf;
	int			ret;
	int			inl;

	ret = 1;
	buf = NULL;
	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	while (!(isincharset(tmp, '\n')) && ret)
	{
		if (!(buf = readline(&ret, buf, fd)) ||
				!(tmp = ft_strjoin(tmp, buf)))
			return (-1);
	}
	if ((inl = fillline(tmp, line, &ret)) == -1)
		return (-1);
	tmp = ft_substr(tmp, inl + 1);
	if (ret == 0)
	{
		free(tmp);
		tmp = NULL;
	}
	free(buf);
	return (ret);
}

char			*readline(int *ret, char *str, int fd)
{
	free(str);
	str = NULL;
	if ((str = malloc(sizeof(char) * (BUFFER_SIZE + 1))) == NULL)
		return (0);
	if ((*ret = read(fd, str, BUFFER_SIZE)) == -1)
	{
		free(str);
		str = NULL;
		return (0);
	}
	str[*ret] = '\0';
	return (str);
}

int				fillline(char *str, char **line, int *ret)
{
	int			count;

	count = 0;
	while (str[count] != '\n' && str[count])
		count++;
	if ((*line = malloc(sizeof(char) * (count + 1))) == NULL)
		return (-1);
	count = 0;
	while (str[count] != '\n' && str[count])
	{
		(*line)[count] = str[count];
		count++;
	}
	(*line)[count] = '\0';
	if (isincharset(str, '\n'))
		*ret = 1;
	return (count);
}
