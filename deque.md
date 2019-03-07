怎么说呢，deque是一种双向开口的连续线性空间，至少逻辑上看上去是这样。然而事实上却没有那么简单，准确来说deque其实是一种分段连续空间，因此其实现以及各种操作比vector复杂的多。

 

一.deque的中控器

      deque是有一段一段的定量连续空间构成，采用一块所谓的map（当然不是map容器）作为主控。map是一小块连续空间，其中每一个元素都是一个指针，指向另一段连续性空间（缓冲区）。缓冲区才是deque的储存空间主体。我们可以指定缓冲区大小，默认值0表示使用512字节缓冲区。deque设计结构如下图所示：

二.deque的数据结构

      deque除了维护map的指针外，也要维护start，finish两个迭代器，分别指向第一缓冲区的第一个元素和最后缓冲区的最后一个元素（的下一个位置）。此外，它还要记录当前map的大小，因为当map结点不够的时候，需要另外配置一个更大的map，计算其大小需要知道当前map的大小（源码为：new_map_size=map_size+max(map_size,nodes_to_add)+2;）。deque数据结构如下：

class deque
{
public:
    typedef T value_type;
    typedef valude_type *pointer;
    typedef size_f size_type;
public: //迭代器
    typedef __deque_iterator<T,T&,T*,BufSiz> iterator;
protected: //元素的指针的指针
    typedef pointer *map_pointer;
protected:
    iterator start;
    iterator finish;
    map_pointer map;
    size_type map_size; //map中指针个数
...
};
 

三.deque的成员函数

      考虑到deque的特殊结构，所以实现deque的各种操作都相当琐碎复杂。最关键的就是判断是否已经处于缓冲区边缘，如果是，一旦前进或后退就必须跳跃至下一个或上一个缓冲区。还有一个重要问题就是当map前端或尾端备用空间不足时就要重新配置新map（配置更大的，拷贝原来的，释放原来的），下面的push_back()和push_front()等函数都需要先判断。下面分别解释deque的各个成员函数。

push_back()：当最后缓冲区有两个（含）以上的空间，直接在缓冲区增加新元素；当最后缓冲区只剩一个备用空间时，push_back()调用push_back_aux()，先配置一个新的缓冲区，然后再在那个仅剩的备用空间定义新元素，并更改finish的状态，令其指向新结点。
push_front()：当第一缓冲区有备用空间时，直接在备用空间增加新元素；当第一缓冲区无备用空间时，调用push_front_aux()配置新结点（缓冲区），增加新元素，并改变start状态。
pop_back()：当最后缓冲区有一个（含）以上元素，就将finish向前移一位并将最后那个元素析构掉；当最后缓冲区没有任何元素，就调用push_pop_aux()将这个缓冲区释放。解释一下：第一种情况finish指向最后缓冲区的first位置，第二种情况finish指向最后第二个缓冲区的last位置。
pop_front()：第一缓冲区有两个（含）以上元素，将第一个元素析构，将start后移；否则，将这个缓冲区释放，start指向下一个缓冲区第一个元素。
clear()：deque的最初状态（即无任何元素时）保有一个缓冲区，因此clear()之后也一样要保留一个缓冲区，finish=start。
erase()：先判断清除空间前后元素个数，移动较少一端。
insert()：若在最前端，即push_front()，最后端类似；判断插入点前后元素个数，移动较少的一端。
 

四.配接器stack和queue

      stack是一种先进后出（FILO）的数据结构，它只有一个出口。deque是双向开口的数据结构，所以SGI STL便以deque作为缺省情况下的stack底部结构，封闭其头端开口。stack没有迭代器，所以除了顶部元素，无法存取其它元素，即不能遍历stack。

      stack的成员函数都是针对其顶部元素进行操作：push()，pop()，top()。

      queue是一种先进先出（FIFO）的数据结构，它有两个出口。queue也是以deque作为底部结构，封闭其底端的出口和前端的入口。queue，只有顶端（两端）的元素能被外部使用，所以queue也没有迭代器，不提供遍历功能。

      queue的成员函数有：front()，back()，push()，pop()。

      可以看到stack和queue的成员函数以及特性都是针对其数据结构来的，所以深入理解其内部结构，不易与deque众多的成员函数混淆。当然stack和queue也可以list为底层结构实现。

 

参考：《STL源码剖析》