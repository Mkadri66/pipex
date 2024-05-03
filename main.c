/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:29:45 by mkadri            #+#    #+#             */
/*   Updated: 2024/05/03 21:05:37 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **env_vars)
{
	int pipe_fd[2];
	pid_t pid;

	count_args(argc);
	if(pipe(pipe_fd) == -1)
	{
		perror("Pipe error");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if(pid == -1)
	{
		perror("Fork error");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/* Child process*/
		ft_printf("Child \n");
	}
	else
	{
		/* Parent process*/
		wait(NULL);
		ft_printf("Parent \n");
	}
	(void) argv;
	(void) env_vars;
	return(0);
}
