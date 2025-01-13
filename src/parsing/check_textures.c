#include "../../includes/cub3d.h"

void    check_text_extensions(t_data **data)
{
    if (check_extension((*data)->south_texture, ".xpm")
        || check_extension((*data)->north_texture, ".xpm")
        || check_extension((*data)->west_texture, ".xpm")
        || check_extension((*data)->east_texture, ".xpm"))
        return (clean_data_map_exit(data, 0, "Textures must have .xpm extension\n"));
    return ;
}