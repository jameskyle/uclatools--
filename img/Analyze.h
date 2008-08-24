#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include <vector>
#include <stdexcept>
#include <exception>

namespace uctImage {
  using std::string;
  /**
   * Analyze file class
   *
   * The uctAnalyze file class takes an anlyze image, parses the header and 
   * stores this information including image data. Accessors are provided for
   * all fields declared in the Mayo/SPM  format specification.
   */
  class uctAnalyze {
    public:
      /**
       * Constructor for the uctAnalyze class.
       *
       * Parses the analyze header file and stores appropriate information in 
       * class variables.
       */
      uctAnalyze(const std::string filename);

      /** 
       * Destructor for the uctAnalyze class
       */
      ~uctAnalyze();
      /**
       * Returns a pointer to the sizeof_hdr value
       */
      const int* getSizeof_hdr() const {return &this->sizeof_hdr;}
      
      /**
       * Returns the address to the data_type string
       */
      const std::string* getDataType() const {return &this->data_type;}
      
      /**
       * Returns the address to the db_name string
       */
      const std::string* getDbName() const {return &this->db_name;}
      
      /**
       * Returns address of the extents value
       */
      const int* getExtents() const {return &this->extents;}
      /**
       * Returns address of the session_error value
       */
      const short* getSessionError() const {return &this->session_error;}
      /**
       * Returns address of the regular value
       */
      const char* getRegular() const {return &this->regular;}
      
      /**
       * Returns address of the regular value
       */
      const char* getHkey_un0() const {return &this->hkey_un0;}

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
      int sizeof_hdr; /**< the size of the header. OS: 1 **/
      std::string data_type; /**< declares the type of image data in .img. Retains padding  **/
      std::string db_name; /**< name file is stored under in the image db **/
      /**
       * should be 16384, image is created as continguous with a minimum 
       */
      int extents; 
      short session_error; /**< Session Error value **/
      char regular;
      char hkey_un0; 
      std::vector<short> dimensions;
      
      std::string filename; /**< Filename for analyze header file **/
  };
}

