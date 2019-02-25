#include <iostream>
#include <vector>

using namespace std;

vector<int> bubbleSort(vector<int> &list){
    if (list.empty()){
        return list;
    }
    int temp;
    // 要遍历的次数,也就是list.size()次，
    for (int i = 0; i < list.size() - 1; ++i){
        // 从后向前依次的比较相邻两个数的大小
        for (int j = 0; j < list.size() - 1; j++){
            // 如果后一位的元素比当前位小，则交换它们的位置
            if (list[j + 1] < list[j]){
                temp = list[j + 1];
                list[j + 1] = list[j];
                list[j] = temp;
            }
        }
    }
    return list;
}

int main(){
    int arr[] = { 6, 4, 8, 1, 2, 3, 9 };
    vector<int> test(arr, arr + sizeof(arr) / sizeof(arr[0]));
    bubbleSort(test);
    cout << "排序后" << endl;
    for (int i = 0; i < test.size(); i++){
        cout << test[i] << " ";
    }
    cout << endl;
    
}