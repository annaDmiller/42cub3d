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
    mlx->ray->wall_hit_x = (float) mlx->player[X_PIXEL] + mlx->ray->dist * cos(norming_angle(mlx->ray->angle));
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
    return (t << 24 | r << 16 | g << 6 | b);
}

int get_color(int x, int y, t_img *texture)
{
    return (*(int *) (texture->address + (y * texture->line_length + x * (texture->bits_per_pixel / 8))));
}