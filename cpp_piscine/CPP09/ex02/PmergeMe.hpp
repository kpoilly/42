/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:07:13 by kpoilly           #+#    #+#             */
/*   Updated: 2024/06/19 13:59:30 by kpoilly          ###   ########.fr       */
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

void	merginsSort(std::vector<int>& cont);
void	merginsSort(std::list<int>& cont);

#endif