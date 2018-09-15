#include <iostream>
#include <string>
using namespace std;

bool palindrome(string word, int firstIndex, int lastIndex);
string longestpalindrome(string);
int main()
{
	string test;
	cout << "Input String: ";
	cin >> test;
	cout << "Longest Palindrome is: " << longestpalindrome(test) << endl;;


	system("pause");
}


bool palindrome(string word, int firstIndex, int lastIndex) {
	if (firstIndex == lastIndex || lastIndex<firstIndex) return true;
	else if (word[firstIndex] == word[lastIndex])
		return palindrome(word, firstIndex + 1, lastIndex - 1);
	else 
		return false;
}

string longestpalindrome(string test)
{
	string longestpalindromeSubstr = "";
	for (int i = 0; i < test.length(); i++) {
		for (int j = i + 1; j < test.length(); j++)
		{
			if (test[i] == test[j])
			{
				string temp = test.substr(i, j - i + 1);
				if (palindrome(temp, 0, temp.length() - 1))
				{
					int length = temp.length();
					if (temp.length()>longestpalindromeSubstr.length())
					{
						longestpalindromeSubstr = temp;
					}

				}
			}
		}
	}
	return longestpalindromeSubstr;
}