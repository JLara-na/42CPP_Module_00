/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <jlara-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:30:44 by jlara-na          #+#    #+#             */
/*   Updated: 2024/11/16 01:01:18 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"
#include "../inc/ansi_defines.h"

//Phonebook functions
PhoneBook::PhoneBook(){_contact_nb = 0;}
PhoneBook::~PhoneBook(){}

void PhoneBook::error(std::string state){
	std::cout << state << std::endl;
	exit(0);
}

void PhoneBook::add_contact(){
	std::string	fields[] = {"Name: ", "Last name: ", "Nickname: ", "Phone number: ", "Secret: "};
	std::string	aux;
	Contact	*Contact = &_agenda[_contact_nb % 8];

	std::cout << "Adding contact:" << std::endl;
	for (int i = 0; i < 5; i++){
		std::cout << fields[i];
			while (true){
				std::getline(std::cin, aux);
				if (std::cin.eof())
					error(RED "EOF" DEFAULT_SGR);
				if (i == PHONE_NUMBER)
				{
					if (aux.length() == 9 && aux.find_first_not_of("0123456789") == std::string::npos){
				    	Contact->set_field(i, aux);
				    	break ;
			    	}
			    	else {
				    	std::cout << RED_B "Phone numbers of 9 digits only" DEFAULT_SGR << std::endl;
				    	std::cout << fields[i];
				    }
				}
				else {
					if (aux.length() > 0){
				    	Contact->set_field(i, aux);
				    	break ;
			    	}
			    	else {
				    	std::cout << RED_B << "Field " << fields[i] << "cannot be empty" << DEFAULT_SGR << std::endl;
				    	std::cout << fields[i];
				    }
				}
		}
	}
	std::cout << GREEN_B << "Contact added at index = " << _contact_nb % 8 << DEFAULT_SGR << std::endl;
	_contact_nb++;
}

std::string PhoneBook::_crop_name(std::string name){
	std::string aux = name.substr(0, 10);
	if (name.length() > 10)
		aux = name.substr(0, 9) + '.';
	else
		aux = name.substr(0, 10);
	if (aux.length() <= 9)
		aux = std::string(10 - aux.length(), ' ') + aux;
	return (aux);
}

void PhoneBook::search_contact(){
	std::string	fields[] = {"Name: ", "Last name: ", "Nickname: ", "Phone number: ", "Secret: "};
	std::string input;
	
	std::cout << CYAN << "╔══════════╦══════════╦══════════╦══════════╗" << DEFAULT_SGR << std::endl;
	std::cout << CYAN << "║   INDEX  ║   NAME   ║  L NAME  ║ NICKNAME ║" << DEFAULT_SGR << std::endl;
	std::cout << CYAN << "╠══════════╩══════════╩══════════╩══════════╣" << DEFAULT_SGR << std::endl;
	for (int i = 0; i < 8; i++){
		std::cout << CYAN << "║" + std::string(9, ' ') << i << "|" << _crop_name(_agenda[i].get_field(NAME))
		<< "|" << _crop_name(_agenda[i].get_field(LAST_NAME)) << "|" << _crop_name(_agenda[i].get_field(NICKNAME))
		<< "║" << DEFAULT_SGR << std::endl;
	}
	std::cout << CYAN << "╚═══════════════════════════════════════════╝" << DEFAULT_SGR << std::endl;
	std::cout << BLUE << "Insert the INDEX from wich you want to retrieve data: " << DEFAULT_SGR;
	while (true){
		std::getline(std::cin, input);
		if (std::cin.eof())
			error(RED "EOF" DEFAULT_SGR);
		if (input.length() > 0 && input.find_first_not_of("0123456789") == std::string::npos && (std::atoi(input.c_str()) >= 0) && std::atoi(input.c_str()) <= 7)
			break ;
		else {
			std::cout << RED_B "Your input must be a number between 0 and 7" DEFAULT_SGR << std::endl;
			std::cout << BLUE << "Insert the INDEX from wich you want to retrieve data: " << DEFAULT_SGR;
		}
	}
	for (int i = 0; i < 5; i++){
		std::cout << CYAN << fields[i] << DEFAULT_SGR; 
		std::cout << _agenda[std::atoi(input.c_str())].get_field(i) << std::endl; 
	}
}

//Contact functions
Contact::Contact(){}
Contact::~Contact(){}
void Contact::set_field(int field_nb, std::string data){fields[field_nb] = data;}
std::string Contact::get_field(int field_nb){return (fields[field_nb]);}

void process_input(std::string input, PhoneBook *Book)
{
	if (std::cin.eof())
		Book->error(RED "EOF" DEFAULT_SGR);
	else if (input == "ADD" || input == "A")
		Book->add_contact();
	else if (input == "SEARCH" || input == "S")
		Book->search_contact();
	else if (input == "EXIT" || input == "E")
		Book->error(GREEN "Exit program, Bye!" DEFAULT_SGR);
	else
		std::cout << RED << input + ": command not found" << DEFAULT_SGR << std::endl;
}

int	main(int ac, char **av)
{
	std::string	Input;
	PhoneBook	Book;
	
	(void)ac;
	(void)av;
	while (true)
	{
		std::cout << CUSTOM_208 "Comands: " GREEN "ADD(A), " MAGENTA "SEARCH(S), " RED "EXIT(E) " << DEFAULT_SGR << std::endl;
		std::getline(std::cin, Input);
		process_input(Input, &Book);
	}
}

