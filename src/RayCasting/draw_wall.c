#include "../../includes/cub3d.h"

void    draw_line(t_mlx *mlx, int screen_line)
{
    float   wall_top_pxl;
    float   wall_bot_pxl;
    float   test_height;
    float   test_ang;

    mlx->ray->dist *= cos(norming_angle(mlx->ray->angle - mlx->player[ANGLE]));
    if (mlx->ray->dist < 0)
        mlx->ray->dist *= -1;
    test_ang = tan(mlx->player[SIGHT] / 2);
    mlx->ray->wall_height = (SCREEN_WIDTH / (2 * tan(mlx->player[SIGHT] / 2)) * (CELL_SIZE / mlx->ray->dist));
    test_height = mlx->ray->wall_height;
    (void) test_height;
    (void) test_ang;
    wall_top_pxl = (SCREEN_HIGHT / 2) - (mlx->ray->wall_height / 2);
    wall_bot_pxl = (SCREEN_HIGHT / 2) + (mlx->ray->wall_height / 2);
    if (wall_bot_pxl > SCREEN_HIGHT)
        wall_bot_pxl = SCREEN_HIGHT;
    if (wall_top_pxl < 0)
        wall_top_pxl = 0;
    paint_wall(mlx, screen_line, wall_bot_pxl, wall_top_pxl);
    return ;
}
