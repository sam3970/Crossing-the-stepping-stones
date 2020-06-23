#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool test(int mid,vector<int> stones, int k)
{
    for(int cnt=0,i=0;i<stones.size();i++)
    {
        if(stones[i]-mid<=0) cnt++;
        else cnt=0;
        if(cnt>=k) return false;
    }
}

int solution(vector<int> stones, int k) {
    int l_answer = 1;
    int r_answer = 200000001;
    
    while(l_answer <= r_answer)
    {
        int mid = (l_answer + r_answer) / 2;
        if(test(mid,stones,k))
            l_answer=mid+1;
        else
            r_answer=mid-1;
    }
    return l_answer;
}

int main()
{
	cout << solution({ 2,4,5,3,2,1,4,2,5,1 }, 3);
}