// 硬币问题 动态规划 最短路 从0到s DAG问题
// dp[i][j]表示：离目标还差i个重量时 可以选择j种重量 此时最少选择dp[i][j]个物体
#include<cstring>
#include<iostream>
using namespace std;
int min(int a,int b)
{
    if(a>b)return b;
    else return a;
}
int main()
{
    int ans = 99999, p = 0, value[100], num[100], n, i, j, k, dp[100][100], weight[100];
    int s;
     memset(dp, 999999, 10000 * sizeof(int));
     memset(weight,0,100*sizeof(int));
     cout<<"请输入物品数量n \n";
    cin >> n;
    cout<<"请输入n个物品的重量 \n";
    for (i = 1; i <= n; i++)
    {
        cin >> k;
        weight[k]++;
    }
    cout<<"请输入背包承重s \n";
    cin >> s;
    for (j = 99; j >= 0; j--)
        if (weight[j] != 0)
        {
            value[p] = j;
            num[p] = weight[j];
            p++;
        }
    // 求解dp[s][p]
    dp[s][p] = 0;
    int s1 = s, p1 = p;            // 循环变量
    for (p1 = p; p1 >= 1; p1--)        //p1：还剩p1种重量可选
    {
        // 当前抉择的重量为value[p-p1];
        for (s1 = s; s1 > 0; s1--)                //for p1 for s1 : 遍历目前状态 
            for (i = 0; i <= num[p - p1]; i++)        //选几个
                if (s1 - i * value[p - p1] >= 0)
                {
                    dp[s1 - i * value[p - p1]][p1 - 1] =
                        min(dp[s1][p1] + i, dp[s1 - i * value[p - p1]][p1 - 1]);                //状态转移方程
                    if (s1 - i * value[p - p1] == 0)
                        ans = min(ans, dp[s1 - i * value[p - p1]][p1 - 1]);
                }
    }
    if(ans>n)
    {
        cout<<"无法实现\n";
        return;
    }
     cout<<"最少需要";
    cout << ans;
    cout<<"个"<<endl;
}
