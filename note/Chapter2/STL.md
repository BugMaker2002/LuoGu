## vector
> 1.$vector<int>a(10, 3)$定义一个长度为10的vector,每个元素的值为3
> 2.size()返回元素的个数
> 3.empty()判断是否为空
> 4.clear()清空元素
> 5.操作系统的一个特点：申请所花费的时间与申请次数关系比较大，而与一次申请的数组大小其实没什么关系，比方说一次申请一个大小为1和100的数组时间相差无几，但如果申请100次长度为1的数组，那可能花费的时间就比较多了
> 6.front()，end()返回第一个和最后一个数
> 7.可以直接比较两个vector，比方说$vector<int>(4,3) < vector<int>(3,4)$（按字典序来比较）
## pair
> 1.first第一个元素
> 2.second第二个元素
> 通常将pair和vector结合起来使用：$vector<pair<int,int>>$
## string
> 1.substr(int start, int len)函数
## queue
> 1.push()队尾插入
> 2.front()队首
> 3.back()队尾
> 4.pop()弹出队头
> 5.size()和empty()
> 清空一个队列：```queue<int> q; q = queue<int>()```
## priority_queue
> 1.push()插入
> 2.top()堆顶元素
> 3.pop()弹出堆顶元素
```cpp
//小根堆
priority_queue<int, vector<int>, greater<int>> heap1;
//大根堆
priority_queue<int, vector<int>, less<int>> heap2;
```
## stack
> 1.push()栈顶插入
> 2.top()栈顶元素
> 3.pop()弹出栈顶元素
## deque双端队列
> 1.size()
> 2.empty()
> 3.clear()
> 4.front()
> 5.back()
> 6.push_back()/pop_back()
> 7.push_front()/pop_front()
> ==虽然看上去支持的类型很多，但有一个致命的缺点：__**速度慢，效率低！！**__！==
## set和multiset
> 1.set不可以有重复元素，multiset可以有
> 2.都支持insert()、size()、empty()、clear()操作
> 3.都支持find()、count()（返回某一个数的个数，对于mutiset才有意义）、erase()操作
> 4.lower_bound()返回大于等于x的最小的数的迭代器
> 5.upper_bound()返回大于x的最小的数的迭代器
## bitset
> bitset<10000> S;尖括号里面填的是数量
> ~、&、|、^
> count()返回有多少个1
> any()判断是否至少有一个1
> set()把所有位置成1