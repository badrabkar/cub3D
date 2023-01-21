/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 21:23:44 by babkar            #+#    #+#             */
/*   Updated: 2023/01/20 18:27:16 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "errno.h"

t_map   textures_init(t_map map)
{
    int width;
    int heigth;

    width = 64;
    heigth = 64;
    map.east_texture.img = mlx_xpm_file_to_image(map.mlx.mlx, map.east_texture_xpm, &width, &heigth);
    if (!map.east_texture.img)
        puterr("mlx_xpm_file_to_image failed!");
    map.east_texture.addr_int = (int *)mlx_get_data_addr(map.east_texture.img, &map.east_texture.bits_per_pixel, &map.east_texture.line_length, &map.east_texture.endian);
    if (!map.east_texture.addr_int)
        puterr("mlx_get_data_addr failed!");
        
    map.west_texture.img = mlx_xpm_file_to_image(map.mlx.mlx, map.west_texture_xpm, &width, &heigth);
    if (!map.west_texture.img)
        puterr("mlx_xpm_file_to_image failed!");
    map.west_texture.addr_int = (int *)mlx_get_data_addr(map.west_texture.img, &map.west_texture.bits_per_pixel, &map.west_texture.line_length, &map.west_texture.endian);
    if (!map.west_texture.addr_int)
        puterr("mlx_get_data_addr failed!");
        
    map.north_texture.img = mlx_xpm_file_to_image(map.mlx.mlx, map.north_texture_xpm, &width, &heigth);
    if (!map.north_texture.img)
        puterr("mlx_xpm_file_to_image failed!");
    map.north_texture.addr_int = (int *)mlx_get_data_addr(map.north_texture.img, &map.north_texture.bits_per_pixel, &map.north_texture.line_length, &map.north_texture.endian);
    if (!map.north_texture.addr_int)
        puterr("mlx_get_data_addr failed!");
        
    map.south_texture.img = mlx_xpm_file_to_image(map.mlx.mlx, map.south_texture_xpm,&width, &heigth);
    if (!map.south_texture.img)
        puterr("mlx_xpm_file_to_image failed!");
    map.south_texture.addr_int = (int *)mlx_get_data_addr(map.south_texture.img, &map.south_texture.bits_per_pixel, &map.south_texture.line_length, &map.south_texture.endian);
    if (!map.south_texture.addr_int)
        puterr("mlx_get_data_addr failed!");
    return (map);
}