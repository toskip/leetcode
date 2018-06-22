#include <iostream>

int main() {
    int array[5] = {4,3,5,2,6};
    int a = max(array[0],array[1]);
    int b = min(array[0],array[1]);
    for(int i = 2;i<5;i++)
    {
        if(a <= array[i]) 
        {
            b = a;
            a  = array[i];
        }
    }
    std::cout << a<<' '<<b<<endl;
}
