#include <cstdio>
#include <iostream>
#include <math.h>
#include <queue>
using namespace std;

int main() {

    queue<int> st;

    for (int i = 0; i < 5; i++) {
        st.push(i);
    }
    while(!st.empty()) {

        cout<<st.front()<<" " ;
        st.pop();
    }
    return 0;
}