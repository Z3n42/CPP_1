# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tutorial11_tags.feature                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/03 13:33:27 by ingonzal          #+#    #+#              #
#    Updated: 2022/07/03 13:34:13 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# file:features/tutorial11_tags.feature
@wip
Feature: Using Tags with Features and Scenarios (tutorial11 := tutorial2)

    In order to increase the ninja survival rate,
    As a ninja commander
    I want my ninjas to decide whether to take on an opponent
    based on their skill levels.

    @ninja.any
    Scenario: Weaker opponent
        Given the ninja has a third level black-belt
        When attacked by a samurai
        Then the ninja should engage the opponent

    @ninja.chuck
    Scenario: Stronger opponent
        Given the ninja has a third level black-belt
        When attacked by Chuck Norris
        Then the ninja should run for his life
