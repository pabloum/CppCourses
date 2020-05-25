

#include "interval_map"

template<typename K, typename V>
void TestAssign() {
  interval_map<unsigned int, char> testMap('P');
  testMap.assign(4,5,'P');
  testMap.show();
}

// May 2020
// Before understanding 

void assign(K const& keyBegin, K const& keyEnd, V const& val) {
    // INSERT YOUR SOLUTION HERE

    // First, I check whether the interval is empty or not.
    // If it is empty or if the value is lower than the lowest possible value, the function terminates
    if (!(keyBegin < keyEnd) || keyBegin < std::numeric_limits<K>::lowest()) {
        return;
    }

    auto itComponentBegin = m_map.find(keyBegin);
    auto itComponentEnd = m_map.find(keyEnd);

    //--------------------------
    //--------------------------
    // checking if the key already exists
    if (m_map.count(keyEnd) >= 1 || m_map.count(keyBegin) >= 1) {

        // checking that the new value is not equal to the next one or to the previous.
        // We need to preserve the solution canonical
        if  (
              ((std::prev(itComponentBegin))->second == val) ||
              (itComponentEnd->second == val)
            )
        {
            return; // Just terminate the function
        }
    }

    //--------------------------
    //--------------------------
    // Completes till new kyeBegin with prevous end value
    if (itComponentBegin == m_map.end()) {
        for (K key = m_map.rbegin()->first; key < keyBegin; key++) {
            m_map.insert(m_map.end(), std::make_pair(key, m_map.rbegin()->second));
        }
    }

    //--------------------------
    //--------------------------
    // Fills new interval
    // TODO -> change this for to iterators upper_bound(); --> cHECK it out
    // for (auto it = itComponentBegin; it != itComponentEnd; it++) {
    for (K key = keyBegin; key < keyEnd; key++) {
        // Checks if the key is new or if it should Overwrite
        auto itComponent = m_map.find(key);

        if (itComponent == m_map.end()) {
            m_map.insert(m_map.end(), std::make_pair(key, val));
        }
        else {
            itComponent->second = val;
        }
    }
}

// January 2019
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
