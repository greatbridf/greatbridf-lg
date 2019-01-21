// std::string
#include <iostream>
#include <string>

using namespace std;

void output(string);

int main() {
  int times;
  string INPUT;
  cin >> INPUT >> times;
  for (int i = 0; i < INPUT.size(); ++i) {
    if (times == 0) {
      output(INPUT);
      return 0;
    }
    if (INPUT[i] > INPUT[i+1]) {
      INPUT.erase(i, 1);
      --times, --i;
    }
  }
  while (times--)
    INPUT.pop_back();
  output(INPUT);
  return 0;
}

void output(string str) {
  bool flag = false;
  for (auto itr = str.begin(); itr != str.end(); ++itr) {
    if (flag) break;
    if (*itr == '0') {
      itr = str.erase(itr);
      --itr;
    } else 
      flag = true;
  }
  cout << str;
}

// Or
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
	char num[241];
	int del;
	cin >> num >> del;
	for (char* i = num; *i != 0; ) {
		if (*i > *(i+1) && del != 0) {
			for (char* j = i; *j != 0; ++j)
				*j = *(j+1);
			i = num;
			--del;
		} else ++i;
	}
	while (num[0] == '0' && strlen(num) != 1) {
		for (int i = 0; i < strlen(num)+1; ++i) {
			num[i] = num[i+1];
		}
	}
	cout << num;
	return 0;
}

// 标准答案：
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
	int s;
	char str[250];
	scanf("%s %d", str, &s);
	int len = strlen(str);
	for (; s!=0; len--, s--) {
		int i = 0;
		while (str[i] <= str[i+1]) i++;
		while (i < len - 1) {
			str[i] = str[i+1];
			++i;
		}
	}
	int flag = 1;
	for (int i = 0; i < len; ++i) {
		if (str[i] == '0' && i < len - 1 && flag == 1) continue;
		else {
			printf("%c", str[i]);
			flag = 0;
		}
	}
	return 0;
}

