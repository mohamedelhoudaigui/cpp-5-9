/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theworld27 <theworld27@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 03:59:16 by mel-houd          #+#    #+#             */
/*   Updated: 2024/10/09 15:46:47 by theworld27       ###   ########.fr       */
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