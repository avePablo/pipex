/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalvar <pabalvar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:45:20 by pabalvar          #+#    #+#             */
/*   Updated: 2025/03/26 16:45:26 by pabalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_handler(int n_exit)
{
	if (n_exit == 1)
		ft_putstr_fd("./pipex infile cmd cmd outfile\n", 2);
	exit(EXIT_FAILURE);
}

int	open_file(char *file, int in_or_out)
{
	int	fd;

	if (in_or_out == 0)
		fd = open(file, O_RDONLY);
	else
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		exit_handler(1);
	return (fd);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

char	*my_getenv(char *name, char **env)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(name);
	while (env[i])
	{
		if (!ft_strncmp(env[i], name, len) && env[i][len] == '=')
			return (env[i] + len + 1);
		i++;
	}
	return (NULL);
}

char	*get_path(char *cmd, char **env)
{
	char	**allpath;
	char	*full_path;
	char	*temp;
	int		i;

	allpath = ft_split(my_getenv("PATH", env), ':');
	if (!allpath)
		return (cmd);
	i = -1;
	while (allpath[++i])
	{
		temp = ft_strjoin(allpath[i], "/");
		full_path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(full_path, F_OK | X_OK) == 0)
		{
			ft_free_tab(allpath);
			return (full_path);
		}
		free(full_path);
	}
	ft_free_tab(allpath);
	return (cmd);
}
