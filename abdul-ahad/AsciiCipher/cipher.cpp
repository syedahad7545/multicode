#include <iostream>
#include <fstream>

void cipher() {
    std::fstream diary;
    diary.open("mydiary.txt", std::ios::in);
    std::fstream cipher;
    cipher.open("cipherDiary.txt", std::ios::out);

    if (diary.is_open() && cipher.is_open()) {
        std::string line;
        while (getline(diary, line)) {
            for (int i = 0; i < line.length(); ++i) {
                cipher << int(line[i]);
            }
            cipher << '\n';
        }
    } else {
        std::cerr << "File handling is failed" << std::endl;
    }
}
