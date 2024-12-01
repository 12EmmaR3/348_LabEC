//Name: Emma Roy
//Lab: 348 - EC Lab
// I would like this lab to count towards my test grades, not my lab grades. Thank you!

#include <iostream>
#include <iomanip> 
#include <string>
using namespace std;


void invalid(){
  cout << "The input is invalid." << endl;
}

double extractNumeric(const string& num){
  bool has_sign = false;   //checks if there is a + or - in the front
  bool is_num = false;  //checks if char is a num or not
  bool has_decimal = false;   //checks if there is a decimal 
  bool is_negative = false; //checks if its negative
  double result = 0.0; //converts to double
  double decimal_factor = 0.1; //rounds the decimal value


  if(num.length() > 20){  //if the number is greater than 20 char constraint
    return -999999.99;
  }
  for (size_t i = 0; i < num.length(); ++i) {
    char iter = num[i];  //we look at every char seperately

    if (i == 0 && (iter == '+' || iter == '-')) { //if char is the first one and equals + or - 
          has_sign = true;
          if (iter == '-') {
              is_negative = true; // marks it as negative
          }
          continue;
      }else if(i >= 0 && (iter == '+' || iter == '-')){ //if theres a sign anywhere other than beginning, return an error
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
    if(!is_num){   //returns an error if its is an invalid char
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

