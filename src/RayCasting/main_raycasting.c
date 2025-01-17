#include "../../includes/cub3d.h"

void    ray_casting(t_mlx *mlx)
{
    float   inter_hor;
    float   inter_vert;
    int     screen_line;

    mlx->ray->angle = mlx->player->angle - (mlx->player->sight_rad / 2);
    screen_line = 0;
    while (screen_line < SCREEN_WIDTH)
    {
        inter_hor = find_horiz_intersection(mlx, norming_angle(mlx->ray->angle));
        inter_vert = find_vert_intersection(mlx, norming_angle(mlx->ray->angle));
        //draw_line(mlx, screen_line);
        screen_line++;
        mlx->ray->angle += (mlx->player->sight_rad / SCREEN_WIDTH);
    }
}