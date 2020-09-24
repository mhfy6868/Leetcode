## C++ 常用函数积累

to_string();



string.c_str();

1、标准库的string类提供了3个成员函数来从一个string得到c类型的**字符数组**：c_str()、data()、copy(p,n)。

 2、c_str()是Borland封装的String类中的一个函数，它返回当前字符串的首字符地址。

c_str()函数返回一个指向正规C字符串的指针常量，内容与本string串相同。这是为了与C语言兼容，在C语言中没有string类型，故必须通过string类对象的成员函数c_str()把string对象转换成C中的字符串样式。

  3、c_str()的原型是：const char*c_str() const;

  4、c_str()生成一个const char*指针，指向以空字符终止的数组。（data()与c_str()类似，但是返回的数组不以空字符终止。）

  5、注意：一定要使用strcpy()等函数来操作c_str()返回的指针。



​		

