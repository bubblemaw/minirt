/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 19:29:38 by masase            #+#    #+#             */
/*   Updated: 2025/06/10 11:15:42 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void print_camera_as_array(t_camera *cam)
{
    printf("Camera %d:\n", cam->number);
    printf("Position: [%.2f, %.2f, %.2f]\n", cam->x, cam->y, cam->z);
    printf("Orientation: [%.2f, %.2f, %.2f]\n", cam->v_x, cam->v_y, cam->v_z);
    printf("Field of View: %d\n", cam->FOV);
}

void print_plane_as_array(t_plane *pl)
{
    printf("Plane %d:\n", pl->number);
    printf("Position: [%.2f, %.2f, %.2f]\n", pl->x, pl->y, pl->z);
    printf("Orientation: [%.2f, %.2f, %.2f]\n", pl->v_x, pl->v_y, pl->v_z);
    printf("Color: [%d, %d, %d]\n", pl->R, pl->G, pl->B);
}

void print_sphere_as_array(t_sphere *sp)
{
    printf("Sphere %d:\n", sp->number);
    printf("Position: [%.2f, %.2f, %.2f]\n", sp->x, sp->y, sp->z);
    printf("Diameter: %.2f\n", sp->diameter);
    printf("Color: [%d, %d, %d]\n", sp->R, sp->G, sp->B);
}

void print_cylinder_as_array(t_cylinder *cyl)
{
    printf("Cylinder %d:\n", cyl->number);
    printf("Position: [%.2f, %.2f, %.2f]\n", cyl->x, cyl->y, cyl->z);
    printf("Orientation: [%.2f, %.2f, %.2f]\n", cyl->v_x, cyl->v_y, cyl->v_z);
    printf("Color: [%d, %d, %d]\n", cyl->R, cyl->G, cyl->B);
    printf("Dimensions: [Diameter: %.2f, Height: %.2f]\n", cyl->diameter, cyl->height);
}

void print_ambiance_as_array(t_ambiance *amb)
{
    printf("Ambient Light %d:\n", amb->number);
    printf("Color: [%d, %d, %d]\n", amb->R, amb->G, amb->B);
    printf("Ratio: %.2f\n", amb->ratio);
}

void print_point_as_array(t_point *pt)
{
    printf("Point Light %d:\n", pt->number);
    printf("Position: [%.2f, %.2f, %.2f]\n", pt->x, pt->y, pt->z);
    printf("Brightness Ratio: %.2f\n", pt->bright_ratio);
}
