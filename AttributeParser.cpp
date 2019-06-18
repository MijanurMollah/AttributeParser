#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, q;
    cin >> n >> q;
    string *arr = new string[n];

    for (int i = 0; i < n; i++) {
      string value;
      cin >> value;
      while (value[value.length() - 1] != '>') {
        arr[i] += value + " ";
        cin >> value;
      }
      arr[i] += value;
    }

    for (int i = 0; i < q; i++) {
      string query;
      cin >> query;
      stringstream ss(query);
      string current_word;
      string attr_line;
      bool first = true;

      while (getline(ss, current_word, '~')) {
        if (first) {
            int index = 0;
            stringstream s(current_word);
            string word;

            while (getline(s, word, '.')) {
              string opening_tag = "<" + word;
              for (int i = index; i < n; i++) {
                if (arr[i].find(opening_tag) < 1000000) {
                  attr_line = arr[i];
                  index = i;
                  break;
                }
                }                
            }
            first = false;
        }
        else {
          int pos = attr_line.find(current_word);
           if (pos != -1) {
            string sub_sentence =
                attr_line.substr(pos + current_word.size() + 4, attr_line.size());
                int attr_end_pos = sub_sentence.find("\"");
                string result = sub_sentence.substr(0,attr_end_pos); 
            cout << result << endl;
          }
           else
            cout << "Not Found!" << endl;
        }
      }
    }
    
    return 0;
}
