/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olly <olly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:42:41 by okapshai          #+#    #+#             */
/*   Updated: 2025/01/26 10:53:11 by olly             ###   ########.fr       */
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
	fill_colors(data, list, &(*data)->floor_hex, (*data)->floor_rgb, "F ");
	fill_colors(data, list, &(*data)->ceiling_hex, (*data)->ceiling_rgb, "C ");
	get_map_size(data, list);
	init_empty_map(data, list);
	fill_map(data, list);
	get_player_position(data);
	//print_data_structure(*data);

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


// Finds a matching line, extracts the texture path (after removing the prefix) and assigns it to *dest

void	fill_texture(t_data **data, t_list **list, char **dest, char *src)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp)
	{
		if (ft_strncmp(tmp->line, src, 3) == 0)
		{
			*dest = trimmed_string(tmp->line, src);
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
}

// Removes any characters found in the set string from both the beginning and the end of the str string. 
// Return (newly allocated string with the unwanted characters removed)

char	*trimmed_string(char *str, char *set)
{
	int		len;
	char	*substr;

	len = 0;
	substr = NULL;
	if (!str || !set)
		return (NULL);
	while (*str && ft_strchr(set, *str))
		str++;
	len = ft_strlen(str);
	while (len && ft_strchr(set, str[len - 1]))
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

void	fill_colors(t_data **data, t_list **list, int *dst_hex, int *dst_rgb, char *src)
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
	hexa_color = create_trgb_value(0, rgb[RED_RGB], rgb[GREEN_RGB], rgb[BLUE_RGB]);
	dst_rgb[RED_RGB] = rgb[RED_RGB];
	dst_rgb[GREEN_RGB] = rgb[GREEN_RGB];
	dst_rgb[BLUE_RGB] = rgb[BLUE_RGB];
	free_array(array);
	return (hexa_color);
}



// Create a trgb single int from 4 ints. One byte containing 2^8 = 256
// t (transparency): Alpha (transparency) channel. It is typically an integer between 0 (completely transparent) and 255 (completely opaque).
// r (red): Red channel. It is an integer between 0 and 255, where 0 is no red, and 255 is the maximum amount of red.
// g (green): Green channel. It is an integer between 0 and 255, where 0 is no green, and 255 is the maximum amount of green.
// b (blue): Blue channel. It is an integer between 0 and 255, where 0 is no blue, and 255 is the maximum amount of blue.
// Return (a single 32-bit integer that encodes the RGBA color information)
// Each channel is packed into one byte, which makes up the 4-byte (32-bit) integer

int	create_trgb_value(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

// Helper function to remove spaces and tabs from a string

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
				clean_all_exit(data, list, "RGB value too big\n");
			if (nbr > 255)
				clean_all_exit(data, list, "RGB value too big\n");
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


void	print_data_structure(t_data *data)
{
	int i;

	printf("=== t_data Structure ===\n");
	printf("Map Dimensions: Width = %d, Height = %d\n", data->map_width, data->map_height);
	printf("\nMap:\n");
	for (i = 0; i < data->map_height; i++)
		printf("%s\n", data->map[i]);
	printf("\nTextures:\n");
	printf("North Texture: %s\n", data->north_texture ? data->north_texture : "Not Set");
	printf("South Texture: %s\n", data->south_texture ? data->south_texture : "Not Set");
	printf("West Texture: %s\n", data->west_texture ? data->west_texture : "Not Set");
	printf("East Texture: %s\n", data->east_texture ? data->east_texture : "Not Set");
	printf("\nFloor Colors (RGB): [%d, %d, %d]\n", 
		data->floor_rgb[RED_RGB], data->floor_rgb[GREEN_RGB], data->floor_rgb[BLUE_RGB]);
	printf("Floor Color (Hex): 0x%08x\n", data->floor_hex);

	printf("\nCeiling Colors (RGB): [%d, %d, %d]\n", 
		data->ceiling_rgb[RED_RGB], data->ceiling_rgb[GREEN_RGB], data->ceiling_rgb[BLUE_RGB]);
	printf("Ceiling Color (Hex): 0x%08x\n", data->ceiling_hex);
	printf("\nPlayer Details:\n");
	printf("Position: X = %d, Y = %d\n", data->player_x, data->player_y);
	printf("Direction: %c\n", data->player_direction);
	printf("Direction (Radian): %.2f\n", data->player_direction_radian);

	printf("========================\n");
}
