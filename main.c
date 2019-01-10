/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 15:40:23 by lbonnete          #+#    #+#             */
/*   Updated: 2019/01/10 15:37:07 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	int fd;
	t_info	info;
	char	**map;


	info.ptr = mlx_init();
	info.win = mlx_new_window(info.ptr, 1600, 900, "New");
	info.color1 = 000255255255;
	info.set = 0;
	fd = open(av[1], O_RDONLY);
	if (!(map = ft_get_map(fd)))
		return (0); 
	mlx_mouse_hook(info.win, deal_mouse, &info);
	mlx_key_hook(info.win, deal_key, &info);
	mlx_loop(info.ptr);
	return (0);
}
