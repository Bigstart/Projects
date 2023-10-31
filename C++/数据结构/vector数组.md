# vector

## 一、创建vector对象
格式：   vector<数据类型> 名字
例如：
```cpp
    vector<int> myVector;  //存储整数的
	vector<char> myVector; //存储字符的
	vector<string> myVector;  ////存储字符串的
```


## 二、初始化一维vector对象
### 1 vector<int> myVector
此时myVector中没有任何元素，直接进行访问会报错
可以使用myVector.resize(num),或者myVector.resize(n,num)来初始化

myVector.resize(num)是使用num个0来初始化
```cpp
vector<int> myVector;
myVector.resize(5);
//输出内容是： 0 0 0 0 0
for(int i = 0; i < myVector.size(); i++)
{
	cout<<myVector[i]<<" ";
}
```

myVector.resize(n,num)是使用n个num来初始化
```cpp
vector<int> myVector;
myVector.resize(5,10);
//输出内容是： 10 10 10 10 10
for(int i = 0; i < myVector.size(); i++)
{
	cout<<myVector[i]<<" ";
}
```

### 2 vector<int> myVector = {1,2,3,4,5}
在初始化后就进行了赋值，此时的myVector.size() = 5; 
如果使用myVector.resize(num)来修改的话，如果num==3,会丢弃myVector最后的4和5
```cpp
vector < int > myVector = { 1,2,3,4,5 };
	myVector.resize(3);
	//输出内容是：1 2 3
	for (int i = 0; i < myVector.size(); i++) {
		cout << myVector[i] << " ";
	}
```

如果num==7，会用0来填充没有赋值的部分
```cpp
vector < int > myVector = { 1,2,3,4,5 };
	myVector.resize(7);
	//输出内容是：1 2 3 4 5 0 0
	for (int i = 0; i < myVector.size(); i++) {
		cout << myVector[i] << " ";
	}
```

### 3 vector<int> myVector(num);  或者vector<int> myVector(n,num)
类似于resize的用法

### 4 使用另外一个数组来初始化myVector
vector<int> myVector(testVector); 或者 vector<int> myVector = testVector;
testVector也必须是vector类型

```cpp
vector<int> testVector = {1,2,3,4,5};
vector<int> myVector(testVector);
//myVector的内容是 1 2 3 4 5
```

```cpp
vector<int> testVector = {1,2,3,4,5};
vector<int> myVector = testVector;
//myVector的内容是 1 2 3 4 5
```

### 5 使用指针初始化一维vector
vector<int> myVector(*p,*q);  使用另外一个数组的指针来初始化v，这里既可以使用vector的指针，也可以使用普通数组的指针
```cpp
int arr[5] = {1,2,3,4,5};
vector<int> myVector = {1,2,3,4};

vector<int> vector1(arr,arr+3);   //arr是数组的首地址，arr+3是数组首地址向后移三位，
//arr + 3 指向数组中的第四个元素，但范围构造函数在结束位置之前停止，所以只会复制前三个元素。
此时的vector数组是  1 2 3

vector<int> vector2(myVector.begin() + 1, myVector.end() - 1);
//myVector.begin() + 1 指向 myVector 中的第二个元素（值为 2）
//myVector.end() - 1 指向 myVector 中的倒数第二个元素（值为 3）
```


## 三 初始化二位vector对象
### 1 vector<vector<int>> myVector
和一维数组一样，没有任何元素，直接访问会报错
可以先使用myVector.resize(n)来初始化这个二维数组的第一维，然后使用for循环初始化第二维
```cpp
vector<vector<int>> myVector;
myVector.resize(5);
for(int i = 0; i < 5; i++)
{
	myVector[i].resize(5);   //每一行都初始化为0
}
//输出：
	for (int i = 0; i < myVector.size(); i++) 
	{
		for (int j = 0; j < myVector[i].size(); j++) {  // 这里使用 j 来迭代内层循环
			cout << myVector[i][j] << " ";
		}
		cout << endl;
	}
```

