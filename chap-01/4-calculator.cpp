#include <iostream>
#include <string>
#include <vector>

bool parse_params(char& op, std::vector<int>& values, int argc, char** argv);
void display_result(int resultat);
int compute_result(char op,const std::vector<int>& values);
int mul(const std::vector<int>& values);
int add(const std::vector<int>& values);
int sub(const std::vector<int>& values);
bool foo(const int*& array);

int main(int argc, char** argv)
{
    using namespace std; 
    char op;
    vector<int> values;
    if(!parse_params(op, values, argc, argv)){
        return -1;
    }
    auto result = compute_result(op, values);
    display_result(result);
    return 0;
}

bool parse_params(char& op, std::vector<int>& values, int argc, char** argv){

    if (argc < 2)
    {
        std::cerr << "Expected operator as first argument." << std::endl;
        return false;
    }
    op = argv[1][0];
    if( op != '+' && op != '-' && op != '*')
    {        
        return false;
    }

    for(int i = 2; i < argc ; i++)
    {
        int value = atoi(argv[i]);
        values.emplace_back(value); 
    }

    if (op == '-' && values.empty())
        {
            std::cerr << "Operator '-' expects at least one operand to substract from." << std::endl;
            return false;
        }
    return true;
}

int compute_result(char op, const std::vector<int>& values){
    switch (op)
    {
    case '+':
        return add(values);
        break;
    
    case '*':
        return mul(values);
        break;

    case '-':
        return sub(values);
        break;
    
    default:
        return 0;
    }

}

int add(const std::vector<int>& values){
    auto result = 0;
    for (auto v : values)
    {
        result += v;
    }
    return result;
}

int mul(const std::vector<int>& values){
    auto result = 1;
    for (auto v : values)
    {
        result += v;
    }
    return result;
}

int sub(const std::vector<int>& values){
    auto result = values[0];
    for (auto v : values)
    {
        result -= v;
    }
    return result;
}

void display_result(int resultat){
    std::cout << "Result is " << resultat << std::endl;  
}