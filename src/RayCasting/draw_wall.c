#include "../../includes/cub3d.h"

static void texture_wall(t_mlx *mlx, int screen_line, float wall_bot_pxl, float wall_top_pxl);

void    draw_line(t_mlx *mlx, int screen_line)
{
    float   wall_height;
    float   wall_top_pxl;
    float   wall_bot_pxl;

    mlx->ray->dist *= cos(norming_angle(mlx->ray->angle - mlx->player->angle));
    wall_height = (SCREEN_WIDTH / tan(mlx->player->sight_rad) * (CELL_SIZE / mlx->ray->dist));
    wall_top_pxl = (SCREEN_HIGHT / 2) - (wall_height / 2);
    wall_bot_pxl = (SCREEN_HIGHT / 2) + (wall_height / 2);
    if (wall_bot_pxl > SCREEN_HIGHT)
        wall_bot_pxl = SCREEN_HIGHT;
    if (wall_top_pxl < 0)
        wall_top_pxl = 0;
    texture_wall(mlx, screen_line, wall_bot_pxl, wall_top_pxl);
    return ;
}

static void texture_wall(t_mlx *mlx, int screen_line, float wall_bot_pxl, float wall_top_pxl)
{
    t_img   *texture;

    texture = check_side(mlx, mlx->ray->hit_vert_wall);
    //paint_wall
    //paint_floor
    //paint_ceiling
    return ;
}

static t_img    *check_side(t_mlx *mlx, int hit_vert_wall)
{
    mlx->ray->angle = norming_angle(mlx->ray->angle);
    if (hit_vert_wall == 1)
    {
        if (mlx->ray->angle > M_PI_2 && mlx->ray->angle < 3 * M_PI_2)
            return (mlx->map->west_texture);
        else
            return (mlx->map->east_texture);
    }
    else
    {
        if (mlx->ray->angle > 0 && mlx->ray->angle < M_PI)
            return (mlx->map->south_texture);
        else
            return (mlx->map->north_texture);
    }
}