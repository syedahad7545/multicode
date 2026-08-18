#include <iostream>
#include <fstream>

void dicipher() {
   std::fstream cipher;
   cipher.open("cipherDiary.txt", std::ios::in);
   std::fstream dicipher;
   dicipher.open("mydiaryDicipher.txt", std::ios::out);

   if (cipher.is_open() && dicipher.is_open()) {
       std::string line;
       while (getline(cipher, line)) {
           int num = 0;
           for (int i = 0; i < line.length(); ++i) {
               if (48 >= (num) && (num) <= 122 && (num) != 32) {
                  num = (num * 10) + (line[i] - 48);
               } else {
                   dicipher << char(num);
                   num = 0;
                   num = (num * 10) + (line[i] - 48);
               }
           }
           dicipher << char(num);
           dicipher << '\n';
        }
   }else {
       std::cerr << "File handling is failed" << std::endl;
       }

}
