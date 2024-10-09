/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 21:30:31 by mel-houd          #+#    #+#             */
/*   Updated: 2024/10/09 23:21:13 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	this->Types[0] = "robotomy request";
	this->Types[1] = "shrubbery request";
	this->Types[2] = "presidential request";

}

Intern::Intern( const Intern & src )
{
	*this = src;
}

Intern::~Intern()
{
}

Intern&	Intern::operator=( Intern const & src )
{
	(void)src;
	return *this;
}

AForm*	MakeRobo(std::string Target) {
	return (new RobotomyRequestForm(Target));
}

AForm*	MakeShru(std::string Target) {
	return (new ShrubberyCreationForm(Target));
}

AForm*	MakePres(std::string Target) {
	return (new PresidentialPardonForm(Target));
}

AForm*	Intern::makeForm(std::string FormName, std::string Target) {
	AForm*	(*AllForms[])(std::string target) = {&MakeRobo, &MakeShru, &MakePres};
	for (int i = 0; i < 3; i++) {
		if (FormName == Types[i])
			return (AllForms[i](Target));
	}
	std::cout << "Intern cannot create form " << FormName << '\n';
	return NULL;
}
