#include "../cub3d.h"

void	put_pixel_2img(int x, int y, int color)
{
	if (x < 0 || y < 0)
		return ;
	*(int *)&cub3()->image.addr[(y * cub3()->image.size)\
        + (x * (cub3()->image.bpp / 8))] = color;
}
