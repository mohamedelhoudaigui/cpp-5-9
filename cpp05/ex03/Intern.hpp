/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 21:30:34 by mel-houd          #+#    #+#             */
/*   Updated: 2024/10/09 23:21:10 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{

	public:

		Intern();
		Intern( Intern const & src );
		~Intern();
		Intern&	operator=( Intern const & src );
		AForm*	makeForm(std::string FormName, std::string Target);

	private:
		std::string	Types[3];
};

AForm*	MakeRobo(std::string Target);
AForm*	MakeShru(std::string Target);
AForm*	MakePres(std::string Target);

#endif