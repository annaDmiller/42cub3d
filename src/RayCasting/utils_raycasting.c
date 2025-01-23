#include "../../includes/cub3d.h"

double  norming_angle(double angle)
{
    while (!(angle >= 0 && angle <= 2 * M_PI))
    {
    if (angle < 0)
        angle += 2 * M_PI;
    if (angle > 2 * M_PI)
        angle -= 2 * M_PI;
    }
    return (angle);
}

//не уверена на счёт этой функции, примеров этого не было, придумала сама
void    find_wall_hit_point(t_mlx *mlx)
{
    mlx->ray->wall_hit_y = mlx->player->pos_y_pix + mlx->ray->dist * sin(norming_angle(mlx->ray->angle));
    mlx->ray->wall_hit_x = mlx->player->pos_x_pix + mlx->ray->dist * cos(norming_angle(mlx->ray->angle));
    return ;
}