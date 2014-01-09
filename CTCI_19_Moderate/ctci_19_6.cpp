#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string numToString(int num){
	string strOfNum;
	int len = 1;
	// count the number of digits in num
	while(pow(10, len) < num){
		len++;
	}
	string wordArray0To9[] = {"", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine "};
	string wordArray10To19[] = {"", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "};
	string wordArray10To90[] = {"", "Ten ", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "};
	string wordArray100To1000[] = {"", "Hundred And ", "Thousand "};
	int tmp;
	if(num == 0)
		strOfNum.append("Zero");
	else{
		if(len > 3 && len%2 == 0)
			len++;
		do{
			// num is greater than 999
			if(len > 3){
				tmp = num/int(pow(10, (len-2)));
				// if tmp is 2-digit num and not a multiple of 10
				if(tmp/10 == 1 && tmp%10 != 0)
					strOfNum.append(wordArray10To19[tmp%10]);
				else{
					strOfNum.append(wordArray10To90[tmp/10]);
					strOfNum.append(wordArray0To9[tmp%10]);
				}
				if(tmp > 0)
					strOfNum.append(wordArray100To1000[len/2]);
				num = num % int(pow(10, len-2));
				len = len-2;
			}
			// num is less than 1000
			else{
				tmp = num/100;
				if(tmp != 0){
					strOfNum.append(wordArray0To9[tmp]);
					strOfNum.append(wordArray100To1000[len/2]);
				}
				tmp = num%100;
				if(tmp/10 == 1 && tmp%10 != 0)
					strOfNum.append(wordArray10To19[tmp%10]);
				else{
					strOfNum.append(wordArray10To90[tmp/10]);
					strOfNum.append(wordArray0To9[tmp%10]);
				}
				len = 0;
			}
		} while(len > 0);
	}
	return strOfNum;
}

int main(){
	int num = 13579;
	string str = numToString(num);
	cout<<num<<": "<<str<<endl;
	return 0;
}