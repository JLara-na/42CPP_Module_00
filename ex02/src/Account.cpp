/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <jlara-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 11:13:31 by jlara-na          #+#    #+#             */
/*   Updated: 2024/11/16 16:18:08 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "../inc/Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals= 0;

Account::Account( int initial_deposit ){
	_nbAccounts = getNbAccounts();
	_totalAmount = getTotalAmount() + initial_deposit;
	_totalNbDeposits = getNbDeposits();
	_totalNbWithdrawals = getNbWithdrawals();

	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbAccounts++;
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";amount:" << initial_deposit
				<< ";created"
				<< std::endl;
}
Account::~Account(){
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";closed"
				<< std::endl; 
}

int		Account::getNbAccounts( void ){return (_nbAccounts);}
int		Account::getTotalAmount( void ){return (_totalAmount);}
int		Account::getNbDeposits( void ){return (_totalNbDeposits);}
int		Account::getNbWithdrawals( void ){return (_totalNbWithdrawals);}
void	Account::displayAccountsInfos( void ){
	_displayTimestamp();
	std::cout	<< "accounts:" << _nbAccounts
				<< ";total:" << _totalAmount
				<< ";deposits:" << _totalNbDeposits
				<< ";withdrawals:" << _totalNbWithdrawals
				<< std::endl;
}

void	Account::makeDeposit( int deposit ){
	if (deposit <= 0)
		return ;
	_displayTimestamp();
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout	<< "index:" << _accountIndex
				<< ";p_amount:" << _amount
				<< ";deposit:" << deposit
				<< ";amount:" << _amount + deposit
				<< ";nb_deposits:" << _nbDeposits
				<< std::endl;
	_amount += deposit;
	_totalAmount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal ){
	_displayTimestamp();
	if (withdrawal > _amount)
	{
		std::cout	<< "index:" << _accountIndex
					<< ";p_amount:" << _amount
					<< ";withdrawal:refused"
					<< std::endl;
		return (false);
	}
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout	<< "index:" << _accountIndex
				<< ";p_amount:" << _amount
				<< ";withdrawal:" << withdrawal
				<< ";amount:" << _amount - withdrawal
				<< ";nb_withdrawals:" << _nbWithdrawals
				<< std::endl;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	return(true);
}

int		Account::checkAmount( void )const{return(_amount);}

void	Account::displayStatus( void )const{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";deposits:" << _nbDeposits
				<< ";withdrawals:" << _nbWithdrawals
				<< std::endl;
}

void	Account::_displayTimestamp( void ){
	std::time_t		now = time(NULL);
    std::tm			tstruct;
    char			buf[80];

	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", &tstruct);
	std::cout << "[" << buf << "] ";
}