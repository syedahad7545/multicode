#include <iostream>

class Question {
    private:
    std::string ques;
    std::string op1;
    std::string op2;
    std::string op3;
    int correct;
    public:
    void setQues(std::string ques) {
      this->ques = ques;
      }
    void setOp1(std::string op1) {
      this->op1= op1;
      }
    void setOp2(std::string op2) {
      this->op2= op2;
      }
    void setOp3(std::string op3) {
      this->op3= op3;
      }
    void setCorrect(int ans) {
      this->correct= ans;
      }
    void show() {
        std::cout << ques << std::endl;
        std::cout << "A) " << op1 << std::endl;
        std::cout << "B) " << op2 << std::endl;
        std::cout << "C) " << op3 << std::endl;
  }
    void match(int num) {
        if (num == correct) {
            std::cout << "Your answer is correct. " << std::endl;
      }else {
            std::cout << "Your answer is incorrect. The correct answer is: " << correct << std::endl;
        }
    }


};
