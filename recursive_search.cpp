#include "recursive_search.h"

int lastOccurrence(const std::vector<int>& v, int target, int index) {
    if (index < 0) return -1;
    if (v[index] == target) return index;
    return lastOccurrence(v, target, index - 1);
}
