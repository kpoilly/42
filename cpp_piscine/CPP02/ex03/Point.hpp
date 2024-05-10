/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 09:42:12 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/02 11:13:41 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include <math.h>
# include "Fixed.hpp"

class point
{
	private:
		fixed const _x;
		fixed const _y;
	public:
		point(void);
		point(const float x, const float y);
		point(const point& copy);
		~point();
		
		point& operator= (const point& copy);
		fixed const getx(void) const;
		fixed const gety(void) const;
};

bool	bsp(point const a, point const b, point const c, point const point);

#endif