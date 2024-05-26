/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 06:49:55 by mkadri            #+#    #+#             */
/*   Updated: 2024/05/26 20:13:29 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	execute_cmd(char *commands, char **env_vars)
{
	char	**commands_tab;
	char	*path;

	commands_tab = ft_split(commands, ' ');
	path = get_command_path(commands_tab[0], env_vars);
    if(!path)
    {
        perror("Command not found");
        free_array(commands_tab);
        exit(0);
    }
	if (execve(path, commands_tab, env_vars) == -1)
	{
		perror("Command not found");
        free_array(commands_tab);
		exit(0);
	}
	
}

int	child_process(char **argv, int *fd_array, char **env_vars)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (0);
	dup2(fd, STDIN_FILENO);
	dup2(fd_array[1], STDOUT_FILENO);
	close(fd_array[0]);
	execute_cmd(argv[2], env_vars);
	return (0);
}

int	parent_process(char **argv, int *fd_array, char **env_vars)
{
	int	fd;

	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (0);
	dup2(fd_array[0], STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	close(fd_array[1]);
	execute_cmd(argv[3], env_vars);
	return (0);
}
