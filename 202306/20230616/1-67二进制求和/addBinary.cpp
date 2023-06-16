

#include <iostream>
#include <string>
#include <algorithm> // 包含reverse函数
using namespace std;
string addBinary(string a, string b)
{
	int asize = a.size() - 1;
	int bsize = b.size() - 1;
	int isIn = 0;
	string ans;
	while (asize >= 0 && bsize >= 0)
	{
		int sum  = isIn;
		sum += a[asize--] - '0';
		sum += b[bsize--] - '0';
		ans.push_back((sum % 2) ? '1' : '0');
		isIn = sum / 2;
	}
	while (asize >= 0)
	{
		int sum = isIn;
		sum += a[asize--] - '0';
		ans.push_back((sum % 2) ? '1' : '0');
		isIn = sum / 2;

	}
	while (bsize >= 0)
	{
		int sum = isIn;
		sum += b[bsize--] - '0';
		ans.push_back((sum % 2) ? '1' : '0');
		isIn = sum / 2;
	}
	if (isIn == 1)
	{
		ans.push_back('1');
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main()
{
	string res = addBinary("11", "1");
	cout << res;
	return 0;
}
//思路：首先对两个字符串比较大小，用长的来遍历，进位要加1