#include "../../includes/cub3d.h"

void    render_floor_ceiling(t_mlx *mlx)
{
    int x;
    int y;

    x = 0;
    while (x < SCREEN_WIDTH)
    {
        y = 0;
        while (y < SCREEN_HIGHT)
        {
            if (y < SCREEN_HIGHT / 2)
                put_pix_to_img(mlx, x, y, trgb(0, mlx->map->ceiling_rgb[0], mlx->map->ceiling_rgb[1], mlx->map->ceiling_rgb[2]));
            else
                put_pix_to_img(mlx, x, y, trgb(0, mlx->map->floor_rgb[0], mlx->map->floor_rgb[1], mlx->map->floor_rgb[2]));
            y++;
        }
        x++;
    }
    return ;
}