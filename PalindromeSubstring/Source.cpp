#include <iostream>
#include <string>
using namespace std;

bool palindrome(string word, int firstIndex, int lastIndex);
int main()
{
	string test = "babba";
	string longestpalindrome = "";
	int length = 0;

	for (int i = 0; i < test.length(); i++) {
		for (int j = i + 1; j < test.length(); j++)
		{
			if (test[i] == test[j])
			{
				string temp = test.substr(i, j-i);
				if (palindrome(temp, 0, temp.length() - 1))
				{
					length = temp.length();
					if(temp.length()>longestpalindrome.length())
					{
						longestpalindrome = temp;
					}
					
				}

			}
		}
	}
	if (longestpalindrome != "")
	{
		cout << longestpalindrome << endl;
	}
	system("pause");
}


bool palindrome(string word, int firstIndex, int lastIndex) {
	if (firstIndex == lastIndex) return true;
	else if (word[firstIndex] == word[lastIndex])
		return palindrome(word, firstIndex + 1, lastIndex - 1);
	else 
		return false;

}