/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:52:45 by malbrand          #+#    #+#             */
/*   Updated: 2023/03/28 22:05:37 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# include <deque>
#include <ctime>
# include <vector>
# include <sstream>
# include <iostream>

class PmergeMe
{
	private :
				std::vector<int>	_vector;
				std::deque<int>		_deque;

	public :
/******************************************************************************/
/*                            CONSTRUCTOR                                     */
/******************************************************************************/
				PmergeMe(void);
				PmergeMe(const PmergeMe &rhs);
/******************************************************************************/
/*                            DESTRUCTOR                                      */
/******************************************************************************/
				virtual~PmergeMe(void);
/******************************************************************************/
/*                        OPERATOR OVERLOAD                                   */
/******************************************************************************/
				PmergeMe &operator=(const PmergeMe &rhs);
/******************************************************************************/
/*                          MEMBER FONCTION                                   */
/******************************************************************************/
				void	printDeque(void);
				void	printVector(void);
				void	ftSort(int ac, char **av);

template< typename T >
	void	insertionSort(T & container, int l, int r)
	{
		for (int i = l + 1; i <= r; i++)
		{
        	int key = container[i];
        	int j = i - 1;
        	while (j >= l && container[j] > key)
			{
            	container[j + 1] = container[j];
            	j--;
			}
        	container[j + 1] = key;
		}
	}

template<typename T>
	void merge(T & container, int l, int m, int r)
	{
    	int n1 = m - l + 1;
    	int n2 = r - m;

    	T L(n1);
    	T R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = container[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = container[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
	{
        if (L[i] <= R[j])
		{
            container[k] = L[i];
            i++;
        }
        else
		{
            container[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        container[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
	{
        container[k] = R[j];
        j++;
        k++;
    }
}

template<typename T>
	void mergeSort(T &container, int l, int r, int k)
{
    if (l < r)
	{
        if (r - l + 1 <= k)
		{
            insertionSort(container, l, r);
            return;
		}
        int m = l + (r - l) / 2;

        mergeSort(container, l, m, k);
        mergeSort(container, m + 1, r, k);
        merge(container, l, m, r);
    }
}
};
#endif
