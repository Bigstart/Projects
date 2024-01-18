# string

# 获取长度
使用length()函数
cout<< str.length() << endl;

使用字符串的size()函数
cout<< str.size() << endl;

# 通过索引访问字符串
索引的下标从0到size()-1
```cpp
string str = "abcd1234";
for(int i = 0; i<str.size(); i++)
{
    cout<<str[i];
}
```

# 通过迭代器访问字符串
## 直接使用auto替代繁琐的类型声明（推荐）
```cpp
string str = "abcd1234";
for(auto it:str)
{
    cout<<it;
}
```
## 声明类型
```cpp
string str = "abcd1234";
for(string::iterator it = str.begin(); it! = str.end(); it++)
{
    cout << *it;
}
```
## 用auto代替string，效果一样
```cpp
string str = "abcd1234";
for(auto it = str.begin(); it! = str.end(); it++)
{
    cout << *it;
}
```

# 插入元素
## 向字符串指定位置插入元素
```cpp
string str = "abcdefg";
//向字符串索引为3的位置插入“1234”
str.insert(3,"1234");
```
## 向字符串开头插入元素
```cpp
string str = "abcdefg";
//向字符串索引为0的位置插入“1234”
str.insert(0,"1234");
```
等价于要插入的字符串元素直接在前方与该字符串连接
```cpp
string str = "abcdefg";
str = "1234" + str;
```
## 向字符串结尾插入元素
```cpp
string str = "abcdefg";
//向字符串索引为str.size()的位置插入"1234"，就是在字符串的末尾添加"1234"
str.insert(str.size(), "1234");
```
等价于要插入的字符串元素直接在后方与该字符串连接：
```cpp
string str = "abcdefg";
str = str + "1234"; //或者str += "1234";
```

# 连接字符串
## 通过 + 连接字符串
```cpp
string str = "abcdefg";
str = str + "1234"; //或者str += "1234";
```
## 通过append()函数连接字符串
```cpp
string str = "abcdefg";
str.append("1234");
```

# 删除字符串中的元素 erase()函数
```cpp
string str = "0123456789";
//从索引为2的位置开始（包括2），删除3个字符
str.erase(2,3);
//输出：0156789
```

# 修改字符串中的元素
## 通过索引修改
```cpp
string str = "0123456789";
str[0]='a';
str[1]='b';
str[2]='c';
//输出：abc3456789
```
## 通过replace()函数替换/修改
```cpp
string str = "0123456789";
//替换str中从索引1（包括1）开始的3个字符为“abcde”
str.replace(1,3,"abcde");
//输出：0abcde456789
```

# 查找字符串中的元素/查找子串
## find()函数
该函数从字符串的开头开始查找字串
1.如果能找到，返回子串第一个字符所在的索引
```cpp
string str = "Hello, world!";
	// 查找子串的位置
int pos = str.find("world");
//pos输出7
int pos1 = str.find("llo");
//pos输出2
```
2.如果找不到，返回-1，不会报错
```cpp
string str = "Hello, world!";
	// 查找子串的位置
int pos = str.find("abc"); 
	//pos输出：-1
```
## rfind()函数
该函数从字符串的末尾开始查找子串
1.如果能找到，返回子串第一个字符所在的索引
```cpp
string str = "Hello, world!";
	// 查找子串的位置
	int pos = str.rfind("world"); 
	//输出：7
```
2.如果找不到，返回-1，不会报错
```cpp
string str = "Hello, world!";
	// 查找子串的位置
int pos = str.rfind("abc"); 
	//输出：-1
```

# 截取子串： substr()函数
```cpp
string str = "0123456789";
//截取字符串从索引3开始的，长度为5的子串
string sub = str.substr(3,5);
//输出：34567
```
 
# 判断字符串是否为空 empty()函数
0代表非空，1代表空字符串
```cpp
string str1 = "abc";
	//输出：0，表示str1非空
cout << str1.empty() << endl;
 
string str2 = "";
	//输出：1，表示str2为空串
cout << str2.empty() << endl;
```

# 字符串的比较
## 通过比较运算符来比较
按照字符的ASCII码值来比较的
如果第一个字符相同，它将继续比较第二个字符，如果第二个字符相同，
就会继续比较下一个字符，以此类推，直到找到不同的字符或者一个字符串结束。
```cpp
string str1, str2;
str1 = "Hello";
str2 = "Hello";
//输出：1，表示两个字符串相等
cout << (str1 == str2) << endl;
 
str1 = "Hello";
str2 = "World";
//输出：1，表示表示str1小于str2
cout << (str1 < str2) << endl;
 
str1 = "abcd";
str2 = "ABCD";
//输出：1，表示str1大于str2
cout << (str1 > str2) << endl;
```
## 通过compare()函数来比较
返回0表示相等，负数表示str1小于str2，正数表示str1大于str2
```cpp
string str1, str2;
str1 = "Hello";
str2 = "Hello";
//输出：0，表示两个字符串相等
cout << str1.compare(str2) << endl;

str1 = "Hello";
str2 = "World";
//输出：-1，表示表示str1小于str2
cout << str1.compare(str2) << endl;
 
str1 = "abcd";
str2 = "ABCD";
//输出：1，表示str1大于str2
cout << str1.compare(str2) << endl;
```

# 字符串转数字  stoi()   stof()  stod()  函数
## 字符串转整数  stoi()函数
```cpp
string str = "123";
int num = stoi(str);
//num=123;
```
## 字符串转浮点数 stof()
```cpp
float floatNum = stof("3.14"); 
	//输出：3.14
```
## 字符串转双精度浮点数 stod()
```cpp
double doubleNum = stod("6.022e23");
	//输出：6.022e+23
```