/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 21:30:18 by mel-houd          #+#    #+#             */
/*   Updated: 2024/10/09 21:30:20 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>


class Bureaucrat;

class AForm
{

	public:

		AForm();
		AForm(std::string Name, int GSign, int GExec);
		AForm( AForm const & src );
		virtual ~AForm();
		AForm &		operator=( AForm const & src );

		std::string		GetName()	const;
		bool			GetStatus()	const;
		int				GetGSign()	const;
		int				GetGExec()	const;
		void			beSigned(const Bureaucrat& b);
		virtual void	execute(Bureaucrat const & executor) const = 0; 

		class GradeTooLowException : public std::exception {
			const char* what() const throw();
		};

		class GradeTooHighException : public std::exception {
			const char* what() const throw();
		};

	private:
		const std::string	Name;
		const int			GSign;
		const int			GExec;
		bool				Signed;

};

std::ostream&			operator<<( std::ostream & o, AForm const & i );

#endif