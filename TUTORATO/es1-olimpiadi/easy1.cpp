#include <fstream>
using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int N;
    int a, b;
    int max;

    in >> N;
    in >> max;
    
    for (int i=0; i<N; i++) {
        in >> a;
        in >> b;
        if (a>max) {
            max = a;
        }
        if (b>max) {
            max = b;
        }
    }

    out << max;

    return 0;
}