#ifndef _INTERVAL_MAP_H_
#define _INTERVAL_MAP_H_

  #include <map>
  #include <limits>

  void LOG() {
  }

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
          if (!(keyBegin < keyEnd)) {
              return;
          }

          // typename std::map<K,V>::iterator
          auto itBeginLowerBound = std::prev(m_map.lower_bound(keyBegin));
          auto itBeginUpperBound = m_map.upper_bound(keyBegin);

          auto itEndLowerBound = std::prev(m_map.lower_bound(keyEnd));
          auto itEndUpperBound = m_map.upper_bound(keyEnd);

          V initialValue = itEndLowerBound->second;

          // Insert in begining of new interval
          if (!(itBeginLowerBound->second == val) && !(itBeginUpperBound->second == val)) {
            m_map.insert_or_assign(m_map.find(keyBegin), keyBegin, val);
          }

          // Insert in the end of new interval, the previous value.
          if (m_map.find(keyEnd) == m_map.end()) {
            m_map.insert_or_assign(m_map.find(keyEnd), keyEnd, initialValue);
          }

          // Updating begin iterators
          itBeginLowerBound = std::prev(m_map.lower_bound(keyBegin));
          itBeginUpperBound = m_map.upper_bound(keyBegin);

          itEndLowerBound = std::prev(m_map.lower_bound(keyEnd));
          itEndUpperBound = m_map.upper_bound(keyEnd);

          // initialValue = itEndLowerBound->second;

          // Debugging prints
          // std::cout << "itBeginLowerBound Value = " << itBeginLowerBound->first << " - " << itBeginLowerBound->second << '\n';
          // std::cout << "itBeginUpperBound Value = " << itBeginUpperBound->first << " - " << itBeginUpperBound->second << '\n';
          //
          // std::cout << "itEndLowerBound Value = " << itEndLowerBound->first << " - " << itEndLowerBound->second << '\n';
          // std::cout << "itEndUpperBound Value = " << itEndUpperBound->first << " - " << itEndUpperBound->second << '\n';


          auto itKeyEnd = m_map.find(keyEnd);
          // std::cout << "itKeyEnd Value = " << itKeyEnd->first << " - " << itKeyEnd->second << '\n';

          // Delete previous data in that inerval if needed
          bool shouldDelete = (
            itBeginUpperBound != m_map.find(keyEnd) &&
            itEndLowerBound   != m_map.find(keyBegin)
          );

          if (shouldDelete) {
            m_map.erase(itBeginUpperBound, itKeyEnd);
            std::cout << " This should be deleting " << '\n';
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
