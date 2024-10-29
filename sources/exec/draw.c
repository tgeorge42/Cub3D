/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:42:54 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/14 17:20:29 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	set_textures_variables(t_cub *cub, t_ray *ray, int x)
{
	(void)x;
	ray->wall_x = 0;
	ray->tex_pos = 0;
	ray->draw_start = -ray->line_height / 2 + cub->window_y / 2;
	if (ray->draw_start < 0 || ray->draw_start > cub->window_y)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + cub->window_y / 2;
	if (ray->draw_end >= cub->window_y)
		ray->draw_end = cub->window_y - 1;
	if (ray->side == 0)
		ray->wall_x = cub->game->p_pos_y + ray->ray_length * ray->diray_y;
	else
		ray->wall_x = cub->game->p_pos_x + ray->ray_length * ray->diray_x;
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x * (double)cub->textures[cub->game->texture].tex_width);
	if ((ray->side == 0 && ray->diray_x > 0) || (ray->side == 1 && ray->diray_y < 0))
		ray->tex_x = cub->textures[cub->game->texture].tex_width
			- ray->tex_x - 1;
	ray->step = 1 * (double)cub->textures[cub->game->texture].tex_height
		/ ray->line_height;
	ray->tex_pos = (ray->draw_start - WINHEIGHT
			/ 2 + ray->line_height / 2) * ray->step;
}

void	pick_texture(t_cub *cub, t_ray *ray)
{
	if (ray->side == 0 && ray->diray_x < 0)
		cub->game->texture = EA_TEXT;
	else if (ray->side == 0 && ray->diray_x > 0)
		cub->game->texture = WE_TEXT;
	else if (ray->side == 1 && ray->diray_y < 0)
		cub->game->texture = SO_TEXT;
	else if (ray->side == 1 && ray->diray_y > 0)
		cub->game->texture = NO_TEXT;
}

void	draw_textures(t_cub *cub, t_ray *ray, int x)
{
	int		i;

	pick_texture(cub, cub->ray);
	set_textures_variables(cub, cub->ray, x);
	i = ray->draw_start;
	while (i >= 0)
	{
		my_mlx_pixel_put(cub->img, x, i, get_rgb(cub->ceiling));
		i--;
	}
	i = ray->draw_start;
	while (i <= ray->draw_end)
	{
		my_mlx_pixel_put(cub->img, x, i,
			get_color(cub, ray->tex_x, ray->tex_pos, cub->game->texture));
		ray->tex_pos += ray->step;
		i++;
	}
	while (i < cub->window_y)
	{
		my_mlx_pixel_put(cub->img, x, i, get_rgb(cub->floor));
		i++;
	}
}

// void	draw_lines(t_cub *cub, int line_height, int side, int x)
// {
// 	int		draw_start;
// 	int		draw_end;
// 	int		color;
// 	int		i;

// 	draw_start = -line_height / 2 + cub->window_y / 2;
// 	if (draw_start < 0 || draw_start > cub->window_y)
// 		draw_start = 0;
// 	draw_end = line_height / 2 + cub->window_y / 2;
// 	if (draw_end >= cub->window_y)
// 		draw_end = cub->window_y - 1;
// 	if (side == 1)
// 		color = 0x00FF0000;
// 	else
// 		color = 0x0000FF00;
// 	// i = 0;
// 	// printf("start = %d\n", draw_start);
// 	i = draw_start;
// 	while (i >= 0)
// 	{
// 		my_mlx_pixel_put(cub->img, x, i, 0x000000FF);
// 		i--;
// 	}
// 	i = draw_start;
// 	while (i <= draw_end)
// 	{
// 		my_mlx_pixel_put(cub->img, x, i, color);
// 		i++;
// 	}
// 	while (i < cub->window_y - 1)
// 	{
// 		my_mlx_pixel_put(cub->img, x, i, 0x00FFFFFF);
// 		i++;
// 	}
// }
