/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:07:14 by oseitama          #+#    #+#             */
/*   Updated: 2023/01/31 18:06:05 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

/*	Parse Plane data	*/
void	plane_data(t_sdl *sdl, char **str)
{
	int	i;

	i = -1;
	OBJP.pos.x = (double)(ft_atoi(str[1]));
	OBJP.pos.y = (double)(ft_atoi(str[2]));
	OBJP.pos.z = (double)(ft_atoi(str[3]));
	OBJP.rot.x = (double)(ft_atoi(str[4]));
	OBJP.rot.y = (double)(ft_atoi(str[5]));
	OBJP.rot.z = (double)(ft_atoi(str[6]));
	if (ft_atoi(str[7]) < 0 || ft_atoi(str[8]) < 0 || ft_atoi(str[9]) < 0)
		ft_error("Wrong input.");
	OBJP.col.rgb[0] = (unsigned char)(ft_atoi(str[7]));
	OBJP.col.rgb[1] = (unsigned char)(ft_atoi(str[8]));
	OBJP.col.rgb[2] = (unsigned char)(ft_atoi(str[9]));
	OBJP.specular = (double)(ft_atoi(str[10]));
	OBJP.name = PLANE;
	sdl->obj_counter++;
	while (++i <= 10)
		free(str[i]);
	free(str);
}

/*	Get the plane normal	*/
t_vec	plane_normal(t_ray *ray, t_object *obj)
{
	if (vec_dot(ray->dir, obj->rot) < 0)
		return (obj->rot);
	return (vec_scale(obj->rot, -1));
}

/*	Check if ray intersects plane	*/
double	plane_intersect(t_vec orig, t_vec dir, t_object *obj)
{
	double	t;
	double	a;
	double	b;
	t_vec	x;

	x = vec_sub(orig, obj->pos);
	a = vec_dot(x, obj->rot);
	b = vec_dot(dir, obj->rot);
	if (b == 0 || (a < 0 && b < 0) || (a > 0 && b > 0))
		return (-1);
	t = -a / b;
	if (t > EPS)
		return (t);
	return (-1);
}

void	plane(t_sdl *sdl, t_ray *ray, int i, t_object *obj)
{
	obj->rot = vec_norm(obj->rot);
	obj->t = plane_intersect(ray->orig, ray->dir, obj);
	if (obj->t > 0 && obj->t < sdl->min_t)
	{
		sdl->min_t = obj->t;
		sdl->clos_obj = i;
	}
}
