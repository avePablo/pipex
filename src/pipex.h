#ifndef PIPEX_H
# define PIPEX_H

# include "../Libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

void	exit_handler(int n_exit);

int		open_file(char *file, int in_or_out);

void	ft_free_tab(char **tab);

char	*my_getenv(char *name, char **env);

char	*get_path(char *cmd, char **env);

void	exec(char *cmd, char **env);

void	child(char **av, int *p_fd, char **env);

void	parent(char **av, int *p_fd, char **env);

#endif
