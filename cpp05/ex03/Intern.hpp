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
		AForm*		Pointers[3];
};


#endif