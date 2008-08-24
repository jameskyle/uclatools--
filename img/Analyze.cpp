#include "Analyze.h"
using namespace img;

uctAnalyze::uctAnalyze(const std::string filename) {
  // Set filename
  this->filename = filename;
  std::ifstream file; /* analyze file to be parsed */
  std::vector<char> header(40);
  std::vector<char> bytes;
  std::vector<char>::iterator i = header.begin();

  //register exceptions for file
  file.exceptions(std::fstream::failbit | 
                        std::fstream::eofbit  | 
                        std::fstream::badbit);

  try {
    // Open .hdr file, exit failure on err
    file.open(filename.c_str());
    // Slurp sizeof_hdr and flip endianness
    file.read(&header[0], 40);
    // Close file after slurping header
    bytes.assign(i, i+4);

    this->shift32(&bytes[0], &this->sizeof_hdr);
    // Iterate to data_type and store it, OffSet 0
    i += 4;
    this->data_type.assign(i, i+10);
    // Iterate to db_name and store it, OffSet 4
    i += 10;
    this->db_name.assign(i, i+18);
    // Iterate to extents flip dah bits and store it, OffSet 18
    i += 18;
    bytes.assign(i, i+4);
    this->shift32(&bytes[0], &this->extents);
    // Iterate to session_error and store it
    i += 4;
    bytes.assign(i, i+2);
    this->shift16(&bytes[0],&this->session_error);

    // Iterate to regular field, store it
    i += 2;
    this->regular = (*i);

    // Iterate to next, store it
    i += 1;
    this->hkey_un0 = (*i);
    // Total Offset:  39
    // Begin Dimensions
    i += 1;
    // Now we grab the 7 dimension parameters and store them in a vector
    // temp storage for swapped shorts
    short temp;
    bytes.assign(i, i+2);
    this->shift16(&bytes[0], &temp);
    this->dimensions.push_back(temp);
    i += 2;
    int *foo;
    char* bar;
    bytes.assign(i, i+2);
    bar = &bytes[0];
    foo = (int *)bar;
    //this->shift16(&bytes[0], &temp);
    this->dimensions.push_back(temp);
    std::cout << *foo << std::endl;
    file.close();
  }
  catch (std::out_of_range e) {
    std::cout << e.what() << std::endl; 
  }
  catch(std::exception &e){
    std::cout << e.what() << std::endl; 
  }
}

void uctAnalyze::shift32(const char* bytes, int *swapped) {
  *swapped = (*(int *)bytes >> 24) |
    ((*(int *)bytes << 8) & 0x00FF0000) |
    ((*(int *)bytes >> 8) & 0x0000FF00) | 
    (*(int *)bytes << 24);
}

void uctAnalyze::shift16(const char* bytes, short *swapped) {
  *swapped = (*(short *)bytes >> 8) | (*(short *)bytes << 8);
}

uctAnalyze::~uctAnalyze() {
}
