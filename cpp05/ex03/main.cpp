/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theworld27 <theworld27@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 01:05:20 by mel-houd          #+#    #+#             */
/*   Updated: 2024/10/09 18:12:09 by theworld27       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"


int	main() {
	Bureaucrat				a("test", 1);
	Intern					b;

	AForm*					f = b.makeForm("robotomy request", a.GetName());
	AForm*					e = b.makeForm("    ", a.GetName());

	std::cout << f << '\n';
	std::cout << e << '\n';

	delete f;
}
