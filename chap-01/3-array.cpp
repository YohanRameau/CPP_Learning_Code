#include <iostream>
#include <vector>
#define UNUSED(x) (void)x

int main(int argc, char ** argv)
{
    UNUSED(argc);
    /*int array[50] = {};

    for (int i = 1; i <= 50; i++)
    {
        array[i-1] = i;
    }

    for(int value : array){
        std::cout << value << std::endl;
    }*/
    using namespace std;
    char * pEnd;
    int length = strtol(argv[1], &pEnd, 10);
    if (length <= 0)
    {
        cerr << "Expected strictly positive value for array size." << endl;
        return -1;
    }
    vector<int> values;
    for(int i = 0; i < length; i++)
    {
        cout << values.emplace_back(i+1) << endl;
    }
    for(int value: values)
    {
        cout << value;
    }
    
    /*int * values = new int[length] {};
    for(int i = 0; i < length; i++)
    {
        cout << values[i] << endl;
    }
    delete[] values;*/
    

    return 0;
}
