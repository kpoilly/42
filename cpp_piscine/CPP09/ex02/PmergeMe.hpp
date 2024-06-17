/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:07:13 by kpoilly           #+#    #+#             */
/*   Updated: 2024/06/17 14:38:54 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sys/time.h>
# include <sstream>
# include <string>
# include <vector>
# include <list>
# include <algorithm>

void	merginsSort(std::vector<int>& cont);
void	merginsSort(std::list<int>& cont);

#endif