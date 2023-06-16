#include <iostream>
#include <iostream>
#include <string>
#include <algorithm> // 包含reverse函数
using namespace std;
string addBinary(string a, string b)
{
	int asize = a.size();
	int bsize = b.size();

	int maxnumber;
	string maxStr;
	string minStr;
	if (asize > bsize)
	{
		maxnumber = asize;
		int gap = asize - bsize;
		maxStr = a;
		minStr = b;
		// min.reverse(b.begin(), b.end());
		reverse(minStr.begin(), minStr.end());
		for (int i = 0; i < gap; i++)
		{
			minStr += '0';
		}
		// min.reverse(b.begin(), b.end());
		reverse(minStr.begin(), minStr.end());
	}
	else
	{
		maxnumber = bsize;
		int gap = bsize - asize;
		string maxStr = b;
		string minStr = a;
		reverse(minStr.begin(), minStr.end());
		for (int i = 0; i < gap; i++)
		{
			minStr += '0';
		}
		reverse(minStr.begin(), minStr.end());
	}

	string result;
	bool isIn = false;
	for (int i = maxnumber - 1; i >= 0; i--)
	{
		if (maxStr[i] == '1' && minStr[i] == '1')
		{
			if (isIn == true)
			{
				result += '1';
			}
			else
			{
				result += '0';
			}
			isIn = true;
		}
		else if (maxStr[i] == '0' && minStr[i] == '1')
		{
			if (isIn == true)
			{
				result += '0';
				isIn = true;
			}
			else
			{
				result += '1';
				isIn = false;
			}
		}
		else if (maxStr[i] == '1' && minStr[i] == '0')
		{
			if (isIn == true)
			{
				result += '0';
				isIn = true;
			}
			else
			{
				result += '1';
				isIn = false;
			}
		}
		else if (maxStr[i] == '0' && minStr[i] == '0')
		{
			if (isIn == true)
			{
				result += '1';
			}
			else
			{
				result += '0';
			}
		}
		if(isIn == true)
		{
			result += '1';
		}
		reverse(result.begin(), result.end());
	}
	return result;
}
int main() {
    string res = addBinary("11", "1");
    std::cout << res << std::endl;
    return 0;
}
