

#include "interval_map"

template<typename K, typename V>
void TestAssign() {
  interval_map<unsigned int, char> testMap('P');
  testMap.assign(4,5,'P');
  testMap.show();
}


void assign(K const& keyBegin, K const& keyEnd, V const& val) {
    // INSERT YOUR SOLUTION HERE

    // First, I check whether the interval is empty or not.
    // If it is empty or if the value is lower than the lowest possible value, the function terminates
    if (!(keyBegin < keyEnd) || keyBegin < std::numeric_limits<K>::lowest()) {
        return;
    }

    typename std::map<K, V>::reverse_iterator it;
    it = m_map.rbegin();

    // checking that the new value is not equal to the previous one
    if (it->second != val) {

        // checking if the key already exists
        if (m_map.count(keyEnd) >= 1) {

            // checking that the new value is not equal to the next one. We need to preserve the solution canonical
            if (m_map.find(keyEnd)->second == val) {
                return;
            }
        }

        if (m_map.find(keyBegin) == m_map.end()) {
            for (K key = it->first; key < keyBegin; key++) {
                m_map.insert(std::make_pair(key, it->second));
            }
        }

        for (K key = keyBegin; key < keyEnd; key++) {
            if (m_map.find(key) == m_map.end()) {
                m_map.insert(std::make_pair(key, val));
            }
            else {
                m_map.find(key)->second = val;
            }
        }
    }
}
