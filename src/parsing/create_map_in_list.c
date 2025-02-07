/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_in_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:07:45 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/07 11:12:47 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	create_map_in_list(int fd, t_list **list)
{
	char	*line;
	t_list	*current_node;
	int		gnl_return_value;

	line = NULL;
	current_node = NULL;
	gnl_return_value = get_next_line(fd, &line);
	while (gnl_return_value > 0)
	{
		current_node = ft_lstnew(line);
		if (!current_node)
			clean_list_gnl(list, line);
		*list = ft_lstadd_back(list, current_node);
		gnl_return_value = get_next_line(fd, &line);
	}
	if (gnl_return_value == 0)
	{
		if (line[0] != '\0')
			*list = ft_lstadd_back(list, current_node);
		free(line);
	}
	else
		clean_list_gnl(list, line);
}

int	set_line_type(char *str)
{
	int	type;

	while (*str == ' ' || *str == '\t' )
		str++;
	if (*str == '\0')
		type = EMPTY_LINE;
	else if (is_direction_char(*str))
		type = TEXTURE_LINE;
	else if (is_color_char(*str))
		type = COLOR_LINE;
	else if (*str == '0' || *str == '1' || *str == ' ')
		type = MAP_LINE;
	else
		type = ERROR_LINE;
	return (type);
}

int	is_direction_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

int	is_color_char(char c)
{
	return (c == 'F' || c == 'C');
}

void	clean_list_gnl(t_list **list, char *line)
{
	ft_lst_clear(list);
	free(line);
	print_error("GNL failed\n");
}
