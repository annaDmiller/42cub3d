#include "../../includes/cub3d.h"

static t_img    *check_side(t_mlx *mlx, int hit_vert_wall);
static float    find_x_offset(t_mlx *mlx, int hit_vert_wall, t_img *texture);

void texture_wall(t_mlx *mlx, int screen_line, float wall_bot_pxl, float wall_top_pxl)
{
    t_img   *texture;
    float   x_offset;
    float   y_offset;

    texture = check_side(mlx, mlx->ray->hit_vert_wall);
    x_offset = find_x_offset(mlx, mlx->ray->hit_vert_wall, texture);
    y_offset = find_y_offset(mlx, wall_top_pxl - wall_bot_pxl, texture);
    //paint_wall
    return ;
}

static t_img    *check_side(t_mlx *mlx, int hit_vert_wall)
{
    mlx->ray->angle = norming_angle(mlx->ray->angle);
    if (hit_vert_wall == 1)
    {
        if (mlx->ray->angle > M_PI_2 && mlx->ray->angle < 3 * M_PI_2)
            return (mlx->textures->w_text);
        else
            return (mlx->textures->e_text);
    }
    else
    {
        if (mlx->ray->angle > 0 && mlx->ray->angle < M_PI)
            return (mlx->textures->s_text);
        else
            return (mlx->textures->n_text);
    }
}

static float    find_x_offset(t_mlx *mlx, int hit_vert_wall, t_img *texture)
{
    if (hit_vert_wall == 1)
        return (fmodf(mlx->ray->wall_hit_y * (texture->width / CELL_SIZE), CELL_SIZE));
    return (fmodf(mlx->ray->wall_hit_x * (texture->width / CELL_SIZE), CELL_SIZE));
}

static float    find_y_offset(t_mlx *mlx, float wall_height, t_img *texture)
{
    return (wall_height / texture->height); 
}