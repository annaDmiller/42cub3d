#include "../../includes/cub3d.h"

void    ray_casting(t_mlx *mlx)
{
    float   inter_hor;
    float   inter_vert;
    int     screen_line;

    mlx->ray->angle = mlx->player->angle - (mlx->player->sight_rad / 2);
    screen_line = 0;
    render_floor_ceiling(mlx);
    while (screen_line < SCREEN_WIDTH)
    {
        inter_hor = find_horiz_intersection(mlx, norming_angle(mlx->ray->angle));
        inter_vert = find_vert_intersection(mlx, norming_angle(mlx->ray->angle));
        if (inter_vert <= inter_hor)
        {
            mlx->ray->dist = inter_vert;
            mlx->ray->hit_vert_wall = 1;
        }
        else
        {
            mlx->ray->dist = inter_hor;
            mlx->ray->hit_vert_wall = 0;
        }
        find_wall_hit_point(mlx);
        draw_line(mlx, screen_line);
        screen_line++;
        mlx->ray->angle += (mlx->player->sight_rad / SCREEN_WIDTH);
    }
    mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->mlx_img, 0, 0);
    return ;
}