/** @file gift.hh
 */
#ifndef GIFT_HH
#define GIFT_HH

#include <iostream>

/** Gift class. Gift has a name.
 */
class Gift
{
public:

  /** a constructor. Gives gift an initial name.
   *  @param name initial name of the gift
   */
  Gift(const char *name = NULL);

  /** Copy constructor.
   *  @param gift gift
   */
  Gift(const Gift& gift);

  /** a destructor that frees memory allocated by the gift (its name)
   */
  virtual ~Gift();

  /** Name of the gift
   *  @return pointer to name of the gift
   */
  const char *getName() const;

  /** Changes name for the gift.
   *  @param newName name to set
   */
  void setName(const char *newName);

  /** Assignment operator overloading function. Gifts may now be assigned
   *  to each other with no danger of shallow copying. Check for self
   *  assignment to avoid error in cases of "a = a;"
   *  @param otherGift gift whose data is copied to this gift
   */
  Gift& operator=(const Gift& otherGift);

  /** output stream operator, prints name of the gift to an output stream.
   *  Only the name. Nothing more.
   *  @param os   output stream
   *  @param gift gift to print
   *  @return os
   */
  friend std::ostream& operator<<(std::ostream& os, const Gift& gift);

  /** input stream operator, read a line from the input stream and assign it
   *  as a name for the gift. end-of-line character is ignored.
   *  @param is   input stream to read
   *  @param gift reference to gift where the name is stored
   *  @return is
   */
  friend std::istream& operator>>(std::istream& is, Gift& gift);

protected:

  // Yes. this should be std::string, but now it is char *
  // because this is an exercise about pointers.
  char *name; /**< name */
};

#endif /* ITEM_HH */
