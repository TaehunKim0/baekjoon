#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include <chrono>
using namespace std;

class Problem {
public:
  void Split(std::string str, char seperation) {
    istringstream iss(str);
    string str_buffer;
    vector<std::string> words;
    while (getline(iss, str_buffer, seperation)) {
      words.push_back(str_buffer);
    }

    for (auto i : words) {
      cout << i << endl;
    }
  }

  void Solve() {

    auto start = chrono::high_resolution_clock::now();

    std::map<string, int> m;
    enum ECommand { push = 1, pop, size, empty, front, back };

    ios::sync_with_stdio(false);
    cin.tie(0);

    m["push"] = ECommand::push;
    m["pop"] = ECommand::pop;
    m["size"] = ECommand::size;
    m["empty"] = ECommand::empty;
    m["front"] = ECommand::front;
    m["back"] = ECommand::back;

    int totalCommandCount = 0;
    cin >> totalCommandCount;

    int *queue = new int[totalCommandCount];
    int currentIndex = -1;
    int count = 1;

    for (int i = 0; i < totalCommandCount; i++) {
      std::string command = "";
      int value = 0;
      cin >> command;
      cout << endl;
      cout << "command : " << command << endl;

      switch (m[command]) {
      case ECommand::push:
        cin >> value;
        cout << "value : " << value << endl;
        currentIndex++;
        queue[currentIndex] = value;
        break;

      case ECommand::pop:
        cout << (queue[0] > 0 ? queue[0] : -1) << endl;
        queue[0] = 0;
        cout << "pop" <<endl;
        for (int i = 0; i < totalCommandCount; i++) {
          if ((i + 1) < totalCommandCount - 1) {
            if (queue[i + 1] == 0) {
              queue[i] = 0;
              break;
            }
            queue[i] = queue[i + 1];
          } else {
            break;
          }
        }

        currentIndex = std::max(--currentIndex, -1);
        break;

      case ECommand::size:
        cout << currentIndex + 1 << endl;
        break;

      case ECommand::empty:
        cout << (queue[0] == 0) << endl;
        break;

      case ECommand::front:
        cout << (queue[0] > 0 ? queue[0] : -1) << endl;
        break;

      case ECommand::back:
        cout << (queue[currentIndex] > 0 ? queue[currentIndex] : -1) << endl;
        break;
      }
    }
    // 종료 시간 기록
    auto end = chrono::high_resolution_clock::now();
    // 실행 시간 계산
    chrono::duration<double, std::milli> elapsed = end - start;

    cout << "Execution time: " << elapsed.count() << " ms" << endl;
  }

};
