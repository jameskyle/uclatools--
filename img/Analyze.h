#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include <stdexcept>
#include <exception>
#include <map>
#include <iomanip>
#include "dbh.h"

namespace UC {
  class Error {
    const char* const data;
    public:
      Error(const char* const msg = 0)  : data(msg) {}
      const char* what() const {return data;}
  };
  /**
   * Analyze file class
   *
   * The Analyze file class takes an anlyze image, parses the header and 
   * stores this information including image data. Accessors are provided for
   * all fields declared in the Mayo/SPM  format specification.
   */
  class Analyze {
    public:
      dsr hdr;
      /**
       * Constructor for the Analyze class.
       *
       * Parses the analyze header file and stores appropriate information in 
       * class variables.
       */
      Analyze(const std::string filename);
      
      /** 
       * Print formated header to stdout
       */
      void PrintHeader();
      /** 
       * Destructor for the Analyze class
       */
      ~Analyze();
      /** 
       * Place holder
       */

    private:
      /**
       * Function that reverses endianness of a 32bit character and assigns
       * result to passed *swapped pointer
       *
       * @pre pointer to a character array of bytes to be swapped and 
       * pointer to a valid int32 object passed
       * @post *swapped contains the value of the reversed bytes
       *
       */
      void shift32(const char* bytes, int *swapped);
      
      /**
       * Function that reverses endianness of a 16bit character and assigns
       * result to passed *swapped pointer
       *
       * @pre pointer to a character array of bytes to be swapped and 
       * pointer to a valid int16 object passed
       * @post *swapped contains the value of the reversed bytes
       *
       */
      void shift16(const char* bytes, short *swapped);
      
      /**
       * Place Holder
       */
      void populateHeaderFields();
     
      std::string filename; /**< Filename for analyze header file **/

    };

}

