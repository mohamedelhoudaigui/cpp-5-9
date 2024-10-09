/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 01:05:20 by mel-houd          #+#    #+#             */
/*   Updated: 2024/10/08 04:21:23 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"


int	main() {
	Bureaucrat	a("test", 130);
	Form		AForm("AForm", 1, 1);
	Form		BForm(AForm);
	Form		CForm = BForm;
	
	std::cout << AForm << '\n';
	std::cout << BForm << '\n';
	std::cout << CForm << '\n';

	try {
		Form	DForm("", -1, 149);
	} catch (const std::exception& e) {
		std::cout << e.what() << '\n';
	}

	try {
		Form	DForm("", 1, 155);
	} catch (const std::exception& e) {
		std::cout << e.what() << '\n';
	}

	try {
		Form	DForm("DForm", 1, 155);
		Bureaucrat	b("test", 130);

		b.signForm(DForm);

	} catch (const std::exception& e) {
		std::cout << e.what() << '\n';
	}

	try {
		Form	DForm("DForm", 1, 1);
		Bureaucrat	b("test", 130);

		b.signForm(DForm);

	} catch (const std::exception& e) {
		std::cout << e.what() << '\n';
	}

	
}