### 2 vector<vector<int>> myVector(n,testVector);
可以直接使用n和testVector来初始化myVector，但是testVector需要时vector类型
```cpp
vector<int> testVector(4,1);     //里面的值是 {1 1 1 1}
vector<vector<int>> myVector(4,testVector);  //4代表的意思是有4行
//输出：
for(int i = 0;i < myVector.size(); i++)
{
	for(int j = 0; j < myVector[i].size(); j++)
	{
		cout<<myVector[i][j]<<" ";
	}
}
```

### 3 复制其他vector的方式初始化
vector<std::vector<int>> testVector = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
}
vector<std::vector<int>> myVector = testVector;

### 4 使用指针初始化二维vector'
既可以使用vector的指针，也可以使用普通数组的指针

使用vector的指针
```cpp
vector<int> vector1 = {1,2,3,4};
vector<vector<int>> vector2(4,vector1);   //有4行，每一行都是 vector1 的副本
vector<vector<int>> myVector(vector2.begin(),vector2.end());   //复制 vector2 中的内容
```

使用普通数组的指针
```cpp
int arr[4][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
vector<vector<int>> myVector;
for(int i = 0;i < 4; i++)
{
	//使用指针arr[i]初始化每一行
	vector<int> row(arr[i],arr[i]+4);
	myVector.push_back(row);
}
//输出内容是：
	/*1 2 3 4
	5 6 7 8
	9 10 11 12
	13 14 15 16*/
```


## 三 访问vector中的元素
直接使用下标操作符[]来访问vector中特定索引的元素
```cpp
vector<int> myVector = {10,20,30,40};
cout<<myVector[0]<<endl;   //10
cout<<myVector[1]<<endl;
cout<<myVector[2]<<endl;
cout<<myVector[3]<<endl;
```

## 四 获取vector的大小
使用size()或者capacity()函数
```cpp
vector<int> myVector = {10,20,30,40,50};
cout<<myVector.size()<<endl;   // 5
cout<<myVector.capacity()<<endl;  // 5
```


## 五 向vector中添加元素
使用push_back()函数将元素添加到vector的末尾，默认且只能添加到末尾
```cpp
vector<int> myVector = {1,2,3,4};
myVector.push_back(100);
myVector.push_back(200);
现在里面的内容是 {1,2,3,4,100.200}
```

## 六 向vector中插入元素
使用insert()函数来在指定位置插入元素。需要提供插入位置的迭代器和插入的元素值
```cpp
vector<int> myVector = {100,200,300,400,500,600};
vector<int>::iterator it;
it = myVector.begin();   //索引为0的位置
myVector.insert(it,111);  //向索引为0的位置插入元素111
//现在数组的内容为{111,100,200,300,400,500,600}

it = myVector.begin() + 2;  //索引为2的位置
myVector.insert(it,222);    //向索引为2的位置插入元素222
//现在数组的内容为{111,100,222,200,300,400,500,600}

it = myVector.end(); //myVector的末尾
myVector.insert(it, 999); //向myVector的末尾插入元素999
//现在数组的内容为{111,100,222,200,300,400,500,600,999}
```

## 删除vector中的元素
使用pop_back()函数删除vector末尾的元素，默认且只能删除末尾的元素
```cpp
vector<int> myVector = {100,200,300,400,500};
myVector.pop_back();
myVector.pop_back();
	cout << myVector.size() << endl; // 3
	//输出内容是：100 200 300
```

## 删除vector中指定位置的元素
使用erase()函数来删除指定位置的元素，需要提供删除位置的迭代器
```cpp
vector<int> myVector = { 100,200,300,400,500,600 };
vector::iterator it;

it = myVector.begin();  //索引为0的位置
myVector.erase(it);   //删除索引为0的位置的元素
//现在的内容为{200,300,400,500,600}

it = myVector.begin() + 2;  //索引为2的位置
myVector.erase(it);   //删除索引为2的位置的元素
//现在的内容为{200,300,500,600}
```


