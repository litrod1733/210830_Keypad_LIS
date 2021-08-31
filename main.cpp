//
// Created by 이인성 on 2021/08/29.
//

#include <string>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int fingerLocation(int a, int b) {
  int a_x;
  int a_y;
  int b_x;
  int b_y;
  if(b % 3 == 0) {
    a_x = a%3;
    a_y = a/3;
    b_x = 3;
    b_y = b/3-1;
  }
  else {
    a_x = a%3;
    a_y = a/3;
    b_x = b%3;
    b_y = b/3;
  }
  int result = abs(a_x - b_x) + abs(a_y - b_y);
  return result;
}

string solution(vector<int> numbers, string hand) {
  string answer;
  int lefthand = 10;
  int righthand = 12;
  int number_s = numbers.size();
  for(int i=0; i<number_s; i++) {
    if(numbers[i] == 0) {
      numbers[i] = 11;
    }
    if((numbers[i] == 1) || (numbers[i] == 4) || (numbers[i] == 7)) {
      answer.push_back('L');
      lefthand = numbers[i];
    }
    else if((numbers[i] == 3) || (numbers[i] == 6) || (numbers[i] == 9)) {
      answer.push_back('R');
      righthand = numbers[i];
    }
    else {
      int L = fingerLocation(numbers[i], lefthand);
      int R = fingerLocation(numbers[i], righthand);
      if(L < R) {
        answer.push_back('L');
        lefthand = numbers[i];
      }
      else if(L > R) {
        answer.push_back('R');
        righthand = numbers[i];
      }
      else {
        if(hand == "right") {
          answer.push_back('R');
          righthand = numbers[i];
        }
        else {
          answer.push_back('L');
          lefthand = numbers[i];
        }
      }
    }

  }
  return answer;
}
int main(){
    vector<int> numbers = {1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5};
//    vector<int> numbers = {7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2};
//  vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    string hand = "right";
//    string hand = "left";
//  string hand = "right";
  cout << solution(numbers, hand) << endl;

  return 0;
}