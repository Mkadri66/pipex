/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:31:52 by mkadri            #+#    #+#             */
/*   Updated: 2024/05/11 20:29:11 by mkadri           ###   ########.fr       */
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

int  count_args(int argc);
int verif_files(char **argv);
int   child_process(char **argv, int *fd_array, char **env_vars);
int   parent_process(char **argv, int *fd_array, char **env_vars);

#endif