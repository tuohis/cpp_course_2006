#ifndef CPERSON_H
#define CPERSON_H

typedef struct CPerson CPerson; 

#ifdef __cplusplus

extern "C" {

#endif

  // The functions declared in these file call abort()
  // if something unexpected happens.


  // This function creates a new person with
  // a certain name and age.
  //
  // The contents of the name pointer are copied in to
  // the return value.
  // 
  // Preconditions:
  // - name points to a valid C string.
  // Returns:
  // - A pointer to the created person. The user of
  //   this ADT must call the destruct function to the returned pointer
  //   when it is no longer required
  CPerson *personConstruct(char const *name,
			int age);

  
  // This function creates a copy of a person.
  //
  // Preconditions:
  // - p is a pointer to a valid instance of CPerson
  // Returns:
  // - A pointer to a instance of CPerson which has
  //   the same name and age as the person given as argument.
  CPerson *personCreateCopy(CPerson const *p);

  // This function frees all memory allocated to a person.
  //
  // Preconditions:
  // - p is a pointer to a valid instance of CPerson.
  // Postconditions:
  // - p no longer points to a valid instance of CPerson.
  // - All the memory associated with p is freed.
  void personDestruct(CPerson *p);
  
  // This functions changes the name of a person
  //
  // Preconditions:
  // - p is a pointer to a valid instance of CPerson
  // - name is a pointer to a valid C string.
  // Postconditions:
  // - personGetName(p) has the same contents as the "name" parameter
  //   given to the function
  void personSetName(CPerson *p, char const *name);


  // This functions returns a pointer to the C string which
  // contains the name of the person.
  //
  // Preconditions:
  // - p is a pointer to a valid instance of CPerson
  // Returns:
  // - A pointer to a valid C string which contains the name of the person
  char *personGetName(CPerson const *p);

  // This functions returns the age of a person
  //
  // Preconditions:
  // - p is a pointer to a valid instance of CPerson
  // Returns:
  // - The age of the person
  int personGetAge(CPerson const *p);

  // This functions changes the age of a person
  //
  // Preconditions:
  // - p is a pointer to a valid instance of CPerson
  // Postconditions:
  // - The age of the person equals to the age given as parameter.
  void personSetAge(CPerson *p, int age);
  
  
#ifdef __cplusplus

}

#endif

#endif
