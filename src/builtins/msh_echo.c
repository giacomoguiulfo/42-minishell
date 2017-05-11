/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 15:58:10 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/05/11 10:27:57 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h> // TODO: Should I use a private?

int		echo_env(char *str, t_dnarr *newenvp)
{
	int i;
	char *ret;

	i = 0;
	while (newenvp->contents[i])
	{
		// ft_printf("ENV: %s\n", newenvp[i]);
		// ft_printf("STR: %s\n", str);
		// ft_printf("STR + 1: %s\n", str + 1);
		// ft_printf("here inside\n");
		if ((ret = ft_strstr(newenvp->contents[i], str + 1)))
		{
			// ft_printf("here megainside\n");
			ft_putstr(ft_strchr(newenvp->contents[i], '=') + 1);
			return (0);
		}
		// ft_printf("RET: %s\n", ret);
		++i;
	}
	// ft_printf("here outside\n");
	return (0);
}

void	echo_octal(char *str, int *i)
{
	int		value;
	char	*ret;
	int		move;

	move = 0;
	if (!*str)
		return ;
	ret = ft_strndup(str, 3);
	move += ISDIGIT(ret[0]); // TODO: Fix this...
	move += ISDIGIT(ret[1]); // TODO: Fix this...
	move += ISDIGIT(ret[2]); // TODO: Fix this...
	// ft_printf("string %s\n", ret);
	value = ft_atoi_base(ret, 8);
	// ft_printf("value %d\n", value);
	free(ret);
	if (value > 255 || value < 0)
		ft_putchar(0);
	else
	{
		ft_putchar(value);
		// ft_printf("aca Value of i: %d\n", *i);
		*i += move;
		// ft_printf("aca Value of i: %d\n", *i);
	}
}

int		echo_putstr(char *str, t_dnarr *newenvp)
{
	int i;

	i = 0;
	(void)newenvp;
	while (str[i])
	{
		if (str[i] == '$')
			return (echo_env(&str[i], newenvp));
		else if (str[i] == '\\' && str[i + 1] == '"')
		{
			write(1, "\"", 1);
		}
		else if (str[i] == '"')
		{
			i++;
			continue ;
		}
		else if (str[i] == '\\' && str[i + 1] == 'b')
			write(1, "\b", 1);
		else if (str[i] == '\\' && str[i + 1] == 'c')
			return (1);
		else if (str[i] == '\\' && str[i + 1] == 'f')
			write(1, "\f", 1);
		else if (str[i] == '\\' && str[i + 1] == 'n')
			write(1, "\n", 1);
		else if (str[i] == '\\' && str[i + 1] == 'r')
			write(1, "\r", 1);
		else if (str[i] == '\\' && str[i + 1] == 't')
			write(1, "\t", 1);
		else if (str[i] == '\\' && str[i + 1] == 'v')
			write(1, "\v", 1);
		else if (str[i] == '\\' && str[i + 1] == '0')
			echo_octal(str + i + 2, &i);
		else if (str[i] == '\\' && str[i + 1] == '\\')
			write(1, "\\", 1);
		else
		{
			write(1, &str[i], 1);
			++i;
			continue ;
		}
		i += 2;
		// ft_printf("Value of i: ss%d\n", i);
	}
	return (0);
}

int		msh_echo(char **args, t_dnarr *newenvp)
{
	int i;
	int put_nl;

	i = 1;
	put_nl = 1;
	// TODO: Handle echo ~ and other paths like ~/Desktop only starting with ~
	if (!args[1])
	{
		if (put_nl)
			ft_putchar('\n');
		return (1);
	}
	if (!ft_strcmp("-n", args[1]))
	{
		++i;
		put_nl = 0;
	}
	if (args[i])
		if (echo_putstr(args[i++], newenvp))
			put_nl = 0;
	while (args[i])
	{
		ft_putchar(' ');
		if (echo_putstr(args[i++], newenvp))
			put_nl = 0;
	}
	if (put_nl)
		ft_putchar('\n');
	else
		ft_printf("%{b_white}%{bblack}%%%{eoc}\n");
	return (1);
}
