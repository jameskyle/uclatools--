#include "Analyze.h"
using namespace img;

Analyze::Analyze(const std::string filename) {
  // Set filename
  this->filename =  filename;
  std::ifstream     file; /* analyze file to be parsed */
  Reader<int>       read_int32;
  Reader<char>      read_char;
  Reader<char[4]>   read_char4;
  Reader<char[8]>   read_char8;
  Reader<char[10]>  read_char10;
  Reader<char[18]>  read_char18;
  Reader<short int> read_int16;
  Reader<float>     read_float;
  //register exceptions for file
  file.exceptions(std::fstream::failbit | 
                        std::fstream::eofbit  | 
                        std::fstream::badbit);

  try {
    // Open .hdr file, exit failure on err
    file.open(filename.c_str());
/*    // Slurp sizeof_hdr and flip endianness if needed
    // sizeof_hdr : int32
    file.read(read_int32.buf, sizeof(int));
    this->sizeof_hdr = read_int32.t;
    //this->shift32(&bytes[0], &this->sizeof_hdr);
    
    // data_type : uchar[10]
    file.read(read_char10.buf, sizeof(unsigned char[10]));
    this->data_type = read_char10.t;
    
    // db_name : uchar[18]
    file.read(read_char18.buf, sizeof(unsigned char[18]));
    this->db_name = read_char18.t;

    // extents : int32
    file.read(read_int32.buf, sizeof(int));
    this->extents = read_int32.t;
    //this->shift32(&bytes[0], &this->extents);
    
    // session_error : int16
    file.read(read_int16.buf, sizeof(short int));
    this->session_error = read_int16.t;
    //this->shift16(&bytes[0],&this->session_error);
    
    // regular : uchar
    file.read(read_char.buf, sizeof(unsigned char));
    this->regular = read_char.t;
    
    // hkey_un0 : uchar
    file.read(read_char.buf, sizeof(unsigned char));
    this->hkey_un0 = read_char.t;
    // Total Offset:  39

    // Now we grab the 7 dimension parameters and store them in a vector
    for(int i = 0; i <= 7; i++) {
      file.read(read_int16.buf, sizeof(short int));
      this->dimensions.push_back(read_int16.t);
    }
    // vox_units : uchar[4] 
    file.read(read_char4.buf, sizeof(char[4]));
    this->vox_units = read_char4.t;
    
    file.read(read_char8.buf, sizeof(char[8]));
    this->cal_units = read_char8.t;
    file.read(read_int16.buf, sizeof(short));
    this->unused1 = read_int16.t;

    file.read(read_int16.buf, sizeof(short));
    this->datatype = read_int16.t;

    file.read(read_int16.buf, sizeof(short));
    this->bitpix = read_int16.t;
    
    file.read(read_int16.buf, sizeof(short));
    this->dim_un0 = read_int16.t;
    
    for(int i = 0; i < 8;i++) {
      file.read(read_float.buf, sizeof(float));
      this->pixdim.push_back(read_float.t);
    }
    file.read(read_float.buf, sizeof(float));
    this->vox_offset = read_float.t;
    
    // store in the 3 funused values
    for(int i = 0;i < 3;i++) {
      file.read(read_float.buf, sizeof(float));
      this->funused.push_back(read_float.t);
    }
    file.read(read_float.buf, sizeof(float));
    this->cal_max = read_float.t;

    file.read(read_float.buf, sizeof(float));
    this->cal_min = read_float.t;

    file.read(read_float.buf, sizeof(float));
    this->cal_min = read_float.t; */
    file.close();
  }
  catch (std::out_of_range e) {
    std::cout << e.what() << std::endl; 
  }
  catch(std::exception &e){
    std::cout << e.what() << std::endl; 
  }
}
template<typename T> 
void Analyze::setField(T* field, std::ifstream &file) {

}
template<typename T>
const T* Analyze::getField(std::string type) const {

}
void Analyze::shift32(const char* bytes, int *swapped) {
  *swapped = (*(int *)bytes >> 24) |
    ((*(int *)bytes << 8) & 0x00FF0000) |
    ((*(int *)bytes >> 8) & 0x0000FF00) | 
    (*(int *)bytes << 24);
}

void Analyze::shift16(const char* bytes, short *swapped) {
  *swapped = (*(short *)bytes >> 8) | (*(short *)bytes << 8);
}

Analyze::~Analyze() {
}
