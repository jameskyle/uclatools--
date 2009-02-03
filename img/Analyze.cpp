#include "Analyze.h"
using namespace UC;

Analyze::Analyze(const std::string filename) {
  // Set filename
  this->filename =  filename;
  // Populate header fields
  this->populateHeaderFields();
  }

void Analyze::populateHeaderFields(){
  std::ifstream     file; /* analyze file to be parsed */
  //register exceptions for file
  file.exceptions(std::fstream::failbit | 
                        std::fstream::eofbit  | 
                        std::fstream::badbit);

    // Open .hdr file, exit failure on err
    file.open(filename.c_str());
    file.read(reinterpret_cast<char*>(&this->hdr), sizeof(dsr)); 
    file.close();
}
void Analyze::PrintHeader() {
  std::cout << "sizeof_hdr: "    << this->hdr.hk.sizeof_hdr    
            << std::endl

            << "data_type: '"    << std::setfill(' ') << std::setw(10)
            << this->hdr.hk.data_type << "'" << std::endl

            << "db_name: '" << std::setfill(' ') << std::setw(18) 
            << this->hdr.hk.db_name << "'" << std::endl 

            << "extents: "       << this->hdr.hk.extents       
            << std::endl 

            << "session_error: " << this->hdr.hk.session_error 
            << std::endl

            << "regular: "       << this->hdr.hk.regular       
            << std::endl

            << "hkey_un0: '" << std::setfill(' ') << std::setw(1)  
            << this->hdr.hk.hkey_un0 << "'" << std::endl;

  std::cout << "dime.dim: [0] |  [1] |  [2] |  [3] |  [4] |  [5] |  [6] |  "
            << "[7] |" << std::endl << "\t ";

  for(int i = 0;i < 8;i++) {
    std::cout << std::setfill('0') << std::setw(4) << this->hdr.dime.dim[i] 
      << " | ";

  }

  std::cout  << std::endl;
  std::cout << "[hex]\t ";
  std::cout << std::hex << std::showbase; 
  for(int i = 0;i < 8; i++) {
    std::cout << std::setfill(' ') << std::setw(4)
              << this->hdr.dime.dim[i] << " | ";
  }

  std::cout << std::endl;

  std::cout << "dime.vox_units: '" << std::setfill(' ') << std::setw(4)
            << this->hdr.dime.vox_units << "'" << std::endl;
  std::cout << "dime.cal_units: '" << std::setfill(' ') << std::setw(8) 
            << this->hdr.dime.cal_units << "'" << std::endl;

  std::cout << "pixdim:    [0] |   [1] |   [2] |   [3] |   [4] |   [5] |   ";
  std::cout << "[6] |  [7] |" << std::endl;
  
  std::cout  << "\t " << std::fixed << std::setprecision(3);
  for(int i = 0;i < 8; i++) {
    std::cout << this->hdr.dime.pixdim[i] <<  " | ";
  }
  std::cout << std::endl;
  
  std::cout << "vox_offset: " << this->hdr.dime.vox_offset << std::endl;
  std::cout << "funused1: " << this->hdr.dime.funused1 << std::endl;
  std::cout << "funused2: " << this->hdr.dime.funused2 << std::endl;
  std::cout << "funused3: " << this->hdr.dime.funused3 << std::endl;
  std::cout << "cal_max: " << this->hdr.dime.cal_max << std::endl;
  std::cout << "cal_min: " << this->hdr.dime.cal_min << std::endl;
  std::cout << "compressed: " << this->hdr.dime.compressed << std::endl;
  std::cout << "verified: " << this->hdr.dime.verified << std::endl;
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
