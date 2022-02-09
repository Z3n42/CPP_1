/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mesh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-f <fsilva-f@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 21:17:26 by fsilva-f          #+#    #+#             */
/*   Updated: 2022/02/07 20:49:14 by fsilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

static void	set_point(t_pos *store, t_window *win, t_wcoord *wcoord_out, \
						t_pair *pair)
{
	t_wcoord	wcoord_in;
	t_scoord	scoord;

	get_wcoord(store, wcoord_out, &wcoord_in);
	get_scoord_iso(store, win, &wcoord_in, &scoord);
	add_to_pair(pair, &scoord);
}

/* get_pair()
Build the pair of points to will be used to draw the next line segment
*/
static t_pair	*get_pair(t_pos *store, t_window *win, \
						t_wcoord wcoord, int horiz)
{
	t_pair	*pair;

	pair = (t_pair *)malloc(sizeof (t_pair));
	if (pair == NULL)
		error_exit(1);
	pair->end = 0;
	set_point(store, win, &wcoord, pair);
	if (horiz == 1)
		wcoord.x = wcoord.x + 1;
	else
		wcoord.y = wcoord.y + 1;
	pair->end = 1;
	set_point(store, win, &wcoord, pair);
	return (pair);
}

/* draw_mesh_hori()
Draws the horizontal lines
*/
static void	draw_mesh_hori(t_pos *store, t_window *win)
{
	t_wcoord	wcoord;
	t_pair		*pair;
	int			horiz;

	horiz = 1;
	wcoord.y = 0;
	while (wcoord.y < store->y_max)
	{
		wcoord.x = 1;
		while (wcoord.x <= store->x_max - 1)
		{	
			pair = get_pair(store, win, wcoord, horiz);
			draw_line(win, pair);
			free(pair);
			wcoord.x = wcoord.x + 1;
		}
		wcoord.y = wcoord.y + 1;
	}
}

/* draw_mesh_vert()
Draws the vertical lines
*/
static void	draw_mesh_vert(t_pos *store, t_window *win)
{
	t_wcoord	wcoord;
	t_pair		*pair;
	int			horiz;

	horiz = 0;
	wcoord.x = 1;
	while (wcoord.x < store->x_max)
	{
		wcoord.y = 0;
		while (wcoord.y < store->y_max - 1)
		{
			pair = get_pair(store, win, wcoord, horiz);
			draw_line(win, pair);
			free(pair);
			wcoord.y = wcoord.y + 1;
		}
		wcoord.x = wcoord.x + 1;
	}
}

void	draw_mesh(t_pos *store, t_window *win)
{
	draw_mesh_hori(store, win);
	draw_mesh_vert(store, win);
}
