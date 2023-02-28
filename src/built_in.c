/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 23:13:30 by slord             #+#    #+#             */
/*   Updated: 2023/02/28 14:57:38 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

int	export(t_shell *shell, char **cmds)
{
	if (cmds[1] == NULL)
	{
		env(shell);
		return (0);
	}	
	if (ft_strchr(cmds[1], '=') != 0 && ft_isdigit(cmds[1][0]) == 0
		&& cmds[2] == NULL)
		add_env(shell, cmds[1]);
	else
	{
		shell->status = 1;
		dprintf(2, "MiniHell: bad argument for export\n");
		return (1);
	}
	return (0);
}

int	unset(t_shell *shell, char *cmds)
{
	char	*var_name;

	var_name = ft_strjoin(cmds, "=");
	delete_env(shell, var_name);
	free(var_name);
	return (0);
}

char	*get_pwd(char **env)
{
	char	*pwd;
	int		j;

	j = 0;
	while (ft_strncmp(env[j], "PWD=", 4))
		j++;
	pwd = env[j] + 4;
	return (pwd);
}

int	cd_built_in(t_shell *shell, char *path)
{
	char	*current_path;
	char	*old_path;
	char	buff[1024];

	old_path = getcwd(buff, 1024);
	if (chdir(path) != 0)
	{
		dprintf(2, "MiniHell: Bad argument for cd\n");
		shell->status = 1;
		return (1);
	}
	old_path = ft_strjoin("OLDPWD=", old_path);
	current_path = getcwd(buff, 1024);
	current_path = ft_strjoin("PWD=", current_path);
	add_env(shell, old_path);
	free(current_path);
	free(old_path);
	return (0);
}
