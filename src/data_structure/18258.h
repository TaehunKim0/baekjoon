#include <iostream>
#include <string>
using namespace std;
const int MAX_QUEUE_SIZE = 2000001;
int queueData[MAX_QUEUE_SIZE];

class Problem {
public:
  /*void Split(std::string str, char seperation) {
    istringstream iss(str);
    string str_buffer;
    vector<std::string> words;
    while (getline(iss, str_buffer, seperation)) {
      words.push_back(str_buffer);
    }

    for (auto i : words) {
      cout << i << endl;
    }
  }*/

  void Solve() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int totalcommandcount = 0;
    int firstindex = 0;
    int lastindex = 0;

    cin >> totalcommandcount;
    for (int i = 0; i < totalcommandcount; i++) {
      string command = "";
      cin >> command;

      if (command == "push") {
        int value = 0;
        cin >> value;
        queueData[lastindex++] = value;
      } else if (command == "pop") {
        if (lastindex - firstindex > 0) {
          cout << queueData[firstindex++] << "\n";
        } else {
          cout << "-1"
               << "\n";
        }
      } else if (command == "size") {
        cout << lastindex - firstindex << "\n";
      } else if (command == "empty") {
        cout << ((lastindex - firstindex) == 0 ? 1 : 0) << "\n";
      } else if (command == "front") {
        cout << ((lastindex - firstindex) != 0 ? queueData[firstindex] : -1)
             << "\n";
      } else if (command == "back") {
        cout << ((lastindex - firstindex) != 0 ? queueData[lastindex - 1] : -1)
             << endl;
      }
    }
  }
};
