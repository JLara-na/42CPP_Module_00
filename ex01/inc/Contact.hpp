/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <jlara-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:57:08 by jlara-na          #+#    #+#             */
/*   Updated: 2024/11/15 23:23:00 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <stdlib.h>
# include "PhoneBook.hpp"

typedef enum e_fields
{
	NAME,
	LAST_NAME,
	NICKNAME,
	PHONE_NUMBER,
	SECRET
}	t_fields;

class Contact
{
    private:
        std::string fields[5];
    public:
        Contact();
        ~Contact();

        void        set_field(int field_nb, std::string data);
        std::string get_field(int field_nb);
};
