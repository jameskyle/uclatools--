#include "Analyze.h"

using namespace img;
using namespace std;

int main() {
  Analyze img("../data/example.hdr");
  cout << "Header Size: " << *img.getSizeof_hdr() << endl;
  cout << "Data_Type: " << *img.getData_Type() << endl;
  cout << "DB Name: " << *img.getDbName() << endl;
  cout << "Extents: " << *img.getExtents() << endl;
  cout << "Session Error: " << *img.getSessionError() << endl;
  cout << "Regular: " << *img.getRegular() << endl;
  cout << "Hkey_un0: " << *img.getHkey_un0() << endl;
  const vector<short> dims = img.getDims();
  int i;
  for(i = 0;i < dims.size();i++) {
    cout << "dims[" << i << "]: " << dims[i] << endl;
  }
  cout << "Vox Units: " << *img.getVoxUnits() << endl;
  cout << "Cal Units: " << *img.getCalUnits() << endl;
  cout << "Unused1: " << *img.getUnused1() << endl;
  cout << "DataType: " << *img.getDataType() << endl;
  cout << "BitPix: " << *img.getBitPix() << endl;
  cout << "DimUn0: " << *img.getDimUn0() << endl;

  const vector<float> pixdim = img.getPixDim();
  for(i = 0;i < pixdim.size();i++) {
    cout << "pixdim[" << i << "]: " << pixdim[i] << endl;
  }
  
  cout << "Vox Offset: " << *img.getVoxOffset() << endl;

  const vector<float> funused = img.getFunused();
  for(i = 0;i < funused.size();i++) {
    cout << "funused[" << i << "]: " << funused[i] << endl;
  }

  return 0;
}
