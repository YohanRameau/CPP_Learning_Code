#include <iostream>
#include <string>
#include <tuple>

std::tuple<bool,int,int> parse_params(int argc, const char* const* argv)
{
    std::tuple<bool ,int, int> bad_res {false,0,0};

    if (argc != 3)
    {
        std::cerr << "Program expects 2 parameters!" << std::endl;
        return bad_res;
    }
   
    try
    {
        std::tuple<std::string,std::string> string_operands {argv[1], argv[2]};
        std::tuple<bool,int, int> res{true, std::stoi(std::get<0>(string_operands)), std::stoi(std::get<1>(string_operands))};   
        
        if (std::get<2>(res) == 0)
        {
            std::cerr << "Denominator cannot be null!" << std::endl;
            return bad_res;
        }

        return res;

    }
    catch (const std::exception&)
    {
        std::cerr << "Program expects 2 integer parameters!" << std::endl;
        return bad_res;
    }
}

std::tuple<int, int> divide(int numerator, int denominator)
{
    auto reminder = numerator % denominator;
    auto res = numerator / denominator;
    return  {reminder, res};
}


int main(int argc, char** argv)
{
    auto parse_res = parse_params(argc, argv);
    auto numerator = std::get<1>(parse_res);
    auto denominator = std::get<2>(parse_res);
    if (!std::get<0>(parse_res))
    {
        return 1;
    }

    auto reminder_quotient = divide(numerator, denominator);
    

    std::cout << numerator << " = " << denominator << " * " << std::get<0>(reminder_quotient) << " + " << std::get<1>(reminder_quotient) << std::endl;   

    return 0;
}