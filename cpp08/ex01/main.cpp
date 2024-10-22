/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:09:52 by mel-houd          #+#    #+#             */
/*   Updated: 2024/10/22 20:12:18 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span sp = Span(10);
	sp.addNumber(1);
	sp.addNumber(2);
	sp.addNumber(3);
	sp.addNumber(4);
	sp.addNumber(5);

	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;

	std::vector<int> a;
	for (int i = 6; i < 11; ++i)
		a.push_back(i);

	try
	{
		sp.addNumbers(a.begin(), a.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
		exit(1);
	}

	std::vector<int> s = sp.getSpan();
	for (int i = 0; i < s.size(); ++i)
		std::cout << s[i] << std::endl;

	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}