/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 09:06:42 by mel-houd          #+#    #+#             */
/*   Updated: 2024/08/15 09:51:14 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(Intern const &i)
{
	(void)i;
	return (*this);
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string	forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm		*gg[3] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};
	int			i;
	int			index;

	for (i = 0; i < 3; i++)
	{
		if (forms[i] != name)
			delete gg[i];
		else
			index = i;
	}
	if (index < 3)
	{
		std::cout << "Intern creates " << name << "\n";
		return (gg[index]);
	}
	std::cout << "Intern can't create " << name << "\n";
	throw Intern::FormNotFoundException();
	return (NULL);
}


const char *Intern::FormNotFoundException::what() const throw()
{
	return ("Form not found!");
}