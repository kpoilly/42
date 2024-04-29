/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 07:45:53 by kpoilly           #+#    #+#             */
/*   Updated: 2024/04/29 09:26:38 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

Account::Account(void)
{
	this->_nbAccounts = 0;
	this->_totalAmount = 0;
	this->_totalNbDeposits = 0;
	this->_totalNbWithdrawals = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
};
Account::Account(int initial_deposit)
{
	this->_nbAccounts = 0;
	this->_totalAmount = 0;
	this->_totalNbDeposits = 0;
	this->_totalNbWithdrawals = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	makeDeposit(initial_deposit);
};
Account::~Account(void){};

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
};

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
};

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
};

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
};

void	Account::displayAccountsInfos(void)
{
	
};

void	Account::makeDeposit(int deposit)
{
	this->_totalAmount += deposit;
	this->_totalNbDeposits++;
	this->_amount = deposit;
	this->_nbDeposits++;
	
};

bool	Account::makeWithdrawal(int withdrawal)
{
	if (this->_totalAmount - withdrawal < 0)
		return (false);
		
	this->_totalAmount -= withdrawal;
	this->_totalNbWithdrawals++;
	this->_nbWithdrawals++;
	this->_amount = withdrawal;
	return (true);
};

int		Account::checkAmount(void) const
{
	return (_amount);
};

void	Account::displayStatus(void) const
{
	
};
static void	_displayTimestamp(void)
{
	
};
