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
    mlx->ray->wall_hit_y = (float) mlx->player[Y_PIXEL] + mlx->ray->dist * sin(norming_angle(mlx->ray->angle));
    if (mlx->ray->hit_vert_wall == 0)
    {
        if (ceil(mlx->ray->wall_hit_y) - mlx->ray->wall_hit_y <= mlx->ray->wall_hit_y - floor(mlx->ray->wall_hit_y))
            mlx->ray->wall_hit_y = ceil(mlx->ray->wall_hit_y);
        else
            mlx->ray->wall_hit_y = floor(mlx->ray->wall_hit_y);
    }
    mlx->ray->wall_hit_x = (float) mlx->player[X_PIXEL] + mlx->ray->dist * cos(norming_angle(mlx->ray->angle));
    if (mlx->ray->hit_vert_wall == 1)
    {
        if (ceil(mlx->ray->wall_hit_x) - mlx->ray->wall_hit_x <= mlx->ray->wall_hit_x - floor(mlx->ray->wall_hit_x))
            mlx->ray->wall_hit_x = ceil(mlx->ray->wall_hit_x);
        else
            mlx->ray->wall_hit_x = floor(mlx->ray->wall_hit_x);
    }
    return ;
}

void    put_pix_to_img(t_mlx *mlx, int x, int y, int color)
{
    char    *pix;

    if (y < 0 || y > SCREEN_HIGHT - 1 || x < 0 || x > SCREEN_WIDTH - 1)
        return ;
    pix = ((char *)mlx->image[PLACEHOLDER].address + (y * mlx->image[PLACEHOLDER].line_length + x * (mlx->image[PLACEHOLDER].bits_per_pixel / 8)));
    *(int *)pix = color;
    return ;
}

int trgb(int t, int r, int g, int b)
{
    return (t << 24 | r << 16 | g << 8 | b);
}

int get_color(int x, int y, t_img *texture)
{
    return (*(int *) (texture->address + (y * texture->width + x)));
}