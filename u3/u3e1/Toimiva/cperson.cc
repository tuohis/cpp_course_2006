#include "cperson.h"

#include <algorithm>
#include <new>
#include <cstdlib>
#include <cstring>

// You don't need to understand the contents of this file.
// It is only provided to allow testing of your wrapper.

struct CPerson {
  char *name;
  int age;
};

using std::abort;

CPerson *personConstruct(char const *name,
                        int age) try
  {
    if (name == NULL)
      throw 1;
    CPerson *retval = new CPerson;
    retval->name = new char[strlen(name) + 1];
    std::strcpy(retval->name, name);
    retval->age = age;
    return retval;
    
  } catch (...)
  {
    abort();
  }

CPerson *personCreateCopy(CPerson const *p)
{
  return personConstruct(p->name, p->age);
}

void personDestruct(CPerson *p)
{
  if (p == NULL)
    abort();
  delete[] p->name;
  delete p;
}

void personSetName(CPerson *p, char const *name) try
  {
    if (p == NULL)
      abort();
    delete[] p->name;
    p->name = new char[strlen(name) + 1];
    std::strcpy(p->name, name);
    
  } catch (...)
  {
    abort();
  }

char *personGetName(CPerson const *p)
{
  if (p == NULL)
    abort();
  return p->name;
}

void personSetAge(CPerson *p, int age)
{
  if (p == NULL)
    abort();
  p->age = age;
}

int personGetAge(CPerson const *p)
{
  if (p == NULL)
    abort();
  return p->age;
}

