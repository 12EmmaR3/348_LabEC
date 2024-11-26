//Name: Emma Roy
//Lab: 348 - EC Lab
//
#include <iostream>
#include <iomanip> 
#include <string>
using namespace std;


void invalid(){
  cout << "The input is invalid." << endl;
}

double extractNumeric(const string& num){
  bool has_sign = false;
  bool is_num = false;
  bool has_decimal = false;
  bool is_negative = false;
  double result = 0.0;
  double decimal_factor = 0.1;


  if(num.length() > 20){
    return -999999.99;
  }
  for (size_t i = 0; i < num.length(); ++i) {
    char iter = num[i];

    if (i == 0 && (iter == '+' || iter == '-')) {
          has_sign = true;
          if (iter == '-') {
              is_negative = true; // marks it as negative
          }
          continue;
      }else if(i >= 0 && (iter == '+' || iter == '-')){ 
        return -999999.99;
      }
      else if(iter >= '0' && iter <= '9'){ //checks to see if the value is a number
        is_num = true;
        if (!has_decimal) {
                result = result * 10 + (iter - '0'); // builds the integer part
            } else {
                result += (iter - '0') * decimal_factor; // build the decimal part
                decimal_factor /= 10;
            }
      }
      else if (has_decimal == false && iter == '.'){
        has_decimal = true;
      }else if(has_decimal && iter == '.'){ //if there is more than one decimal
        return -999999.99;
      }
      else{
        return -999999.99;
      }
    }
    if(!is_num){
      return -999999.99;
    }
    if(is_negative) {
        result = -result;
    }
    return result;
}


int main(){ //main function was given
  string input;

  while (true){
    cout << "Enter a string (or 'END' to quit) : ";
    cin >> input;

    if (input == "END"){
      break;
    }
    double number = extractNumeric(input);
    if (number != -999999.99){
      cout << "The input is: "<<fixed << setprecision (4)
          << number << endl;
    }else{
      invalid();
    }
  }
  return 0;
}

