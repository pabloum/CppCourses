#ifndef _INTERVAL_MAP_H_
#define _INTERVAL_MAP_H_

  #include <map>
  #include <limits>

  template<typename K, typename V>
  class interval_map
  {
      std::map<K, V> m_map;

  public:
      // constructor associates whole range of K with val by inserting (K_min, val)
      // into the map
      interval_map(V const& val) {
          m_map.insert(m_map.end(), std::make_pair(std::numeric_limits<K>::lowest(), val));
      }

      // Assign value val to interval [keyBegin, keyEnd).
      // Overwrite previous values in this interval.
      // Conforming to the C++ Standard Library conventions, the interval
      // includes keyBegin, but excludes keyEnd.
      // If !( keyBegin < keyEnd ), this designates an empty interval,
      // and assign must do nothing.
      void assign(K const& keyBegin, K const& keyEnd, V const& val) {
          // INSERT YOUR SOLUTION HERE

          // First, I check whether the interval is empty or not.
          // If it is empty or if the value is lower than the lowest possible value, the function terminates
          if (!(keyBegin < keyEnd) || keyBegin < std::numeric_limits<K>::lowest()) {
              return;
          }

          //--------------------------
          //--------------------------
          // checking if the key already exists
          if (m_map.count(keyEnd) >= 1 || m_map.count(keyBegin) >= 1) {

              // checking that the new value is not equal to the next one or to the previous.
              // We need to preserve the solution canonical
              if  (
                    (std::prev(m_map.find(keyBegin)))->second == val ||
                    (m_map.find(keyEnd))->second == val
                  )
              {
                  return; // Just terminate the function
              }
          }

          //--------------------------
          //--------------------------
          // Completes till new kyeBegin with prevous end value
          if (m_map.find(keyBegin) == m_map.end()) {
              for (K key = m_map.rbegin()->first; key < keyBegin; key++) {
                  m_map.insert(m_map.end(), std::make_pair(key, m_map.rbegin()->second));
              }
          }

          //--------------------------
          //--------------------------
          // Fills new interval
          for (K key = keyBegin; key < keyEnd; key++) {
              // Checks if the key is new or if it should Overwrite
              if (m_map.find(key) == m_map.end()) {
                  m_map.insert(m_map.end(), std::make_pair(key, val));
              }
              else {
                  m_map.find(key)->second = val;
              }
          }
      }

      // look-up of the value associated with key
      V const& operator[](K const& key) const {
          return (--m_map.upper_bound(key))->second;
      }

      void show() {
          for (auto pair : m_map) {
            std::cout << "Key: " << pair.first << ". Value: " << pair.second << '\n';
          }
      }
  };

#endif //_INTERVAL_MAP_H_