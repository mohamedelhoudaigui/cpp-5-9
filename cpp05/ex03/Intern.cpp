/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 21:30:31 by mel-houd          #+#    #+#             */
/*   Updated: 2024/10/09 21:30:32 by mel-houd         ###   ########.fr       */
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

Intern &				Intern::operator=( Intern const & src )
{
	(void)src;
	return *this;
}

AForm*	Intern::makeForm(std::string FormName, std::string Target) {
	this->Pointers[0] = new RobotomyRequestForm(Target);
	this->Pointers[1] = new ShrubberyCreationForm(Target);
	this->Pointers[2] = new PresidentialPardonForm(Target);

	int		i = 0;
	int		j = 0;
	AForm*	ret = NULL;

	for (i = 0; i < 3; i++) {
		if (Types[i] == FormName)
		{
			ret =  Pointers[i];
			break ;
		}
	}
	while (j < 3) {
		if (j != i)
			delete this->Pointers[j];
		j++;
	}
	return ret;
}
