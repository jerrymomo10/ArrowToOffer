#include <limits>
using namespace std;
class CharStatistics{
private:
	int occurence[256];
	int index;
public:
	CharStatistics():index(0)
	{
		for(int i=0;i<256;i++)
		{
			occurence[i] = -1;
		}
	}
	void insert(char ch)
	{
		if(occurence[ch]==-1)
		{
			occurence[ch] = index;
		}
		else if(occurence[ch]>=0)
		{
			occurence[ch] = -2;
		}
		index++;
	}
	char FirstAppearanceOnce()
	{
		char ch = '0';
		int minIndex = numeric_limits<int>::max();
		for(int i = 0;i<256;i++)
		{
			if(occurence[i]>=0&&occurence[i]<minIndex)
			{
				ch = (char)i;
				minIndex = occurence[i];
			}
		}
		return ch;
	}
};