## 删除vector中指定数值的元素
使用remove()函数来删除指定值的元素
### 1：如果能在目标vector中找到该数值的元素，直接删除
```cpp
vector<int> myVector = { 100,200,300,400,500,600 };
myVector.erase(remove(myVector.begin(),myVector.end(),500),myVector.end());
myVector.erase(remove(myVector.begin(),myVector.end(),300),myVector.end()); //删除数值为300的元素
内容为：100 200 400 600
//remove() 函数会将所有等于 valueToDelete 的元素移到向量的末尾，但不会真正删除它们
//它返回一个迭代器，指向从 valueToDelete 移到向量末尾的元素的起始位置。
//myVector.end() 是向量的结束迭代器。
//erase()函数使用提供的迭代器范围，从向量中删除元素
//会删除从 valueToDelete 移到向量末尾的元素，实际上就是删除所有等于 valueToDelete 的元素
```

### 2：如果目标vector中找不到该数值的元素，不做任何操作 直接返回
```cpp
vector<int> myVector = { 100,200,300,400,500,600 };
myVector.erase(remove(myVector.begin(), myVector.end(), 555), myVector.end()); //删除数值为555的元素
myVector.erase(remove(myVector.begin(), myVector.end(), 333), myVector.end()); //删除数值为333的元素
内容为：100 200 300 400 500 600
```


## 修改vector中的元素
直接使用下标操作符[]来修改vector中特定索引的元素
```cpp
vector<int> myVector = { 100,200,300,400,500 };
	myVector[0] = 111; // 修改索引为0的元素
	myVector[1] = 222; // 修改索引为0的元素
```

## 查找vector中的元素
使用find()函数来查找指定值的元素，或者使用迭代器来遍历查找

### 1 使用find()函数查找
```cpp
vector<int> myVector = { 100,200,300,400,500,600 };
vector<int>::iterator it = find(myVector.begin(),myVector.end(),500);
if(it != myVector.end())  //find() 函数在容器中找不到目标元素时，它会返回 myVector.end()，表示未找到。
{
	cout<<"目标元素的索引为"<<distance(myVector.begin(),it)<<endl;
}
else
{
	cout<<"没有找到"<<endl;
}
```

### 2 使用迭代器遍历查找
```cpp
vector<int> myVector = { 100,200,300,400,500,600 };
bool fount = false;
int valueToFind = 300;

for(vector<int>::iterator it = myVector.begin();it != myVector.end();++it)
{
	if(*it == valueToFind)
	{
		cout <<"目标元素的索引为："<< distance(myVector.begin(),it) << endl;
		found = true;
		break;
	}
}
if(!found)
{
	cout<<"没有找到"<<endl;
}
```


## 清空vector中的元素
使用clear()函数可以清空vector中的所有元素
```cpp
vector<int> myVector = { 100,200,300,400,500,600 };
cout << myVector.size() << endl; // 6
myVector.clear();
cout << myVector.size() << endl; // 0
```

## 使用迭代器遍历vector
三种方式
### 第一种
```cpp
vector<int> myVector = {100,200,300,400,500,600 };
for(vector<int>::iterator it = myVector.begin();it != myVector.end(); it++)
{
	cout<< *it << " ";
}
```

### 第二种    
for(int it:myVector){},这里需要指定myVector中元素的类型
这里it不是迭代器，而是一个复制了容器元素的拷贝
```cpp
vector<int> myVector = { 100,200,300,400,500,600 };
for(int it:myVector)
{
	cout<< it << " ";
}
```

### 第三种
for(auto it:myVector){} 这里直接使用auto，不需要根据myVector中元素的类型改变
这里it不是迭代器，而是一个复制了容器元素的拷贝
```cpp
vector<int> myVector = { 100,200,300,400,500,600 };
for(auto it:myVector)
{
	cout<< it << " ";
}
```