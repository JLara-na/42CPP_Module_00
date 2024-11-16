/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <jlara-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:31:25 by jlara-na          #+#    #+#             */
/*   Updated: 2024/11/15 23:24:20 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact		_agenda[8];
		int			_contact_nb;
		
		std::string	_crop_name(std::string name);
	public:
		PhoneBook();
		~PhoneBook();

		void		add_contact();
		void		search_contact();
		void		error(std::string str);
};
