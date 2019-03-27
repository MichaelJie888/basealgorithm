//双向队列
#include<deque>
#include<cstdio>
#include<algorithm>
const int MAX_N = 20;
using namespace std;
int main(){

    deque<int> ideq(MAX_N);
    deque<int>::iterator pos;
    int i;
    // 进行赋值
    for (i = 0; i < MAX_N; i++) {
        ideq[i] = i;
    }
    // 输出deque
    for (i = 0; i < MAX_N; i++) {
        printf("%d ", ideq[i]);
    }

    // 在头部和尾部加入数据
    puts("");
    puts("在头部和尾部加入数据");
    ideq.push_back(100);  // 尾部
    ideq.push_front(101); //头部

    // 输出deque的数据

    for (pos = ideq.begin(); pos != ideq.end(); pos++) {
        printf("%d ", *pos);
    }
    puts("");

    //查找
    const int FIND_NUMBER = 12;
    printf("查找数据%d\n", FIND_NUMBER);


    pos = find(ideq.begin(), ideq.end(), FIND_NUMBER);

    if (pos != ideq.end()) {
        printf("成功找到！ %d\n", *pos);
    } else {
        printf("失败！\n");
    }

    // 在头部和尾部删除数据
    puts("在头部和尾部删除数据");
    ideq.pop_back();
    ideq.pop_front();

    // 再次输出数据
    puts("再次输出数据!");

    for (pos = ideq.begin(); pos != ideq.end(); pos++) {
        printf("%d ", *pos);
    }

    return 0;
}