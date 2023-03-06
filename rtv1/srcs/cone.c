/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:20:47 by oseitama          #+#    #+#             */
/*   Updated: 2023/01/31 17:17:31 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

/*	Parse cone data	*/
void	cone_data(t_sdl *sdl, char **str)
{
	int	i;

	i = -1;
	OBJP.pos.x = (double)(ft_atoi(str[1]));
	OBJP.pos.y = (double)(ft_atoi(str[2]));
	OBJP.pos.z = (double)(ft_atoi(str[3]));
	OBJP.r = (double)(ft_atoi(str[4])) / 10;
	OBJP.rot.x = (double)(ft_atoi(str[5])) / 10;
	OBJP.rot.y = (double)(ft_atoi(str[6])) / 10;
	OBJP.rot.z = (double)(ft_atoi(str[7])) / 10;
	if (OBJP.r < 0.1 || ft_atoi(str[8]) < 0 || \
		ft_atoi(str[9]) < 0 || ft_atoi(str[10]) < 0)
		ft_error("Wrong input for cone.");
	OBJP.col.rgb[0] = (unsigned char)(ft_atoi(str[8]));
	OBJP.col.rgb[1] = (unsigned char)(ft_atoi(str[9]));
	OBJP.col.rgb[2] = (unsigned char)(ft_atoi(str[10]));
	OBJP.specular = (double)(ft_atoi(str[11]));
	OBJP.name = CONE;
	sdl->obj_counter++;
	while (++i <= 11)
		free(str[i]);
	free(str);
}

/*	Checks if ray intersects the cone	*/
double	cone_intersect(t_vec orig, t_vec dir, t_object *obj)
{
	double	a;
	double	b;
	double	c;
	double	d;
	t_vec	x;

	x = vec_sub(orig, obj->pos);
	a = vec_dot(dir, obj->rot);
	a = vec_dot(dir, dir) - (1 + obj->r * obj->r) * a * a;
	b = 2 * (vec_dot(dir, x) - (1 + obj->r * obj->r)) * \
		vec_dot(dir, obj->rot) * vec_dot(x, obj->rot);
	c = vec_dot(x, x) - (1 + obj->r * obj->r) * \
		ft_pow(vec_dot(x, obj->rot), 2);
	d = b * b -4 * a * c;
	if (d < EPS)
		return (-1);
	return (get_t(a, b, d));
}

/*	Calculate the normals of the cone	*/
t_vec	cone_normal_calc(t_ray *ray, t_object *obj)
{
	double	m;
	t_vec	n;
	t_vec	p;

	m = obj->t * vec_dot(ray->dir, obj->rot) + \
		vec_dot(vec_sub(ray->orig, obj->pos), obj->rot);
	p = vec_sum(ray->orig, vec_scale(ray->dir, obj->t));
	n = vec_scale(vec_scale(obj->rot, m), (1 + obj->r * obj->r));
	n = vec_norm(vec_sub(vec_sub(p, obj->pos), n));
	if (vec_dot(ray->dir, n) > EPS)
		n = vec_scale(n, -1);
	return (n);
}

void	cone(t_sdl	*sdl, t_ray *ray, int i, t_object *obj)
{
	obj->t = cone_intersect(ray->orig, ray->dir, obj);
	obj->rot = vec_norm(obj->rot);
	if (obj->t > 0 && obj->t < sdl->min_t)
	{
		sdl->min_t = obj->t;
		sdl->clos_obj = i;
	}
}
