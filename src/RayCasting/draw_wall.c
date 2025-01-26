#include "../../includes/cub3d.h"

void    draw_line(t_mlx *mlx, int screen_line)
{
    float   wall_top_pxl;
    float   wall_bot_pxl;

    mlx->ray->dist *= cos(norming_angle(mlx->ray->angle - mlx->player->angle));
    mlx->ray->wall_height = (SCREEN_WIDTH / tan(mlx->player->sight_rad) * (CELL_SIZE / mlx->ray->dist));
    wall_top_pxl = (SCREEN_HIGHT / 2) - (mlx->ray->wall_height / 2);
    wall_bot_pxl = (SCREEN_HIGHT / 2) + (mlx->ray->wall_height / 2);
    if (wall_bot_pxl > SCREEN_HIGHT)
        wall_bot_pxl = SCREEN_HIGHT;
    if (wall_top_pxl < 0)
        wall_top_pxl = 0;
    paint_wall(mlx, screen_line, wall_bot_pxl, wall_top_pxl);
    return ;
}
