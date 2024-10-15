/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:07:13 by kpoilly           #+#    #+#             */
/*   Updated: 2024/10/15 16:28:03 by kpoilly          ###   ########.fr       */
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

void merge_insert_sort(std::vector<int>& vec, int left, int right);
void merge_insert_sort(std::deque<int>& vec, int left, int right);

#endif