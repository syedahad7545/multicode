#include <iostream>
#include <iomanip>

int main(){

  const char* array[][3] = {
    {"Ali", "ahmad", "Aslam"},
    {"Golang", "python", "Ruby"},
    {"Senior", "Mid-level", "Junior"},
  };

  int nameWidth = 10;
  int langWidth = 15;
  int levelWidth = 8;

  std::cout << std::left
    << std::setw(nameWidth)
    << "Name"
    << std::setw(langWidth)
    << "Language"
    << std::setw(levelWidth)
    << "Level" << std::endl;

  std::cout << std::setw(nameWidth+langWidth+levelWidth)
    << std::setfill('-')
    << "" << std::endl;
  std::cout << std::setfill(' ');

  for(int i = 0; i < 3; ++i){
    for(int j = 0; j < 3; ++j){
      if(j == 0){
      std::cout << std::left
        << std::setw(nameWidth)
        << array[i][j];
      }else if(j == 1){
        std::cout << std::setw(langWidth)
        << array[i][j];
      }else{
        std::cout << std::setw(levelWidth)
        << array[i][j] << std::endl;
      }
    }
  }
}
