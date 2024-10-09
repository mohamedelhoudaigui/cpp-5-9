/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 01:05:20 by mel-houd          #+#    #+#             */
/*   Updated: 2024/10/08 04:22:00 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


int	main() {
	Bureaucrat	a("test", 1);
	Bureaucrat	e("test", 150);
	Bureaucrat	b(a);
	Bureaucrat	c = a;

	std::cout << a << '\n';
	std::cout << b << '\n';
	std::cout << c << '\n';

	try {
		Bureaucrat d("test", -1);

	} catch (const std::exception& e) {
		std::cout << e.what() << '\n';
	}

	try {
		Bureaucrat d("test", 151);
	} catch (const std::exception& e) {
		std::cout << e.what() << '\n';
	}

	try {
		a.IncrGrade();
	} catch (const std::exception& e) {
		std::cout << e.what() << '\n';
	}

	try {
		e.DecrGrade();
	} catch (const std::exception& e) {
		std::cout << e.what() << '\n';
	}
}