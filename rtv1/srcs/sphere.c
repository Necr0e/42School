/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:25:28 by oseitama          #+#    #+#             */
/*   Updated: 2023/01/31 20:08:52 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

/*	Parse Sphere data	*/
void	sphere_data(t_sdl *sdl, char **str)
{
	int	i;

	i = -1;
	OBJP.pos.x = (double)(ft_atoi(str[1]));
	OBJP.pos.y = (double)(ft_atoi(str[2]));
	OBJP.pos.z = (double)(ft_atoi(str[3]));
	OBJP.r = (double)(ft_atoi(str[4])) / 10;
	if (OBJP.r < 0.1 || ft_atoi(str[5]) < 0 || \
		ft_atoi(str[6]) < 0 || ft_atoi(str[7]) < 0)
		ft_error("Wrong input for sphere.");
	OBJP.col.rgb[0] = (unsigned char)(ft_atoi(str[5]));
	OBJP.col.rgb[1] = (unsigned char)(ft_atoi(str[6]));
	OBJP.col.rgb[2] = (unsigned char)(ft_atoi(str[7]));
	OBJP.specular = (double)(ft_atoi(str[8]));
	OBJP.name = SPHERE;
	sdl->obj_counter++;
	while (++i <= 8)
		free(str[i]);
	free(str);
}

/*	Get sphere normals	*/
t_vec	sphere_normal(t_ray *ray, t_object *obj)
{
	t_vec	n;

	n = vec_sum(ray->orig, vec_scale(ray->dir, obj->t));
	n = vec_norm(vec_sub(n, obj->pos));
	if (vec_dot(ray->dir, n) > EPS)
		n = vec_scale(n, -1);
	return (n);
}

/*	Get the intersection points	*/
double	get_t(double a, double b, double d)
{
	double	t1;
	double	t2;

	t1 = (-b - sqrt(d)) / (2 * a);
	t2 = (-b + sqrt(d)) / (2 * a);
	if ((t1 <= t2 && t1 >= 0) || (t1 > 0 && t2 < 0))
		return (t1);
	else if ((t2 <= t1 && t2 >= 0) || (t1 <0 && t2 >= 0))
		return (t2);
	return (-1);
}

/*	Check if ray is intersecting sphere	*/
double	sphere_intersect(t_vec orig, t_vec dir, t_object *obj)
{
	double	a;
	double	b;
	double	c;
	double	d;
	t_vec	oc;

	oc = vec_sub(orig, obj->pos);
	a = vec_dot(dir, dir);
	b = 2 * vec_dot(oc, dir);
	c = vec_dot(oc, oc) - (obj->r * obj->r);
	d = b * b - 4 * a * c;
	if (d < 0)
		return (-1);
	return (get_t(a, b, d));
}

void	sphere(t_sdl *sdl, t_ray *ray, int i, t_object *obj)
{
	obj->t = sphere_intersect(ray->orig, ray->dir, obj);
	if (obj->t > 0 && obj->t < sdl->min_t)
	{
		sdl->min_t = obj->t;
		sdl->clos_obj = i;
	}
}
