/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 09:42:10 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/02 11:14:56 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

point::point(void):_x(0), _y(0){};
point::point(const float x, const float y):_x(x), _y(y){};
point::point(const point& copy):_x(copy._x), _y(copy._y){};
point::~point(){};

point& point::operator= (const point& copy)
{
	(fixed)this->_x = copy.getx();
	(fixed)this->_y = copy.gety();
	return (*this);
};

fixed const point::getx(void) const{return(this->_x);};
fixed const point::gety(void) const{return(this->_y);};
