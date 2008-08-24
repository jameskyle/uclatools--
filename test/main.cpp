#include<iostream>
#include <vector>

using namespace std;
int main() {
  vector<int> foo(20);
  vector<int> bar(4);
  vector<int>::iterator j = foo.begin();
  vector<int>::iterator k = bar.begin();
  
  int i;
  for(i=0;i<20;i++) {
    foo.at(i) = i;
  }
  
  bar.assign(foo.begin(), foo.begin() + 4);
  for(k = bar.begin();k < bar.end();k++) {
    cout << (*k) << endl; 
  }
  cout << bar.size() << endl;
  return 0;
}
