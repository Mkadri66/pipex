/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:29:45 by mkadri            #+#    #+#             */
/*   Updated: 2024/05/22 12:01:30 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env_vars)
{
	int		pipe_fd[2];
	pid_t	pid;

	count_args(argc);
	verif_files(argv);
	if (pipe(pipe_fd) == -1)
		exit(-1);
	pid = fork();
	if (pid == -1)
		exit(-1);
	if (pid == 0)
		child_process(argv, pipe_fd, env_vars);
	waitpid(pid, NULL, 0);
	parent_process(argv, pipe_fd, env_vars);
	return (0);
}
