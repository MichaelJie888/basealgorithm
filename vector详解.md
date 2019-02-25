### vector详解

(1) vector<int> a(10); //定义了10个整型元素的向量（尖括号中为元素类型名，它可以是任何合法的数据类型），但没有给出初值，其值是不确定的。
（2）vector<int> a(10,1); //定义了10个整型元素的向量,且给出每个元素的初值为1
（3）vector<int> a(b); //用b向量来创建a向量，整体复制性赋值
（4）vector<int> a(b.begin(),b.begin+3); //定义了a值为b中第0个到第2个（共3个）元素
（5）int b[7]={1,2,3,4,5,9,8};
        vector<int> a(b,b+7); //从数组中获得初值

[vector详解](http://www.cnblogs.com/Nonono-nw/p/3462183.html)
