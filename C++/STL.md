### STL容器使用
STL容器自带拷贝功能，对于往STL中存入对象会进行对象的深拷贝，重新分配一块内存；对于往STL中存入指针同样会深拷贝一个新的指针，但是这两个指针指向同一块内存，要注意管理。<br>
个人记忆方法：
- 首先记取值用法：比如顺序容器能按索引取值vector、string、deque且能按*(it+i)取值，链表list只能取头尾，特别的用法stack只能后进先出、queue只能先进先出、unordered_map为哈希表实现按键值找、map和set红黑树实现可以按迭代器或自身用法或find取值；
- 删除用法：.erase(it)和.erase(first, last)顺序容器和红黑树通用，然后特别的map和set可以按erase(key)、string可以erase(pos, len)，list、queue、stack、deque、priority_queue为规定的删除pop方法；
- 插入用法: 顺序容器中 .insert(it, val) 或 .insert(it, it_first, it_last)插入另一个容器的迭代器，另外特殊容器插入有特殊规则；
- 特别的，string s = str.substr(pos, len)求子串，int pos = str.find('a')找字符位置，str.insert(pos, str1)

#### 1. vector
- 定义：
```
vector<T> vec;
 vector<T> vec(5);
 vector<T> vec(10, 0); //表示申请10个空间都填上0
```
- 访问：
```
vec[i]
vec.begin()+i //表示第i个元素（从0开始）
vec.end()-1 //最后一个元素
```
- 遍历：迭代器
```
for(auto it = vec.begin(); it != vec.end(); it++){};
```
- 常用函数：
```
	vec.push_back(x)
    vec.pop_back()
    vec.size()
    vec.clear()
    vec.insert(vec.begin()+i, x) //直接插到第i个位置(从0开始)，原来的第i个位置之后的都往后移
    vec.erase(vec.begin()+i);
    vec.erase(vec.begin()+i, vec.begin()+i+3); //删除一段区间为[)
 ```

#### 2. string
#include<string>注意不要和string.h混淆
- 定义：string str;
- 访问：
```
str[i]
str.begin()+i //表示第i个元素（从0开始）
str.end()-1 //最后一个元素
cin>>str;
cout<<str; 
```
- 常用函数
```
// +=、 ==、 !=等比较运算符重载
str.size()
str.insert(pos, str2) // pos为数字
str.insert(str.begin()+3, str2.begin(), str2.end()) 
str.erase(it)
str.erase(first, last)
str.erase(pos, length)
str.clear()
string subStr = str.substr(pos, length)
int pos = str.find(str2) // 在str中寻找子串str2，有则返回第一次出现的首位置，否则返回string::npos 
```

#### 3. set
- 头文件```include<set>```
- 常用函数

```
set.insert(obj);
set.count(obj);
auto it = set.find(obj);
set.erase(obj):
set.erase(it);
```

#### 4. map
- 头文件```#include<map>```
- 常用函数

```
mp[key] = value
mp.count(key)
map<int>::iteritor it = mp.find(key);  //没找到返回end()
map.erase(key);
map.erase(it);
```

#### 5. queue
#### 6. priority_queue
头文件```#include<queue>```
- 定义```priority_queue<int, vector<int>, greate<int>> //表示最小的在头部，less表示最大的在头部```

#### 7. stack
#### 8. pair
- 头文件```#include <utility> ```
- 定义
```
pair<int , int> pa = make_pair(1,2);
```

#### 9. list
可以认为list是一个不能随机存取的deque
- 头文件``` #include<list>```
- 常用函数
```
list.begin() //迭代器
list.end()
list.front() //元素
list.back()
list.push_front()
list.push_back()
list.pop_front()
list.pop_back();
list.empty();
list.erase(it);
list.remove(10); //删除值为10的元素，当然要是list<int>
```

#### 10. deque
可以认为deque就是一个可以在头部插入和删除值的加强版vector
-  头文件 ```#include<deque>```
-  常用函数
```
dq[i]//可以直接用索引取值
dq.front()
dq.back()
dq.push_front()
dq.push_back()
dq.pop_front()
dq.pop_back()
dq.erase(it)
```

#### 11. initializer_list
用来构造vector等，使vector<int> vec = {1, 3, 4, 5, 6}等

### algorithm函数
常用函数：
```
sort(vec.begin(), vec.end(), greater<int>()) //降序排序
// 如何自己写一个根据二维数组内容排序的sort
class test{
static bool cmp(vector<int> &a, vector<int> &b)
{
	return a[0] - b[0] > a[1] - b[1];
}
void fun(vector<vector<int>> vec){  //对于二维数组的值排序
	sort(vec.begin(), vec.end(), cmp)
}
}
```
```
string subStr = str.substr(0, 5); //配合子串使用，0是位置，5是长度
reverse(str.begin(), str.begin()+5); //在原字符串上旋转
```
```
max()
min()
abs()
iterator itx = find(it, it+i, val)//用于查找vector和string
swap(x, y)
reverse(it1, it2)
auto last = remove(vec.begin(), vec.end(), 2);//remove只是把不等于2的顺移到了前面，last就是所在的迭代器位置,所以还是得配合erase使用
fill(it, it+i, x) //给某个容器的某段赋值
next_permutation(pos, pos+i)//给出一个序列在全排列下的一个序列
```

### 有关STL面试题（待完善）
STL主要由容器迭代器、仿函数算法、分配器、配接器组成。
分配器给容器分配内存空间，算法通过迭代器获取容器中的内容，仿函数可以协助算法完成各种操作，配接器用来套接适配仿函数。
#### 1. unorder_map 、map和set有什么区别，分别是怎么实现的？
map和set都是C++的关联容器，其底层实现都是红黑树(RB-Tree)。由于map和set所开放的各种操作接口，所以几乎所有的map和set操作都是转调红黑树的操作行为。然后区别就是map和set的一些方法。
#### 2. 介绍一下STL的allocaotr
STL
#### 3. 说说迭代器iterator
#### 4. STL迭代器删除元素
说在前面，STL容器有两种存储方式，一种是节点式容器(map，list，set等)，节点式容器的插入删除操作会导致该元素失效，其他元素不受影响；另一种式顺序式容器(vector, string, deque等)，顺序式容器的插入删除操作会导致指向该元素以及后面的元素迭代器都失效（迭代器会自动后移一位）。于是以上就出现了在循环中插入删除迭代器元素出现程序崩溃的问题，因为操作后it++会失效（但自己在Clion+gcc里尝试却没有崩溃，但是erase后迭代器确实会前移一位，也就是此时不用++了）。
```
//对于map
while (it != mapInfo.end())
{
    if (...)
    {
        // 删除节点后，对迭代器进行后移的操作，因为其他元素不会失效
        mapInfo.erase(it++);
    }
    else
    {
        it++;
    }
}
// 对于vector
for (auto it= arr.begin(); it!=arr.end(); ) {
        if(*it == 2) {
           it = arr.erase(it);  // 删除方法会返回后一个迭代器，不需要进行++
        }
   		else
        	it++;
    }
```
#### STL中的sort怎么优化的
对于多的数据，sort先做一个快排的分段，如果递归深度过深会改用堆排序，否则在长度区间小于16之后直接使用插入排序。因为对于几近有序的序列，插入排序很有效。