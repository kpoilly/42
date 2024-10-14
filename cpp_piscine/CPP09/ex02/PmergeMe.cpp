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
    if (n == 0) return 0;
    if (n == 1) return 1;
    return jacobsthal(n-1) + 2*jacobsthal(n-2);
}

void insert(std::deque<int>& arr, int left, int right) 
{
    for (int i = left + 1; i <= right; ++i) 
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void insert(std::vector<int>& arr, int left, int right) 
{
    for (int i = left + 1; i <= right; ++i) 
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void merge(std::deque<int>& arr, int left, int mid, int right) 
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::deque<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge(std::vector<int>& arr, int left, int mid, int right) 
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // tableaux temporaires
    std::vector<int> L(n1), R(n2);

    // Copier les données dans les tableaux temporaires L[] et R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Fusionner les tableaux temporaires en un seul
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j]) 
        {
            arr[k] = L[i];
            i++;
        } else 
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copier les éléments restants de L[], s'il en reste
    while (i < n1) 
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copier les éléments restants de R[], s'il en reste
    while (j < n2) 
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void slice(std::deque<int>& arr, int left, int right) 
{
  if (right - left <= 1) 
  {
    return;
  }

  int mid = std::min(left + jacobsthal((right - left) / 2), right - 1);
  slice(arr, left, mid);
  slice(arr, mid + 1, right);
  merge(arr, left, mid, right);
}

void slice(std::vector<int>& arr, int left, int right) 
{
  if (right - left <= 1) 
  {
    return; // Un seul élément ou déjà triée
  }

  int mid = std::min(left + jacobsthal((right - left) / 2), right - 1);
  slice(arr, left, mid);
  slice(arr, mid + 1, right);
  merge(arr, left, mid, right);
}

void sort(std::deque<int>& arr) 
{
    int n = arr.size();

    for (int i = 0; i < n - 1; i += 2) 
    {
        insert(arr, i, std::min(i+1, n-1));
    }
	slice(arr, 0, n-1);
}

void sort(std::vector<int>& arr) 
{
    int n = arr.size();

    // Tri des paires
    for (int i = 0; i < n - 1; i += 2) 
    {
        insert(arr, i, std::min(i+1, n-1));
    }
    // Merge recursif
	slice(arr, 0, n-1);
}
