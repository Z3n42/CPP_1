# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    steps.py                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/21 14:22:47 by ingonzal          #+#    #+#              #
#    Updated: 2022/08/22 18:10:42 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from behave import *
from script import *
from hamcrest import *
from argparse import Namespace
from sys import *

@given ('The user tries to connect to the site')
def step_conect(context):
    """
    BACKGROUND
    """
    assert_that(str(connect()), equal_to("<Response [200]>"))

@given ('The user is searching who is the owner')
def step_impl(context):
    data = connect().json()
    args = Namespace(name=None, type=None, language=None, owner=['PRISA'], website=None, country=None)
    context.parser = Qa(data, args, None)
    # assert_that(1, equal_to(1))
    # pass

@when ('The user searches for the newspapers owned by {arg}, the response {ans} is returned')
def step_impl(context, arg, ans):
    context.parser.args.owner = arg 
    assert context.parser.args.owner

@then ('the parser return the newspapers organized by owner')
def step_impl(context):
    assert context.parser.select_flag() == context.ret
