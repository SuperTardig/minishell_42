/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:29:58 by slord             #+#    #+#             */
/*   Updated: 2023/02/16 08:46:17 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

void	delete_env(t_shell *shell, char *var_name)
{
	int		i;
	char	**temp;
	int		j;

	i = 0;
	j = 0;
	while (shell->env[i])
		i++;
	temp = calloc(sizeof (char *), i + 1);
	i = -1;
	while (shell->env[++i])
		temp[i] = ft_strdup(shell->env[i]);
	free_env(shell);
	shell->env = calloc(sizeof (char *), i + 1);
	i = -1;
	while (temp[++i])
	{
		if (ft_strncmp(var_name, temp[i], ft_strlen(var_name)) == 0)
			i++;
		if (temp[i])
			shell->env[j] = ft_strdup(temp[i]);
		j++;
	}
	free(temp);
}