# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    scripts.feature                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/28 13:46:02 by ingonzal          #+#    #+#              #
#    Updated: 2022/09/28 13:46:06 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Feature: QA technical test 28/08

	Scenario:  Open credentials file and get user and pass

	Background:
		Given The user tries to connect to the site

	Scenario:  Given credentials get the authorization token

	Scenario:  Conect to API with token

	Scenario: Parse result and get the preselected url

	Scenario: Decode the redirected url and get the key

	Scenario Outline: Run all scripts and compare the results
