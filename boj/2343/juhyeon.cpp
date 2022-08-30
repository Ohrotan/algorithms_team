#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int M, N;
    int left = 100001;
    int right = 0;
    int result =1e9;
    cin >> N >> M;
    vector<int> v(N + 1, 0);
    for (int i = 0; i < N; ++i)
    {
        int t;
        cin >> t;
        v[i] =t;
        left = min(t, left);
        right+=t;
    }
    int mid = 0;
    while (left <=right)
    {
        cout <<mid <<endl;
        mid = left + right;
        mid /= 2;
        int cur = 0;
        int cnt = 0;
        int b_sum=0;
        for (int i = cur; i < N; i++)
        {
            b_sum += v[i];
            if(b_sum > mid){
                cnt++;
                b_sum = v[i];
            }
            // 디스크 개수가 M개보다 많으면 탈출
            if (cnt > M)
            {
                left = mid+1;
            }
            else if(i ==N-1){
                result = min(result, mid);
            }
        }
        if(cnt<=M){
            right = mid-1;
        }
    }
    return 0;
}
