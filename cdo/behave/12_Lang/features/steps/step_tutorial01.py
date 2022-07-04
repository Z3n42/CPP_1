# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    step_tutorial01.py                                 :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/03 14:01:40 by ingonzal          #+#    #+#              #
#    Updated: 2022/07/03 14:07:11 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# file:features/steps/step_tutorial01.py
# ----------------------------------------------------------------------------
# STEPS:
# ----------------------------------------------------------------------------
from behave import given, when, then

@given('we have behave installed')
def step_impl(context):
    pass

@when('we implement a test')
def step_impl(context):
    assert True is not False

@then('behave will test it for us!')
def step_impl(context):
    assert context.failed is False

@given('wir haben "behave" installiert')
def step_impl(context):
    context.execute_steps(u"Angenommen we have behave installed")

@when('wir einen Test implementieren')
def step_impl(context):
    context.execute_steps(u"Wenn we implement a test")

@then('wird "behave" ihn für uns testen!')
def step_impl(context):
    context.execute_steps(u'Dann behave will test it for us!')
