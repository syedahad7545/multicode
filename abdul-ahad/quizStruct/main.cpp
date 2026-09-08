#include <iostream>
#include <fstream>
#include <string>
#include "quest.cpp"

int main() {
    std::fstream file("questionBank.txt", std::ios::in);
    std::string line;

    while (getline(file, line)) {
        Question q;
        std::string ques;
        std::string op1;
        std::string op2;
        std::string op3;
        std::string answer;
        int j = 0;
        for (int i = 0; i < 5; ++i) {
            bool state = false;
            int lastChar = 0;
            bool flag = false;
            for (int k = j ; line[k] != ',' && k != line.length() ; ++k) {
                if(line[k] <= 122 && line[k] >= 48)
                    flag = true;
                else
                    flag = false;

                if (flag)
                    lastChar = k;
            }
            for (;line[j] != ',' && line[j] != '\0'; ++j) {
                if (line[j] <= 122 && line[j] >= 48 && j <= lastChar) {
                    state = true;
                }
                if (state) {
                    if (i == 0)

                      ques += line[j];
                    else if (i == 1)
                        op1 += line[j];
                    else if (i == 2)
                        op2 += line[j];
                    else if (i == 3)
                        op3 += line[j];
                    else
                        answer += line[j];
                }
            }
            j++;
            if (i == 0)
                q.setQues(ques);
            else if (i == 1)
                q.setOp1(op1);
            else if (i == 2)
                q.setOp2(op2);
            else if (i == 3)
                q.setOp3(op3);
            else {
                int val = std::stoi(answer);
                q.setCorrect(val);
            }
        }
        q.show();
        std::cout << "Enter your answer: ";
        int a;
        std::cin >> a;
        q.match(a);
    }
    return 0;
}
