/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:15:24 by mel-houd          #+#    #+#             */
/*   Updated: 2024/10/22 19:40:01 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


Span::Span(): _c(0)
{}

Span::~Span()
{}

Span::Span(unsigned int N): _c(N)
{}

Span::Span(const Span& other)
{
	*this = other;
}

Span&	Span::operator=(const Span& other)
{
	this->_c = other.getCapacity();
	std::vector<int> tmp(other.getSpan());
	this->_span = tmp;
	return (*this);
}

unsigned int Span::getCapacity() const
{
	return (this->_c);	
}

const std::vector<int>&	Span::getSpan() const
{
	return (this->_span);
}

// ----------------------------------


void	Span::addNumber(int number)
{
	if (_span.size() >= _c)
		throw std::runtime_error("size of span exeeded");
	_span.push_back(number);
}

int		Span::longestSpan() const
{
	if (_span.size() <= 1)
		throw std::runtime_error("no enough elements in the span");
	std::vector<int> tmp(_span);
	sort(tmp.begin(), tmp.end());
	return (tmp.back() - *tmp.begin());
}

int Span::shortestSpan() const
{
    if (_span.size() <= 1)
        throw std::runtime_error("no enough elements in the span");

    std::vector<int> tmp(_span);
    std::sort(tmp.begin(), tmp.end());

    int res = INT_MAX;
    for (int i = 1; i < tmp.size(); ++i)
    {
        int minSpan = tmp[i] - tmp[i - 1];
        if (minSpan < res)
            res = minSpan;
    }

    return (res);
}