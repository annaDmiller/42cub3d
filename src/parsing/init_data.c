/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:42:41 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/03 13:39:03 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	initialize_data(t_data **data, t_list **list)
{
	init_data(data, list);
	fill_texture(data, list, &(*data)->north_texture, "NO ");
	fill_texture(data, list, &(*data)->south_texture, "SO ");
	fill_texture(data, list, &(*data)->west_texture, "WE ");
	fill_texture(data, list, &(*data)->east_texture, "EA ");
	if (!(*data)->north_texture || !(*data)->south_texture ||
		!(*data)->west_texture || !(*data)->east_texture)
	{
		clean_all_exit(data, list, "Error: One or more textures missing\n");
	}
	fill_colors(data, list, &(*data)->floor_hex, (*data)->floor_rgb, "F ");
	fill_colors(data, list, &(*data)->ceiling_hex, (*data)->ceiling_rgb, "C ");
	get_map_size(data, list);
	init_empty_map(data, list);
	fill_map(data, list);
	get_player_position(data);
}

// Initializes the t_data structure
void	init_data(t_data **data, t_list **list)
{
	*data = (t_data *)malloc(sizeof(t_data) * 1);
	if (!*data)
		clean_all_exit(data, list, "Data initialization failed\n");
	(*data)->map = NULL;
	(*data)->map_height = 0;
	(*data)->map_width = 0;
	(*data)->floor_hex = 0;
	(*data)->ceiling_hex = 0;
	(*data)->floor_rgb[0] = 0;
	(*data)->floor_rgb[1] = 0;
	(*data)->floor_rgb[2] = 0;
	(*data)->ceiling_rgb[0] = 0;
	(*data)->ceiling_rgb[1] = 0;
	(*data)->ceiling_rgb[2] = 0;
	(*data)->north_texture = NULL;
	(*data)->south_texture = NULL;
	(*data)->west_texture = NULL;
	(*data)->east_texture = NULL;
	(*data)->player_x = 0;
	(*data)->player_y = 0;
	(*data)->player_direction = '\0';
	(*data)->player_direction_radian = 0.0;
}


char	*remove_spaces_and_tabs(char *str)
{
    char	*result;
    int		i;
    int		j;

    if (!str)
        return (NULL);

    result = (char *)malloc(strlen(str) + 1);
    if (!result)
        return (NULL);

    i = 0;
    j = 0;
    while (str[i])
    {
        if (str[i] != ' ' && str[i] != '\t')
        {
            result[j] = str[i];
            j++;
        }
        i++;
    }
    result[j] = '\0';
    return (result);
}



// Finds a matching line, extracts the texture path (after removing the prefix) and assigns it to *dest

/* void	fill_texture(t_data **data, t_list **list, char **dest, char *src)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp)
	{

		*dest = trimmed_string(tmp->line, src);
		if (ft_strncmp(tmp->line, src, 3) == 0)
		{
			
			if (!*dest)
			{
				clean_all_exit(data, list, "Texture data init failed\n");
				return;
			}
			if (!*dest && (ft_strcmp(src, "NO ") == 0))
				clean_all_exit(data, list, "North texture data init failed\n");
			else if (!*dest && (ft_strcmp(src, "SO ") == 0))
				clean_all_exit(data, list, "South texture data init failed\n");
			else if (!*dest && (ft_strcmp(src, "WE ") == 0))
				clean_all_exit(data, list, "West texture data init failed\n");
			else if (!*dest && (ft_strcmp(src, "EA ") == 0))
				clean_all_exit(data, list, "East texture data init failed\n");
		}
		tmp = tmp->next;
	}
} */

void	fill_texture(t_data **data, t_list **list, char **dest, char *src)
{
	t_list	*tmp;
	char	*trimmed;

	tmp = *list;
	while (tmp)
	{
		// Trim leading/trailing spaces from the current line
		trimmed = ft_strtrim(tmp->line, " \t");
		if (!trimmed)
			clean_all_exit(data, list, "Memory allocation failed\n");

		// Check if the line starts with the correct texture identifier
		if (ft_strncmp(trimmed, src, 3) == 0)
		{
			*dest = trimmed_string(trimmed, src);
			free(trimmed);

			if (!*dest)
				clean_all_exit(data, list, "Texture data init failed\n");

			return;  // Exit once a valid texture is found
		}

		free(trimmed);
		tmp = tmp->next;
	}

	// If no texture was found, print the specific error
	clean_all_exit(data, list, "Error: One or more textures missing\n");
}


// Removes any characters found in the set string from both the beginning and the end of the str string. 
// Return (newly allocated string with the unwanted characters removed)

/* char	*trimmed_string(char *str, char *set)
{
	int		len;
	char	*substr;

	len = 0;
	substr = NULL;
	if (!str || !set)
		return (NULL);
	str += 3;
	while (*str == ' ')
		str++;
	
	len = ft_strlen(str);
	while (len > 0 && str[len - 1] == ' ')
		len--;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	substr[len] = '\0';
	while (len--)
		substr[len] = str[len];
	return (substr);
} */

char	*trimmed_string(char *str, char *prefix)
{
	int		len;
	char	*substr;

	if (!str || !prefix)
		return (NULL);

	str += ft_strlen(prefix); 
	while (*str == ' ')
		str++;

	len = ft_strlen(str);
	while (len > 0 && str[len - 1] == ' ')
		len--;

	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);

	substr[len] = '\0';
	while (len--)
		substr[len] = str[len];

	return (substr);
}



