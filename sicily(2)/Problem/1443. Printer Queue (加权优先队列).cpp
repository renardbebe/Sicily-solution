/*
	��������������Ȩ��Ԫ�س��ӣ�������ײ������Ȩ�ޣ����÷ŵ���β����ĿҪ����Ǹ�����λ�ã�������ӵ�ʱ��

    �ø����鱣������Ȩ�ޣ�������ÿ�μ�����Ԫ���Ƿ��������Ӧλ�õ�Ȩ����ͬ�������ͬ�����ӣ�����ŵ���β
*/
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
 
struct job
{
    int priority;
    int number;
    job (int priority, int number) { this->priority = priority; this->number = number;}   // �ѽṹ���priority��ֵΪ��������priority
                                                                                          // number��ֵΪ��������number 
    job(){}                        // ���� 
};
 
bool cmp(int a, int b)             // �������� 
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
        while (!q.empty()) q.pop();                    // ��ն���ʣ��Ԫ�� ������һ������ 
    }
    return 0;
}
