/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:56:03 by malbrand          #+#    #+#             */
/*   Updated: 2023/03/28 21:47:52 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/******************************************************************************/
/*                            CONSTRUCTOR                                     */
/******************************************************************************/
PmergeMe::PmergeMe(void)
{
	return ;
}

PmergeMe::PmergeMe(const PmergeMe &rhs)
{
	*this = rhs;
	return ;
}

/******************************************************************************/
/*                            DESTRUCTOR                                      */
/******************************************************************************/

PmergeMe::~PmergeMe(void)
{
	return ;
}

/******************************************************************************/
/*                        OPERATOR OVERLOAD                                   */
/******************************************************************************/
PmergeMe	&PmergeMe::operator=(const PmergeMe &rhs)
{
	this->_vector = rhs._vector;
	this->_deque = rhs._deque;
	return (*this);
}

/******************************************************************************/
/*                                FONCTION                                    */
/******************************************************************************/

void	isNum(char *av)
{
	std::string	s = av;

	if (s.find_first_not_of("0123456789") != std::string::npos)
		throw "Error: only positive number.";
	if (s.length() > 10 || (s.length() == 10 && s > "2147483647"))
		throw "Error: only integer.";
}

/******************************************************************************/
/*                          MEMBER FONCTION                                   */
/******************************************************************************/

void	PmergeMe::printDeque(void)
{
	int i = 0;
	for (std::deque<int>::iterator it = _deque.begin(); it < _deque.end(); it++)
	{
		if(++i > 4)
		{
			std::cout << " [...]";
			break;
		}
		std::cout << " " << *it;
	}
	std::cout << std::endl;

}

void	PmergeMe::printVector(void)
{
	int i = 0;
	for (std::vector<int>::iterator it = _vector.begin(); it < _vector.end(); it++)
	{
		if(++i > 4)
		{
			std::cout << " [...]";
			break;
		}
		std::cout << " " << *it;
	}
	std::cout << std::endl;
}

void	PmergeMe::ftSort(int ac, char **av)
{
	int	nb;

	for (int i = 1; av[i]; i++)
	{
		isNum(av[i]);
		std::istringstream(av[i]) >> nb;
		_vector.push_back(nb);
		_deque.push_back(nb);
	}
	std::cout << "Before: ";
	printVector();

/********************************************************************************/
/*                               VECTOR                                         */
/********************************************************************************/
	clock_t start = clock();
	mergeSort(_vector, 0, _vector.size() -1, 100);
	clock_t end = clock();
	double duration = double(end - start) / CLOCKS_PER_SEC * 1000;
	std::cout << "After: ";
	printVector();
    std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : " << duration << " ms" << std::endl;

/********************************************************************************/
/*                               DEQUE                                          */
/********************************************************************************/
	start = clock();
	mergeSort(_deque, 0, _deque.size() -1, 100);
	end = clock();
	duration = double(end - start) / CLOCKS_PER_SEC * 1000;
    std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque : " << duration << " ms" << std::endl;
}
