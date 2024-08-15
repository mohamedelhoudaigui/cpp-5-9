/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 09:06:44 by mel-houd          #+#    #+#             */
/*   Updated: 2024/08/15 09:32:03 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &other);
		~Intern();
		Intern &operator=(Intern const &i);

		AForm *makeForm(std::string name, std::string target);

		class FormNotFoundException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

#endif