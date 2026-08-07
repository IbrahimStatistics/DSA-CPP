// Shallow copy

#include<iostream>
#include<string>
using namespace std;

class cuboid{
    private:
    // Nothing here..

    public:
        int* length;
        int* breadht;
        int* height;

        void setDimension(int l, int b, int h) {
            *length = l;
            *breadht = b;
            *height = h;
        }

        void getDimensions() {
            cout << "Length : " << *length << endl
                 << "breadht : " << *breadht << endl
                 << "height : " << *height << endl; 
        }
};


int main() {
    cuboid c1;
    c1.setDimension(10,15,20);
    c1.getDimensions();

    cuboid c2 = c1;

    // c2.getDimensions();
}