/*
	队列中最大的优先权的元素出队，如果队首不是最大权限，就用放到队尾，题目要求的是给定的位置，计算出队的时间

    用个数组保存最大的权限，再排序，每次检测队首元素是否与数组对应位置的权限相同，如果相同，出队，否则放到队尾
*/
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
 
struct job
{
    int priority;
    int number;
    job (int priority, int number) { this->priority = priority; this->number = number;}   // 把结构体的priority赋值为传进来的priority
                                                                                          // number赋值为传进来的number 
    job(){}                        // 重载 
};
 
bool cmp(int a, int b)             // 降序排列 
{
	return a > b;
}
 
int main()
{
    queue<job> q;
    int b[101];
    int cases, n, m;
    int a, count;
    job tmp;
 
    cin >> cases;
 
    while (cases--)
    {
        count = 0;
        cin >> n >> m;
 
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            b[i] = a;
            q.push(job(a, i));
        }
 
        sort(b, b+n, cmp);
 
        while (1)
        {
            if (q.front().priority != b[count])
            {
                tmp = q.front();
                q.pop();
                q.push(tmp);
            }
            else
            {
                count++;
                if (q.front().number == m) break;
                q.pop();
            }
        }
        cout << count << endl;
        while (!q.empty()) q.pop();                    // 清空队内剩余元素 进行下一次输入 
    }
    return 0;
}
