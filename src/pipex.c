/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfuto <kfuto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:45:01 by pabalvar          #+#    #+#             */
/*   Updated: 2025/09/15 13:35:30 by kfuto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec(char *cmd, char **env)
{
	char	**s_cmd;
	char	*path;

	s_cmd = ft_split(cmd, ' ');
	if (!s_cmd)
		exit_handler(1);
	path = get_path(s_cmd[0], env);
	if (execve(path, s_cmd, env) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(s_cmd[0], 2);
		ft_free_tab(s_cmd);
		exit(127);
	}
}

void	child(char **av, int *p_fd, char **env)
{
	int	fd;

	fd = open_file(av[1], 0);
	dup2(fd, STDIN_FILENO);
	dup2(p_fd[1], STDOUT_FILENO);
	close(fd);
	close(p_fd[0]);
	close(p_fd[1]);
	exec(av[2], env);
}

void	parent(char **av, int *p_fd, char **env)
{
	int	fd;

	fd = open_file(av[4], 1);
	dup2(fd, STDOUT_FILENO);
	dup2(p_fd[0], STDIN_FILENO);
	close(fd);
	close(p_fd[0]);
	close(p_fd[1]);
	exec(av[3], env);
}

int	main(int ac, char **av, char **env)
{
	int		p_fd[2];
	int		status[2];
	pid_t	pid;
	pid_t	pid2;

	if (ac != 5)
		exit_handler(1);
	if (pipe(p_fd) == -1)
		exit_handler(1);
	pid = fork();
	if (pid == -1)
		exit_handler(1);
	if (pid == 0)
		child(av, p_fd, env);
	pid2 = fork();
	if (pid2 == -1)
		exit_handler(1);
	if (pid2 == 0)
		parent(av, p_fd, env);
	close(p_fd[0]);
	close(p_fd[1]);
	waitpid(pid, &status[0], 0);
	waitpid(pid2, &status[1], 0);
	return (0);
}
