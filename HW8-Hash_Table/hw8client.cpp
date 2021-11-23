// CS311 Yoshii - complete ** for HW8 client
// Note that the client knows about elem.h functions.
// It can create el_t objects.
//-----------------------------------------------

//============================================
// HW#: HW8 hashing client
// Name: **
// File type: client hw8client.cpp (tester)
//===========================================

using namespace std;
#include "htable.h"

// This tester gets input data interactively but
// for a useful client, input should come from a file.
// Note that el_t X; will create a blank element X using the regular constructor.  
// Note that the second constructor of el_t can be used to
// create key+name to add to the table. e.g. el_t X(30, "mary");
int main()
{ **
 Loop:  
   Interactively add about 20 keys and names to the table,
     making sure some of them  collide. (function add)
     You can create el_t containing a key and name using a constructor.
 DisplayTable.
 Loop:
  Interactively look up names using keys. (function find)
    Cout the key + name if found else (blank element was returned)
    an error message. 
 }
