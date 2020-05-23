// First comment

void assign( K const& keyBegin, K const& keyEnd, V const& val ) {
      // insert code here
      if (!(keyBegin < keyEnd)) return;

      std::pair<K,V> beginExtra;
      std::pair<K,V> endExtra;
      bool beginHasExtra = false;
      bool endHasExtra = false;

      typename std::map<K,V>::iterator itBegin;
      itBegin = m_map.lower_bound(keyBegin);
      if ( itBegin!=m_map.end() && keyBegin < itBegin->first ) {
          if (itBegin != m_map.begin()) {
              beginHasExtra = true;
              --itBegin;
              beginExtra = std::make_pair(itBegin->first, itBegin->second);
          }
          // openRange for erase is prevIterator
          // insert (prevIterator->first, prevIterator->second) as well!
      }

      typename std::map<K,V>::iterator itEnd;
      itEnd = m_map.lower_bound(keyEnd);
      if ( itEnd!=m_map.end() && keyEnd < itEnd->first ) {
          endHasExtra = true;
          typename std::map<K,V>::iterator extraIt = itEnd;
          --extraIt;
          endExtra = std::make_pair(keyEnd, extraIt->second);
          // closeRange for erase is this iterator
          // insert (keyEnd, prevIterator->second) as well!
      }

      // 4 canonical conflicts:
      //   beginExtra w/ mid
      //   before-mid w/ mid (beginHasExtra==false)
      //   mid w/ endExtra
      //   mid w/ after-mid (endHasExtra==false)

      bool insertMid = true;
      if (beginHasExtra) {
          if (beginExtra.second == val)
              insertMid = false;
      } else {
          if (itBegin != m_map.begin()) {
              typename std::map<K,V>::iterator beforeMid = itBegin;
              --beforeMid;
              if (beforeMid->second == val)
                  insertMid = false;
          }
      }


      if (endHasExtra) {
          if ( (insertMid && endExtra.second == val) || (!insertMid && endExtra.second == beginExtra.second) )
              endHasExtra = false;
      } else {
          if ( (insertMid && itEnd!=m_map.end() && itEnd->second == val) || (!insertMid && itEnd!=m_map.end() && itEnd->second == beginExtra.second) )
              itEnd = m_map.erase(itEnd);
      }

      itBegin = m_map.erase(itBegin, itEnd);
      if (beginHasExtra)
          itBegin = m_map.insert(itBegin, beginExtra);
      if (insertMid)
          itBegin = m_map.insert(itBegin, std::make_pair(keyBegin, val));
      if (endHasExtra)
          m_map.insert(itBegin, endExtra);
}



// Fourth comment

void assign( K const& keyBegin, K const& keyEnd, V const& val ) {

  if (not (keyBegin < keyEnd) ) {
      return;
  }

  auto beginLowerBound = m_map.lower_bound(keyBegin);
  auto endLowerBound = m_map.lower_bound(keyEnd);

  std::optional<std::pair<K,V>> additionalElement;

  if (endLowerBound == m_map.end() || keyEnd < endLowerBound->first) {
      additionalElement = std::pair(keyEnd, operator[]( keyEnd ));
  } else if (beginLowerBound == m_map.end() || keyBegin < beginLowerBound->first) {
      additionalElement = std::pair(keyEnd, operator[]( keyBegin ));
  }

  if (beginLowerBound != m_map.end()) {
      m_map.erase(beginLowerBound, endLowerBound);
  }

  m_map.insert(std::pair(keyBegin, val));

  if (additionalElement) {
      m_map.insert(additionalElement.value());
  }
}