// Check the list, searches for a color identifier "F " or "C " and extracts their RGB values

/* void	fill_colors(t_data **data, t_list **list, int *dst_hex, int *dst_rgb, char *src)
{
	t_list	*tmp;
	char	*to_split;

	tmp = *list;
	to_split = NULL;
	while (tmp)
	{
		if (ft_strncmp(tmp->line, src, 2) == 0)
		{
			to_split = trimmed_string(tmp->line, src);
			if (!to_split)
			{
				if (ft_strcmp(src, "F ") == 0)
					clean_all_exit(data, list, "Floor RGB data init failed\n");
				else if (ft_strcmp(src, "C ") == 0)
					clean_all_exit(data, list, "Ceiling RGB data init failed\n");
			}
			*dst_hex = rgb_in_hexa_value(data, list, &to_split, dst_rgb);
			if (*dst_hex == -1)
			{
				free(to_split);
				clean_all_exit(data, list, "Wrong RGB Format, found unauthorized space\n");
			}
			free(to_split);
		}
		tmp = tmp->next;
	}
} */

void	fill_colors(t_data **data, t_list **list, int *dst_hex, int *dst_rgb, char *src)
{
	t_list	*tmp;
	char	*to_split;
	char	*cleaned_line;

	tmp = *list;
	while (tmp)
	{
		cleaned_line = ft_strtrim(tmp->line, " \t");
		if (!cleaned_line)
			clean_all_exit(data, list, "Memory allocation failed\n");

		if (ft_strncmp(cleaned_line, src, 2) == 0)
		{
			to_split = trimmed_string(cleaned_line, src);
			free(cleaned_line);

			if (!to_split)
				clean_all_exit(data, list, "RGB data init failed\n");

			to_split = remove_spaces_and_tabs(to_split);  

			*dst_hex = rgb_in_hexa_value(data, list, &to_split, dst_rgb);
			free(to_split);
			return;
		}
		free(cleaned_line);
		tmp = tmp->next;
	}
}


//  Fill both the RGB array and the hex color
// Takes a string of comma-separated RGB values and converts them into a single hexadecimal value:
// Example "F 255,0,0" into "0x0000ff000"
// Return (0x0000ff000)

int	rgb_in_hexa_value(t_data **data, t_list **list, char **str, int *dst_rgb)
{
	char	**array;
	int		rgb[3];
	int		hexa_color;

	if (check_rgb_syntax(*str) == 1)
	{
		ft_putstr_fd("Syntax error in RGB line\n", STDERR_FILENO);
		return (-1);
	}
	set_tab_with_zero(rgb, 3, 0);
	hexa_color = 0;
	array = ft_split(data, list, *str, ',');
	if (!array)
	{
		free(str);
		clean_all_exit(data, list, "Split RGB on commas Malloc fail\n");
	}
	check_value_limits(data, list, array, str);
	rgb[RED_RGB] = ft_atoi(array[RED_RGB]);
	rgb[GREEN_RGB] = ft_atoi(array[GREEN_RGB]);
	rgb[BLUE_RGB] = ft_atoi(array[BLUE_RGB]);
	hexa_color = trgb(0, rgb[RED_RGB], rgb[GREEN_RGB], rgb[BLUE_RGB]);
	dst_rgb[RED_RGB] = rgb[RED_RGB];
	dst_rgb[GREEN_RGB] = rgb[GREEN_RGB];
	dst_rgb[BLUE_RGB] = rgb[BLUE_RGB];
	free_array(array);
	return (hexa_color);
}


// Checks if the RGB string is in a valid format (no spaces in the RGB line)

int	check_rgb_syntax(char *str)
{
    int		i;
    char	*cleaned_str;

    cleaned_str = remove_spaces_and_tabs(str);
    if (!cleaned_str)
        return (1);
    i = 0;
    while (!ft_isdigit(cleaned_str[i]))
        ++i;
    cleaned_str += i;
    if (ft_strchr(cleaned_str, ' ') != 0)
    {
        free(cleaned_str);
        return (1);
    }
    free(cleaned_str);
    return (0);
}

// This function checks if the RGB values are within the range (0–255) and properly formatted
void	check_value_limits(t_data **data, t_list **list, char **array, char **str)
{
	int	i;
	int	len;
	int	nbr;

	i = 0;
	len = 0;
	nbr = 0;
	while (array && array[i])
	{
		len = 0;
		len = count_digits(array[i]);
		nbr = ft_atoi(array[i]);
		if (len == -1 || len > 3 || nbr > 255)
		{
			free(*str);
			free_array(array);
			if (len == -1)
				clean_all_exit(data, list, "RGB value syntax error\n");
			if (len > 3)
				clean_all_exit(data, list, "RGB value is too long\n");
			if (nbr > 255)
				clean_all_exit(data, list, "RGB value is too big, choose from 0-255 range\n");
		}
		i++;
	}
}
// Checks the length of a number in a string, skipping for possible spaces around the number
// Returns (number length) or (-1) if invalid chars
int	count_digits(char *str)
{
	int	i;

	i = 0;
	while (*str == ' ')
		str++;
	while (ft_isdigit(*str))
	{
		i++;
		str++;
	}
	while (*str == ' ')
		str++;
	if (ft_isdigit(*str))
		return (-1);
	return (i);
}
