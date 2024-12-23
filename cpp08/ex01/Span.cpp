/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:15:24 by mel-houd          #+#    #+#             */
/*   Updated: 2024/11/24 14:37:20 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


Span::Span(): c(0)
{}

Span::~Span()
{}

Span::Span(unsigned int N): c(N)
{}

Span::Span(const Span& other)
{
	*this = other;
}

Span&	Span::operator=(const Span& other)
{
	this->c = other.getCapacity();
	std::vector<int> tmp(other.getSpan());
	this->span = tmp;
	return (*this);
}

unsigned int Span::getCapacity() const
{
	return (this->c);	
}

const std::vector<int>&	Span::getSpan() const
{
	return (this->span);
}

void	Span::addNumber(int number)
{
	if (span.size() >= c)
		throw std::runtime_error("size of span exeeded");
	this->span.push_back(number);
}

int		Span::longestSpan()
{
	if (span.size() <= 1)
		throw std::runtime_error("no enough elements in the span");
	std::vector<int> tmp(span);
	sort(tmp.begin(), tmp.end());
	return (tmp.back() - *tmp.begin());
}

int Span::shortestSpan()
{
    if (span.size() <= 1)
        throw std::runtime_error("no enough elements in the span");

    std::vector<int> tmp(span);
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