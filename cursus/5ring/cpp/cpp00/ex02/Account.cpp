/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:46:51 by ingonzal          #+#    #+#             */
/*   Updated: 2022/04/20 18:50:34 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <ctime>
/* #include "Account.hpp" */

static int	Account::_nbAccounts = 0;
static int	Account::_totalAmount = 0;
static int	Account::_totalNbDeposits = 0;
static int	Account::_totalNbWithdrawals = 0;
int	Account::_accountIndex = 0;
int	Account::_amount = 0;
int	Account::_nbDeposits = 0;
int	Account_nbWithdrawals = 0;

static void Account::_displayTimestamp(void)
{
	time_t	rawtime;
	struct tm *timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);

    std::cout << "[" << 1900 + timeinfo->tm_year;
    std::cout << std::setfill('0') << std::setw(2) << 1 + timeinfo->tm_mon;
    std::cout << std::setfill('0') << std::setw(2) << timeinfo->tm_mday;
    std::cout << "_";
    std::cout << std::setfill('0') << std::setw(2) << timeinfo->tm_hour;
    std::cout << std::setfill('0') << std::setw(2) << timeinfo->tm_min;
    std::cout << std::setfill('0') << std::setw(2) << timeinfo->tm_sec << "] ";
}

static void Account::displayAccountsInfos(void)
{
	_displayTimestamp();


}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();

}

int		Account::checkAmount(void) const
{
	_displayTimestamp();

}

void	Account::displayStatus(void) const
{

}

Account::Account(int initial_deposit);

Account::~Account(void);
