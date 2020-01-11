#include <iostream>
#include "gm/vector.h"
#include "gm/simd/simd4f.h"

template <typename T, int Dims>
std::ostream& operator<<(std::ostream& ostr, gm::vector<T, Dims> const& v)
{
    for (int i = 0 ; i < Dims - 1; ++i)
        ostr << v.data[i] << ", ";
    ostr << v.data[Dims - 1];
    return ostr;
}

std::ostream& operator<<(std::ostream& ostr, gm::simd4f const& s)
{
    ostr << simd4f_get_x(s) << ", "
         << simd4f_get_y(s) << ", "
         << simd4f_get_y(s) << ", " 
         << simd4f_get_y(s);
    return ostr;
}

int main(int argc, char* argv[])
{
    gm::vec3 v;
    v.x = 1;
    v.y = 2;
    v.z = 3;

    std::cout << v << std::endl;
    
    return 0;
}
