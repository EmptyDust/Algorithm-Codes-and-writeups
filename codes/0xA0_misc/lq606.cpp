#include <iostream>
using namespace std;
int main()
{
    int count = 0;
    for (int i = 1; i < 2000; ++i) {
        if (i % 10 == 2)continue;
        if (i % 100 < 30 && i % 100 >= 20)continue;
        if (i % 1000 < 300 && i % 1000 >= 200)continue;
        if (i % 10 == 4)continue;
        if (i % 100 < 50 && i % 100 >= 40)continue;
        if (i % 1000 < 500 && i % 1000 >= 400)continue;
        for (int j = 1; j < 2000; ++j) {
            if (j % 10 == 2)continue;
            if (j % 100 < 30 && j % 100 >= 20)continue;
            if (j % 1000 < 300 && j % 1000 >= 200)continue;
            if (j % 10 == 4)continue;
            if (j % 100 < 50 && j % 100 >= 40)continue;
            if (j % 1000 < 500 && j % 1000 >= 400)continue;
            if (i + j > 2019)break;
            for (int k = 1; k < 2000; ++k) {
                if (k % 10 == 2)continue;
                if (k % 100 < 30 && k % 100 >= 20)continue;
                if (k % 1000 < 300 && k % 1000 >= 200)continue;
                if (k % 10 == 4)continue;
                if (k % 100 < 50 && k % 100 >= 40)continue;
                if (k % 1000 < 500 && k % 1000 >= 400)continue;
                if (i!=j&&j!=k&&i!=k&&i + j + k == 2019)count++;
            }
        }
    }
    cout << count/6;
    return 0;
}