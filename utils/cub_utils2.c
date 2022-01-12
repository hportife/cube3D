/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hportife <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:05:13 by hportife          #+#    #+#             */
/*   Updated: 2022/01/04 12:08:33 by hportife         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

t_img	make_image(void *mlx, int w, int h)
{
	t_img	img;

	img.width = w;
	img.height = h;
	img.img = mlx_new_image(mlx, w, h);
	if (!img.img)
		return (img);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	img.pixel_len = img.bits_per_pixel / 8;
	return (img);
}

t_img	load_image(void *mlx, char *path)
{
	t_img	img;

	img.img = mlx_xpm_file_to_image(mlx, path, &(img.width), &(img.height));
	if (!img.img)
		return (img);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	img.pixel_len = img.bits_per_pixel / 8;
	return (img);
}

void	set_img_strip(t_img *data, t_shape shape, float offset)
{
	t_vec		v;
	int			t;
	double		o;
	double		cur;
	char		*dst;

	if (shape.x < 0)
		return ;
	v.y = fmax(0, shape.y);
	v.x = (shape.img->width - 1) * offset;
	o = shape.img->height / (double)shape.height;
	cur = o * (v.y - shape.y);
	dst = data->addr + (
			v.y * data->line_length + shape.x * (data->pixel_len));
	while (v.y < shape.y + shape.height && v.y < data->height)
	{
		t = get_pixel(shape.img, v.x, (int)cur);
		*(unsigned int *)dst = t;
		dst += data->line_length;
		cur += o;
		++v.y;
	}
}
