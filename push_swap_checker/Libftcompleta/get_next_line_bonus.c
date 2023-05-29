/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:08:12 by lbaroni           #+#    #+#             */
/*   Updated: 2022/11/29 15:08:14 by lbaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_read(int fd, int *i)
{
	char	*buff;
	int		a;

	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	a = read(fd, buff, BUFFER_SIZE);
	if (a < 0 || fd < 0 || fd > 1024)
	{
		free (buff);
		return (NULL);
	}
	buff[a] = '\0';
	*i = a;
	return (buff);
}

char	*ft_after_nl(char *statico)
{
	char	*res;
	int		i;
	int		b;

	i = 0;
	b = 0;
	while (statico[i] && statico[i] != '\n')
		i++;
	if (statico[i] == '\n')
		i++;
	res = (char *)malloc(sizeof(char) * (ft_strlen(statico) - i) + 1);
	while (statico[i])
	{
		res[b] = statico[i];
		i++;
		b++;
	}
	res[b] = '\0';
	free(statico);
	return (res);
}

char	*ft_line_towrite(char *statico)
{
	char	*res;
	int		i;

	i = 0;
	while (statico[i] && statico[i] != '\n')
		i++;
	if (statico[i] == '\n')
		res = (char *)malloc(sizeof(char) * i + 2);
	else
		res = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	while (statico[i] && statico[i] != '\n')
	{
		res[i] = statico[i];
		i++;
	}
	if (statico[i] == '\n')
	{
		res[i] = '\n';
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	ft_find_end(char *fd)
{
	int	i;

	i = 0;
	while (fd[i] != '\n' && fd[i])
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*statico[1024];
	char		*buff;
	int			reading;

	reading = 1;
	if (fd == -42)
		return (ft_libero(statico));
	while (reading > 0)
	{
		buff = ft_read(fd, &reading);
		statico[fd] = ft_struni(statico[fd], buff);
		if (statico[fd] == NULL || statico[fd][0] == '\0')
			return (ft_freenreturn(statico[fd]));
		if (statico[fd][ft_find_end(statico[fd])] == '\n' || reading == 0)
		{
			buff = ft_line_towrite(statico[fd]);
			statico[fd] = ft_after_nl(statico[fd]);
			return (buff);
		}
	}
	free(statico[fd]);
	return (NULL);
}
