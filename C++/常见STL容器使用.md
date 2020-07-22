### STL容器使用
#### 1. vector
- 定义：vector<T> vec;
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
    vec.insert(vec.begin())
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
str.substr(pos, length)
int pos = str.find(str2) // 在str中寻找子串str2，有则返回第一次出现的首位置，否则返回string::npos 
```

#### 3. set
#### 4. map
#### 5. queue
#### 6. stack
#### 7. pair
头文件```#include <utility> ```
### algorithm函数
```
max()
min()
abs()
iterator itx = find(it, it+i, val)//用于差找vector和string
swap(x, y)
reverse(it1, it2)
fill(it, it+i, x) //给某个容器的某段赋值
next_permutation(pos, pos+i)//给出一个序列在全排列下的一个序列
```