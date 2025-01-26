#include "../../includes/cub3d.h"

static t_img    *check_side(t_mlx *mlx, int hit_vert_wall);
static float    find_x_offset(t_mlx *mlx, int hit_vert_wall, t_img *texture);

void paint_wall(t_mlx *mlx, int x_img, float wall_bot_pxl, float wall_top_pxl)
{
    t_img   *texture;
    int     x_text;
    float   y_step;
    int     y_text;
    int     color;

    texture = check_side(mlx, mlx->ray->hit_vert_wall);
    x_text = (int) find_x_offset(mlx, mlx->ray->hit_vert_wall, texture);
    y_step = (wall_bot_pxl - wall_top_pxl) / texture->height;
    y_text = (int) (wall_top_pxl - (SCREEN_HIGHT / 2) + (mlx->ray->wall_height / 2)) * y_step;
    if (y_text < 0)
        y_text = 0;
    while (wall_top_pxl < wall_bot_pxl)
    {
        color = get_color(x_text, y_text, texture);
        put_pix_to_img(mlx, x_img, wall_top_pxl, color);
        y_text += y_step;
        wall_top_pxl++;
    }
    return ;
}

static t_img    *check_side(t_mlx *mlx, int hit_vert_wall)
{
    mlx->ray->angle = norming_angle(mlx->ray->angle);
    if (hit_vert_wall == 1)
    {
        if (mlx->ray->angle > M_PI_2 && mlx->ray->angle < 3 * M_PI_2)
            return (&(mlx->image[WALL_WEST]));
        else
            return (&(mlx->image[WALL_EAST]));
    }
    else
    {
        if (mlx->ray->angle > 0 && mlx->ray->angle < M_PI)
            return (&(mlx->image[WALL_SOUTH]));
        else
            return (&(mlx->image[WALL_NORTH]));
    }
}

static float    find_x_offset(t_mlx *mlx, int hit_vert_wall, t_img *texture)
{
    if (hit_vert_wall == 1)
        return (fmodf(mlx->ray->wall_hit_y * (texture->width / CELL_SIZE), CELL_SIZE));
    return (fmodf(mlx->ray->wall_hit_x * (texture->width / CELL_SIZE), CELL_SIZE));
}
