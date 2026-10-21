#include <fstream>
using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int A;
    int B;
    int res;

    in >> A;
    in >> B;

    res = A + B;

    out << res;
    
    return 0;
}