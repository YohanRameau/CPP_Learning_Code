#pragma once
#include <utility>
#include <iostream>

using Vertex = std::pair<int,int>; 

class Polygon
{
    friend std::ostream& operator<<(std::ostream& stream, const Polygon& polygon);
    public:
        void   add_vertex(int a, int b);
        const Vertex& get_vertex(int index) const;
        ~Polygon();    
    private:
        std::size_t  _size     = 0u;
        Vertex* _vertices = nullptr;
};
