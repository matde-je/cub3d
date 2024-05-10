# include "../cub3d.h"

static void set_player_values(float dir_x, float dir_y, float plane_x, float plane_y)
{
    c3d()->p.dir_x = dir_x;
    c3d()->p.dir_y = dir_y;
    c3d()->p.plane_x = plane_x;
    c3d()->p.plane_y = plane_y;
}
void init_start(int x, int y)
{
    c3d()->p.pos_x = x + 0.5;
    c3d()->p.pos_y = y + 0.5;
    if (map_iter(x, y) == 'N')
        set_player_values(0, -1, 0.66, 0);
    else if (map_iter(x, y) == 'S')
        set_player_values(0, 1, -0.66, 0);
    else if (map_iter(x, y) == 'E')
        set_player_values(1, 0, 0, 0.66);
    else if (map_iter(x, y) == 'W')
        set_player_values(1, 0, 0, -0.66);
}