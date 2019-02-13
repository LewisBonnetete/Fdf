/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:54:05 by lbonnete          #+#    #+#             */
/*   Updated: 2019/02/13 13:59:49 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "mlx.h"
# include "math.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct  s_mouse_info
{
    void		*ptr;
    void		*win;
    int			x1;
    int			y1;
	int			x2;
    int			y2;
    int			color;
	int			set;
    int     	thickness;
}				t_mouse_info;

typedef struct  s_map_info
{
    int			**map;
    int			longueur;
    int			hauteur;
}               t_map_info;

typedef struct  s_info
{
    void		*ptr;
    void		*win;
	int			start_x;
	int			start_y;
    int			x1;
    int			y1;
	int			x2;
    int			y2;
    int			thickness;
	int			amp;
	int 		width;
    int			angle;
    int			color1;
    int			color2;
    int         font;
	int		    set;
    int         window_height;
    int         window_width;
    t_map_info  *map;
}               t_info;

typedef struct s_line
{
	int			dx;
	int			sx;
	int			dy;
	int			sy;
	int			err;
	int			e2;
}				t_line;

/*Dealers*/
int				deal_key(int key, t_info *mouse);
int				deal_mouse(int button, int x, int y, t_info *info);
/*mappers*/
int				ft_get_map(t_map_info *map, int fd);
char            **ft_get_char_map(int fd);
void    		draw_links(t_info *info);
/*drawers*/
int				ft_draw_line_mouse(t_mouse_info *info);
void			draw_point_mouse(t_mouse_info *info);
void    		draw_links(t_info *info);
int				draw_point(t_info *info);
int             ft_draw_line(t_info *info);
/*tools*/
char			**ft_realloc_map(char **map, int len);
void        	destroy_tab(char ***tab);
int				ft_tab_len(char **tab);
int		        RGB(int r, int g, int b);
void	        put_font(t_info *info);
/*info_editers*/

void			ft_reset_info(t_info *info);
/*printers*/
void    static  printing_map_size(t_map_info *map);

#endif
