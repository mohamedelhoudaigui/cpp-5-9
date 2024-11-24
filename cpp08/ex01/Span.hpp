/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:09:53 by mel-houd          #+#    #+#             */
/*   Updated: 2024/11/24 00:41:34 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iostream>

class Span
{
	public:
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void	addNumber(int number);
		int		shortestSpan();
		int		longestSpan();

		unsigned int			getCapacity()	const;
		const std::vector<int>&	getSpan()	const;

		template<typename Iter>
		void	addNumbers(Iter begin, Iter end)
		{
			if (std::distance(begin, end) + span.size() > c)
            	throw std::runtime_error("size of span exceeded");

			span.insert(span.end(), begin, end);
		}

	private:
		std::vector<int>	span;
		unsigned int		c;
};

#endif