//
// Created by Bourne on 2017/12/23.
//

#ifndef ALGORITHMS_SORT_H
#define ALGORITHMS_SORT_H

#include <vector>
using namespace std;

template <typename T>
class Sort
{
public:
    Sort() = default;
    ~Sort() = default;

    void selection_sort(vector<T>& vec)
    {
        int len = vec.size();
        for(int i = 0; i < len; i++) {
            int min = i;
            for(int j = i + 1; j < len; j++) {
                if(vec[j] < vec[min]) {
                    min = j;
                }
            }
            swap(vec[i], vec[min]);
        }

    }


    void insertion_sort(vector<T>& vec)
    {
        int len = vec.size();
        for(int i = 1; i < len; i++) {
            T tmp = vec[i];
            int j = i;
            for(;j > 0 && tmp < vec[j - 1]; j--) {
                vec[j] = vec[j - 1];
            }
            vec[j] = tmp;

        }

    }
private:

};


#endif //ALGORITHMS_SORT_H
