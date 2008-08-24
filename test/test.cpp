#include "Analyze.h"

using namespace img;
using namespace std;

int main() {
  uctAnalyze img("standard.hdr");
  cout << "Header Size: " << *img.getSizeof_hdr() << endl;
  cout << "Data Type: " << *img.getDataType() << endl;
  cout << "DB Name: " << *img.getDbName() << endl;
  cout << "Extents: " << *img.getExtents() << endl;
  cout << "Session Error: " << *img.getSessionError() << endl;
  cout << "Regular: " << *img.getRegular() << endl;
  cout << "Hkey_un0: " << *img.getHkey_un0() << endl;
  return 0;
}
