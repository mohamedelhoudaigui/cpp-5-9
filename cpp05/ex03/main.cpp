/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 21:30:39 by mel-houd          #+#    #+#             */
/*   Updated: 2024/10/09 21:30:40 by mel-houd         ###   ########.fr       */
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
