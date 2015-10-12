#include <set>
#include <vector>
using namespace std;

typedef multiset<int,greater<int> > intset;
typedef multiset<int,greater<int> >::iterator setiterator;

void GetLeastNumbers(const vector<int>& data,intset& leastnumbers,int k)
{
	leastnumbers.clear();
	if(k<1||data.size()<k)return;
	auto begin = data.cbegin();
	for(;begin!=data.cend();begin++)
	{
		if(leastnumbers.size()<k)
		{
			leastnumbers.insert(*begin);
		}
		else
		{
			auto itergreast = leastnumbers.begin();
			if(*itergreast>*begin)
			{
				leastnumbers.erase(itergreast);
				leastnumbers.insert(*begin);
			}
		}
	}
}


