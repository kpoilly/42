/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:08:39 by marvin            #+#    #+#             */
/*   Updated: 2024/10/12 17:08:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int jacobsthal(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

void merge(std::deque<int>& arr, int left, int mid, int right)
{
    std::deque<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) 
        temp[k++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    std::copy(temp.begin(), temp.end(), arr.begin() + left);
}

void merge_insert_sort(std::deque<int>& arr, int left, int right) 
{
    if (right - left <= 3)
        std::sort(arr.begin(), arr.end());
    else
    {
        int mid = left + (right - left) / 2;
        merge_insert_sort(arr, left, mid);
        merge_insert_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void merge(std::vector<int>& arr, int left, int mid, int right)
{
    std::vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) 
        temp[k++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    std::copy(temp.begin(), temp.end(), arr.begin() + left);
}

void merge_insert_sort(std::vector<int>& arr, int left, int right) 
{
    if (right - left <= 3)
        std::sort(arr.begin(), arr.end());
    else
    {
        int mid = left + (right - left) / 2;
        merge_insert_sort(arr, left, mid);
        merge_insert_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
