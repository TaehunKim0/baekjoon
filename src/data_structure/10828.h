#include <iostream>
#include <string>

using namespace std;
const int MAX_STACK_SIZE = 10000;
int stackData[MAX_STACK_SIZE];

class Problem {
public:
  void Solve() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int commandCount = 0;
    cin >> commandCount;

    int lastIndex = 0;

    for (int i = 0; i < commandCount; i++) {
      string inputCommand = "";
      cin >> inputCommand;

      if (inputCommand == "push") {
        int inputValue = 0;
        cin >> inputValue;
        stackData[lastIndex++] = inputValue;
      } else if (inputCommand == "pop") {
        if (lastIndex == 0) {
          cout << "-1"
               << "\n";
        } else {
          cout << stackData[--lastIndex] << "\n";
        }
      } else if (inputCommand == "size") {
        cout << lastIndex << "\n";

      } else if (inputCommand == "empty") {
        if (lastIndex == 0) {
          cout << "1"
               << "\n";
        } else {
          cout << "0"
               << "\n";
        }
      } else if (inputCommand == "top") {
        if (lastIndex == 0) {
          cout << "-1"
               << "\n";
        } else {
          cout << stackData[lastIndex - 1] << "\n";
        }
      }
    }
  }
};
