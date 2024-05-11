/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:08:47 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/03 07:31:28 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static float sign(point a, point b, point c)
{
	return (((a.getx() - c.getx()) * (b.gety() - c.gety()) - (b.getx() - c.getx()) * (a.gety() - c.gety())).toFloat());
}

bool	bsp(point const a, point const b, point const c, point const point)
{
	float d1, d2, d3;

	d1 = sign(point, a, b);
	d2 = sign(point, b, c);
	d3 = sign(point, c, a);

	return !((d1 < 0) || (d2 < 0) || (d3 < 0))
		&&	((d1 > 0) || (d2 > 0) || (d3 > 0));
};