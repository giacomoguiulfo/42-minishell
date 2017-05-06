/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 03:49:17 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/05/06 00:03:50 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*msh_read_line(void)
{
	int		c;
	int		bufsize;
	int		position;
	char	*buffer;

	position = 0;
	bufsize = MSH_RL_SIZ;
	buffer = (char *)malloc(sizeof(char) * bufsize);
	while (1)
	{
		c = ft_getchar();
		if (c == EOF || c == '\n')
		{
			buffer[position] = '\0';
			return (buffer);
		}
		else
			buffer[position] = c;
		position++;
		if (position >= bufsize)
		{
			buffer = ft_realloc(buffer, bufsize, bufsize + MSH_RL_SIZ);
			bufsize += MSH_RL_SIZ;
		}
	}
}

void	msh_loop(void)
{
	int		status;
	char	*line;
	char	**args;

	status = 1;
	while (status)
	{
		msh_put_arrow();
		line = msh_read_line();
		args = ft_strsplit(line, ' ');
		status = msh_execute(args);
		free(line);
		ft_free_map(args);
	}
}

int		main(void)
{
	msh_loop();
	return (0);
}
