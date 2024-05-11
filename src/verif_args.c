/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:44:59 by mkadri            #+#    #+#             */
/*   Updated: 2024/05/11 13:08:46 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../pipex.h"

int  count_args(int argc)
{
    if(argc != 5)
    {
        ft_printf("error : must be ./pipex file1 cmd1 cmd2 file2 \n");
        exit(1);
    }
    return (0);
}

int verif_files(char **argv)
{    
    if(access(argv[1], R_OK) == -1 || access(argv[1], F_OK) == -1)
    {
        ft_printf("error : infile not exist or not readable \n");
        exit(1);
    }
    if(access(argv[4], W_OK) == -1 || access(argv[4], F_OK) == -1)
    {
        ft_printf("error : outfile not exist or not writable \n");
        exit(1);
    }
    return(1);
}