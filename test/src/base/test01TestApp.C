//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "test01TestApp.h"
#include "test01App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
test01TestApp::validParams()
{
  InputParameters params = test01App::validParams();
  return params;
}

test01TestApp::test01TestApp(InputParameters parameters) : MooseApp(parameters)
{
  test01TestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

test01TestApp::~test01TestApp() {}

void
test01TestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  test01App::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"test01TestApp"});
    Registry::registerActionsTo(af, {"test01TestApp"});
  }
}

void
test01TestApp::registerApps()
{
  registerApp(test01App);
  registerApp(test01TestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
test01TestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  test01TestApp::registerAll(f, af, s);
}
extern "C" void
test01TestApp__registerApps()
{
  test01TestApp::registerApps();
}
