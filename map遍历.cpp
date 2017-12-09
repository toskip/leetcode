//要文明
//结果按字母序输出，如果需要自定义顺序请重载<运算符
#include <iostream>

int main() {
    map<string,int> temp;
    temp["caonima"] = 1;
    temp["caoniba"] = 1;
    temp["caoninainai"] = 1;
     for(map<string, int>::iterator iter = temp.begin(); iter != temp.end(); iter++)  
    {  
        cout<<iter->first<<"\t"<<iter->second<<endl;  
    }  
    std::cout << "Hello World!\n";
}
