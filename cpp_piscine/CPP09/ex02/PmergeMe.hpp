/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:07:13 by kpoilly           #+#    #+#             */
/*   Updated: 2024/10/14 13:10:33 by kpoilly          ###   ########.fr       */
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
# include <deque>
# include <algorithm>

void sort(std::vector<int>& arr);
void sort(std::deque<int>& arr);

#endif