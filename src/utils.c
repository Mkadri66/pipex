/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 08:09:40 by mkadri            #+#    #+#             */
/*   Updated: 2024/05/22 12:12:49 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	*get_command_path(char *command, char **env_vars)
{
	int		i;
	char	*path_exe;
	char	**exe_paths;
	char	*part_path;

	i = 0;
	while (ft_strnstr(env_vars[i], "PATH", 4) == 0)
		i++;
	exe_paths = ft_split(env_vars[i] + 5, ':');
	i = 0;
	while (exe_paths[i])
	{
		part_path = ft_strjoin(exe_paths[i], "/");
		path_exe = ft_strjoin(part_path, command);
		free(part_path);
		if (access(path_exe, X_OK) == 0)
			return (path_exe);
		free(path_exe);
		i++;
	}
	i--;
	free_array(exe_paths);
	return (0);
}
