/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:07:13 by kpoilly           #+#    #+#             */
/*   Updated: 2024/07/08 14:19:29 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <unistd.h>
# include <sys/time.h>
# include <sstream>
# include <string>
# include <vector>
# include <list>
# include <algorithm>

std::vector<int>	merginsSortVec(std::vector<int>& cont);
std::list<int>		merginsSortList(std::list<int>& cont);

#endif