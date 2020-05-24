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
      additionalElement = std::pair<K,V>(keyEnd, operator[]( keyEnd ));
  } else if (beginLowerBound == m_map.end() || keyBegin < beginLowerBound->first) {
      additionalElement = std::pair<K,V>(keyEnd, operator[]( keyBegin ));
  }

  if (beginLowerBound != m_map.end()) {
      m_map.erase(beginLowerBound, endLowerBound);
  }

  m_map.insert(std::pair<K,V>(keyBegin, val));

  if (additionalElement) {
      m_map.insert(additionalElement.value());
  }
}







// Other solution on GitHub

void assign( K const& keyBegin, K const& keyEnd, V const& val ) {

			if (!(keyBegin < keyEnd)) return;

			std::pair<K,V> beginExtra;
			std::pair<K,V> endExtra;
			bool beginHasExtra = false;
			bool endHasExtra = false;

			typename std::map<K,V>::const_iterator itBegin;
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

			typename std::map<K,V>::const_iterator itEnd;
			itEnd = m_map.lower_bound(keyEnd);
			if ( itEnd!=m_map.end() && keyEnd < itEnd->first ) {
				endHasExtra = true;
				typename std::map<K,V>::const_iterator extraIt = itEnd;
				--extraIt;
				endExtra = std::make_pair(keyEnd, extraIt->second);
				// closeRange for erase is this iterator
				// insert (keyEnd, prevIterator->second) as well!
			}

			// 4 canonical conflicts:
			//	 beginExtra w/ mid
			//	 before-mid w/ mid (beginHasExtra==false)
			//	 mid w/ endExtra
			//	 mid w/ after-mid (endHasExtra==false)

			bool insertMid = true;
			if (beginHasExtra) {
				if (beginExtra.second == val)
					insertMid = false;
			} else {
				if (itBegin != m_map.begin()) {
					typename std::map<K,V>::const_iterator beforeMid = itBegin;
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

// INSERT YOUR SOLUTION HERE
    }











// other solution on stack overflow
void assign (const K & keyBegin, const K & keyEnd, const V & val )
{
    if (!(keyBegin < keyEnd))
        return;
    auto nextInterval = --m_map.upper_bound(keyEnd);
    auto inserted1 = m_map.end();
    auto inserted2 = m_map.end();
    if (nextInterval->second == val)
        ++nextInterval;
    else if (nextInterval->first < keyEnd)
    {
        const V & nextValue = nextInterval->second;
        ++nextInterval;
        inserted1 = nextInterval = m_map.emplace_hint(nextInterval, keyEnd, nextValue);
    }
    try
    {
        auto prevInterval = nextInterval;
        --prevInterval;
        if (keyBegin < prevInterval->first)
            prevInterval = --m_map.upper_bound(keyBegin);
        if (!(prevInterval->second == val))
        {
            if (prevInterval->first < keyBegin)
            {
                ++prevInterval;
                inserted2 = prevInterval = m_map.emplace_hint(prevInterval, keyBegin, val);
            }
            else
            {
                auto beforePrev = prevInterval;
                --beforePrev;
                if (beforePrev != m_map.end() && beforePrev->second == val)
                    prevInterval = beforePrev;
                else
                {
                    auto hint = m_map.erase(prevInterval);
                    inserted2 = prevInterval = m_map.emplace_hint(hint, keyBegin, val);
                }
            }
        }
        m_map.erase(++prevInterval, nextInterval);
    }
    catch (...)
    {
        if (inserted1 != m_map.end())
            m_map.erase(inserted1);
        if (inserted2 != m_map.end())
            m_map.erase(inserted2);
        throw;
    }
}



// Other
// la otra de vivek
// didnt work
void assign( K const& keyBegin, K const& keyEnd, V const& val ) {

        K last = m_map.rbegin()->first;
        K first = m_map.begin()->first;


        if (!(keyBegin < keyEnd) ) return;
        if ( keyBegin < first ) return;
        if( last < keyEnd) return ;

         for (auto it = m_map.begin(); it!=m_map.end(); ++it)
         {
                if((*it).first < keyBegin) continue;
                else
                {
                        (*it).second=val;
                        it++;
                        auto tmp=it;
                        while((*it).first < keyEnd){
                                it++;
                        }
                        m_map.erase(tmp, it);

                break;
                }
         }
    }


// Other solution
// una de vivek
// doesnt work
void assign( K const& keyBegin, K const& keyEnd, V const& val ) {

        K last = m_map.rbegin()->first;
        K first = m_map.begin()->first;


        if (!(keyBegin < keyEnd) ) return;
        if ( keyBegin < first ) return;
        if( last < keyEnd) return ;

        auto itr1 = m_map.find(keyBegin);
        auto itr2 = m_map.find(keyEnd);

        (*itr1).second=val;
        itr1++;

        m_map.erase(itr1,itr2);

         cout << endl << endl;

    }


// other solution
// - la de mohamed

if (!(keyBegin < keyEnd))
        return;
    auto upper_bound_end = m_map.upper_bound(keyEnd);
    auto upper_bound_end2 = upper_bound_end;
    upper_bound_end2--;
    auto uper_bound_begin = m_map.upper_bound(keyBegin);
    auto uper_bound_begin2 = uper_bound_begin;
    uper_bound_begin2--;
    bool flag = false;
    bool flag2 = false;
    if (!((uper_bound_begin2)->second == val))
        flag = true;
    V tmp;
    if (!((upper_bound_end2)->second == val))
    {
        flag2 = true;
        tmp = (upper_bound_end2)->second;
    }
    for (auto it = uper_bound_begin; it != upper_bound_end;)
    {
        it = m_map.erase(it);
    }
    if (flag == true)
        m_map[keyBegin] = val;
    if (flag2 == true)
        m_map[keyEnd] = tmp;


// other solution
// -------------- The two solutions above from Vivek do not work. This is the simplest and shortest implementation I could come up with:
if (not (keyBegin < keyEnd) )
    return;

auto beginLowerBound = m_map.lower_bound(keyBegin);
auto endLowerBound = m_map.lower_bound(keyEnd);

std::optional<std::pair<K,V>> additionalElement;

if (endLowerBound == m_map.end() || keyEnd < endLowerBound->first)
    additionalElement = std::pair(keyEnd, operator[]( keyEnd ));
else if (beginLowerBound == m_map.end() || keyBegin < beginLowerBound->first)
    additionalElement = std::pair(keyEnd, operator[]( keyBegin ));

if (beginLowerBound != m_map.end())
    m_map.erase(beginLowerBound, endLowerBound);

m_map.insert(std::pair(keyBegin, val));

if (additionalElement)
    m_map.insert(additionalElement.value());
