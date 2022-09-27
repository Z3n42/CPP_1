# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    steps.py                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/21 14:22:47 by ingonzal          #+#    #+#              #
#    Updated: 2022/09/27 17:56:38 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from behave import *
from script2 import *
from hamcrest import *
from argparse import Namespace
from sys import *

#Background
@given ('The user tries to connect to the site')
def step_conect(context):
    """
    BACKGROUND
    """
    assert_that(str(connect()), equal_to("<Response [200]>"))

#Name Flag
@given ('The user is searching all information about a specific user')
def step_impl(context):
    data = connect().json()
    args = Namespace(name=[" "], id=None, email=None, gender=None, status=None)
    context.parser = Qa(data, args, None)
    assert (context.parser.args.name)

@when ('The user searches for a user named as "{arg}"')
def step_impl(context, arg):
    data = connect().json()
    context.parser.args.name = arg
    ret = context.parser.select_flag()
    assert_that(context.parser.args.name, equal_to(arg))

@then ('all the info "{answer}" is returned')
def step_impl(context, answer):
    assert_that(str(context.parser.ret), equal_to(answer))

#id Flag
@given ('The user is searching a list of users by id')
def step_impl(context):
    data = connect().json()
    args = Namespace(name=None, id=[" "], email=None, gender=None, status=None)
    context.parser = Qa(data, args, None)
    assert (context.parser.args.id)

@when ('The user searches for the user id "{arg}"')
def step_impl(context, arg):
    data = connect().json()
    context.parser.args.type = arg
    ret = context.parser.select_flag()
    assert_that(context.parser.args.type, equal_to(arg))

@then ('the "{answer}" is returned')
def step_impl(context, answer):
    assert_that(str(context.parser.ret), equal_to(answer))

#Language Flag
@given ('The user is searching a list of newapapers by language')
def step_impl(context):
    data = connect().json()
    args = Namespace(name=None, id=None, email=[" "], gender=None, status=None)
    context.parser = Qa(data, args, None)
    assert (context.parser.args.email)

@when ('The user searches for the newspapers written in "{arg}"')
def step_impl(context, arg):
    data = connect().json()
    context.parser.args.language = arg
    ret = context.parser.select_flag()
    assert_that(context.parser.args.language, equal_to(arg))

@then ('the list "{answer}" grouped by lenguage is returned')
def step_impl(context, answer):
    ret = answer.split(",")
    assert_that(context.parser.ret, equal_to(ret))

#Owner Flag
@given ('The user is searching who is the owner')
def step_impl(context):
    data = connect().json()
    args = Namespace(name=None, id=None, email=None, gender=[" "], status=None)
    context.parser = Qa(data, args, None)
    assert (context.parser.args.gender)

@when ('The user searches for the newspapers owned by "{arg}"')
def step_impl(context, arg):
    data = connect().json()
    context.parser.args.owner = arg
    ret = context.parser.select_flag()
    assert_that(context.parser.args.owner, equal_to(arg))

@then ('the response "{answer}" is returned')
def step_impl(context, answer):
    ret = answer.split(",")
    assert_that(context.parser.ret[0], equal_to(ret[0]))
'''
#Website Flag
@given ('The user wants connect to Newspaper´s Website')
def step_impl(context):
    data = connect().json()
    args = Namespace(name=None, type=None, language=None, owner=None, website=[" "], country=None)
    context.parser = Qa(data, args, None)
    assert (context.parser.args.website)

@when ('The user searches "{arg}" website')
def step_impl(context, arg):
    data = connect().json()
    context.parser.args.website = arg
    ret = context.parser.select_flag()
    assert_that(context.parser.args.website, equal_to(arg))

@then ('the website title is "{answer}"')
def step_impl(context, answer):
    assert_that(str(context.parser.ret), equal_to(answer))
'''
#Country Flag
@given ('The user is searching a list of newapapers by country')
def step_impl(context):
    data = connect().json()
    args = Namespace(name=None, id=None, email=None, gender=None, status=[" "])
    context.parser = Qa(data, args, None)
    assert (context.parser.args.status)

@when ('The user searches for the newspapers published at "{arg}"')
def step_impl(context, arg):
    data = connect().json()
    context.parser.args.country = arg
    ret = context.parser.select_flag()
    assert_that(context.parser.args.country, equal_to(arg))

@then ('the newspapers list is "{answer}"')
def step_impl(context, answer):
    ret = answer.split(",")
    assert_that(context.parser.ret, equal_to(ret))
