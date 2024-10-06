#include <iostream>
#include <string>
using namespace std;

/*
0011011  ==  121010-1

0000101101  ==  1234343232

001011000111  ==  121210123210

010101010010101101  ==  101010101212121010

()()))(( == 01011100 == 1010-1
*/

class Problem {
public:
  void Solve() {
    int inputCount = 0;
    cin >> inputCount;

    for (int i =0 ; i < inputCount; i++)
    {
      string inputText = "";
      cin >> inputText;

      int PTCount = 0;
      bool bIsComplete = false;
      for (char chr : inputText) {

        if (chr == '(') {
          ++PTCount;
        } else if (chr == ')') {
          --PTCount;
        }

        if (PTCount < 0) {
          cout << "NO" << "\n";
          bIsComplete = true;
          break;
        }
      }

      if (PTCount != 0) {
        if (bIsComplete == false)
           cout << "NO" << "\n";
      }
      else {
        cout << "YES" << "\n";
      }
    }
  }
};
