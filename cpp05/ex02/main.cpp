/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 21:29:25 by mel-houd          #+#    #+#             */
/*   Updated: 2024/10/09 21:29:27 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


int	main() {
	Bureaucrat				a("test", 1);
	AForm*					b = new ShrubberyCreationForm(a.GetName());
	PresidentialPardonForm	c(a.GetName());
	RobotomyRequestForm		d(a.GetName());

	try{
		a.signForm(*b);
		a.executeForm(*b);
	} catch (const std::exception& e) {
		std::cout << e.what() << '\n';
	}

	try{
		a.signForm(c);
		a.executeForm(c);
	} catch (const std::exception& e) {
		std::cout << e.what() << '\n';
	}

	try{
		a.signForm(d);
		a.executeForm(d);
	} catch (const std::exception& e) {
		std::cout << e.what() << '\n';
	}

	delete b;
}
