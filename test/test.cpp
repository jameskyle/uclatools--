#include "Analyze.h"

using namespace UC;
using namespace std;

int main() {
  try {
    Analyze* img = new Analyze("./data/example.hdr");
    img->PrintHeader();
    delete img;
  } catch (Error x) {
    cout << "Error: " << x.what() << endl;
  }
  
  return 0;
}
