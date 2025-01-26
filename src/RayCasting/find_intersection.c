#include "../../includes/cub3d.h"

static int check_if_wall_hit(float x, float y, t_mlx* mlx);

float  find_horiz_intersection(t_mlx *mlx, double angle)
{
    float   y_step;
    float   x_step;
    float   inter1_y;
    float   inter1_x;
    int     corrector;

    y_step = CELL_SIZE;
    x_step = CELL_SIZE / tan(angle);
    corrector = 1;
    inter1_y = floor((float) mlx->player[Y_PIXEL] / CELL_SIZE) * CELL_SIZE;
    if (angle > 0 && angle < M_PI)
    {
        inter1_y += CELL_SIZE;
        corrector *= -1;
    }
    else
        y_step *= -1;
    inter1_x = (float) mlx->player[X_PIXEL] + (inter1_y - (float) mlx->player[Y_PIXEL]) / tan(angle);
    if ((x_step > 0 && angle > M_PI_2 && angle < 3 * M_PI_2) || (x_step < 0 && (angle < M_PI_2 || angle > 3 * M_PI_2)))
        x_step *= -1;
    while (!check_if_wall_hit(inter1_x, inter1_y - corrector, mlx))
    {
        inter1_x += x_step;
        inter1_y += y_step;
    }
    return (sqrt(pow(inter1_y - (float) mlx->player[Y_PIXEL], 2) + pow(inter1_x - (float) mlx->player[X_PIXEL], 2)));    
}

float   find_vert_intersection(t_mlx *mlx, double angle)
{
    float   y_step;
    float   x_step;
    float   inter1_y;
    float   inter1_x;
    int     corrector;

    x_step = CELL_SIZE;
    y_step = CELL_SIZE * tan(angle);
    corrector = 1;
    inter1_x = floor((float) mlx->player[X_PIXEL] / CELL_SIZE) * CELL_SIZE;
    if (angle < M_PI_2 || angle > 3* M_PI_2)
    {
        inter1_x += CELL_SIZE;
        corrector *= -1;
    }
    else
        x_step *= -1;
    inter1_y = (float) mlx->player[Y_PIXEL] + (inter1_x - (float) mlx->player[X_PIXEL]) * tan(angle);
    if ((y_step > 0 && angle > M_PI) || (y_step < 0 && angle < M_PI))
        y_step *= -1;
    while (!check_if_wall_hit(inter1_x - corrector, inter1_y, mlx))
    {
        inter1_x += x_step;
        inter1_y += y_step;
    }
    return (sqrt(pow(inter1_y - (float) mlx->player[Y_PIXEL], 2) + pow(inter1_x - (float) mlx->player[X_PIXEL], 2)));
}

static int check_if_wall_hit(float x, float y, t_mlx* mlx)
{
    int ind_x;
    int ind_y;

    if (x < 0 || y < 0)
        return (1);
    ind_x = floor(x / CELL_SIZE);
    ind_y = floor(y / CELL_SIZE);
    if (ind_y >= mlx->map->map_height || ind_x >= mlx->map->map_width)
        return (1);
    if (mlx->map->map[ind_y] && ind_x <= ft_strlen(mlx->map->map[ind_y])
        && mlx->map->map[ind_y][ind_x] == '1')
        return (1);
    return (0);
}