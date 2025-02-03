/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:30:07 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/03 17:33:10 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	clean_data(t_data **data)
{
	if (!*data)
		return ;
	if ((*data)->map)
		free_array((*data)->map);
	free((*data)->north_texture);
	free((*data)->south_texture);
	free((*data)->west_texture);
	free((*data)->east_texture);
	free(*data);
}

void	clean_all_exit(t_data **data, t_list **list, char *msg)
{
	if (*list)
		ft_lst_clear(list);
	if (data)
		clean_data(data);
	print_error(msg);
}
