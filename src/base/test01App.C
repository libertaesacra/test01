#include "test01App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
test01App::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy DirichletBC, that is, set DirichletBC default for preset = true
  params.set<bool>("use_legacy_dirichlet_bc") = false;

  return params;
}

test01App::test01App(InputParameters parameters) : MooseApp(parameters)
{
  test01App::registerAll(_factory, _action_factory, _syntax);
}

test01App::~test01App() {}

void
test01App::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"test01App"});
  Registry::registerActionsTo(af, {"test01App"});

  /* register custom execute flags, action syntax, etc. here */
}

void
test01App::registerApps()
{
  registerApp(test01App);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
test01App__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  test01App::registerAll(f, af, s);
}
extern "C" void
test01App__registerApps()
{
  test01App::registerApps();
}
