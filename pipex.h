/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:31:52 by mkadri            #+#    #+#             */
/*   Updated: 2024/05/13 17:56:53 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX
# define PIPEX


# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
#include <sys/wait.h>

typedef struct s_pipex {
    int arg_files[2];
}   t_pipex;

int  count_args(int argc);
int     verif_files(char **argv, t_pipex *pipex);
int   child_process(char **argv, int *fd_array, char **env_vars);
int   parent_process(char **argv, int *fd_array, char **env_vars);

#endif