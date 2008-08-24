#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include <vector>
#include <stdexcept>
#include <exception>

namespace img {
  /**
   * Header reader struct
   */
  template<typename T> union Reader { 
    int int32;
    char c;
    char c4[4];
    char c8[8];
    char c10[10];
    char c18[18];
    short int16;
    float f;
    char buf[sizeof(T)]; 
  };  //Reader<header> r; file.read(r.buf, sizeof(T));
  using std::string;
  /**
   * Analyze file class
   *
   * The Analyze file class takes an anlyze image, parses the header and 
   * stores this information including image data. Accessors are provided for
   * all fields declared in the Mayo/SPM  format specification.
   */
  class Analyze {
    public:
      /**
       * Constructor for the Analyze class.
       *
       * Parses the analyze header file and stores appropriate information in 
       * class variables.
       */
      Analyze(const std::string filename);

      /** 
       * Destructor for the Analyze class
       */
      ~Analyze();
      /**
       * Returns a pointer to the sizeof_hdr value
       */
      const int* getSizeof_hdr() const {return &this->sizeof_hdr;}
      
      /**
       * Returns the address to the data_type string
       */
      const std::string* getData_Type() const {return &this->data_type;}
      
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

      /**
       * Returns const vector of the dimensions 
       */
      const std::vector<short> getDims() const {
        return std::vector<short>(this->dimensions.begin(), this->dimensions.end());
      } 
      /**
       * Returns the voxal units of image file
       */
      const std::string* getVoxUnits() const {return &this->vox_units;}
      /**
       * Returns the cal units of image file
       */
      const std::string* getCalUnits() const {return &this->cal_units;}
      /**
       * Returns address of the unused1 field
       */
      const short* getUnused1() const {return &this->unused1;}
      /**
       * Returns address of the datatype field
       */
      const short* getDataType() const {return &this->datatype;}
      /**
       * Returns address of the bitpix field
       */
      const short* getBitPix() const {return &this->datatype;}
      /**
       * Returns address of the dim_un0 field
       */
      const short* getDimUn0() const {return &this->dim_un0;}

      /**
       * Returns const vector of the dimensions 
       */
      const std::vector<float> getPixDim() const {
        return std::vector<float>(this->pixdim.begin(), this->pixdim.end());
      } 
      /**
       * Returns const vector of the funused values 
       */
      const std::vector<float> getFunused() const {
        return std::vector<float>(this->funused.begin(), this->funused.end());
      } 
      /**
       * Returns address of vox_offset 
       */
      const float* getVoxOffset() const {return &this->vox_offset;} 
      /**
       * return address of cal_max
       */
      const float* getCalMax() const {return &this->cal_max;}
      /** 
       * Place holder
       */
      template<typename T>
        const T* getField(std::string type) const; 

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
      template<typename T>
        void setField(T* field, std::ifstream& file);
      int sizeof_hdr; /**< the size of the header. OS: 1 **/
      uchar data_type[10]; /**< declares the type of image data in .img. Retains padding  **/
      uchar db_name[18]; /**< name file is stored under in the image db **/
          
      /**
       * should be 16384, image is created as continguous with a minimum 
       */
      int extents; 
      short session_error; /**< Session Error value **/
      char regular;
      char hkey_un0; 
      short dim[8];
      uchar vox_units[4]; 
      uchar cal_units[8]; 
      short unused1;
      short datatype;
      short bitpix;
      short dim_un0;
      float pixdim[8];
      float vox_offset;
      float funused[3];
      float cal_max;
      float cal_min;
      float compressed;
      float verified;
      int glmax;
      int flmin;
      uchar descrip[80];
      uchar aux_file[24];
      char orient;
      short originator[5];
      uchar generated[10];
      uchar scannum[10];
      uchar patient_id[10];
      uchar exp_time[10];
      uchar hist_un0[3];
      int views;
      int vols_added;
      int start_field;
      int field_skip;
      int omax;
      int omin;
      int smax;
      int smin;

      std::string filename; /**< Filename for analyze header file **/
  };
}

