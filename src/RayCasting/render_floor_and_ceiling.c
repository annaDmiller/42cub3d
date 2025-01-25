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
                put_pix_to_img(mlx, x, y, trgb(0, mlx->map->ceil[0], mlx->map->ceil[1], mlx->map->ceil[2]));
            else
                put_pix_to_img(mlx, x, y, trgb(0, mlx->map->floor[0], mlx->map->floor[1], mlx->map->floor[2]));
            y++;
        }
        x++;
    }
    return ;
}