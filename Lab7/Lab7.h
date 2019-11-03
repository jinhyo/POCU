#pragma once

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

namespace lab7
{
	template <typename K, class V>
	std::map<K, V> ConvertVectorsToMap(const std::vector<K>& keys, const std::vector<V>& values)
	{
		std::map<K, V> m;
		unsigned size = min(keys.size(), values.size());
		for (size_t i = 0; i < size; i++)
		{
			m.insert(pair<K, V>(keys[i], values[i]));
		}
		return m;
	}

	template <typename K, class V>
	std::vector<K> GetKeys(const std::map<K, V>& m)
	{
		std::vector<K> v;
		typename map<K, V>::const_iterator itr = m.begin();
		for (; itr != m.end(); itr++)
		{
			v.push_back(itr->first);
		}

		return v;
	}

	template <typename K, class V>
	std::vector<V> GetValues(const std::map<K, V>& m)
	{
		std::vector<V> v;
		typename map<K, V>::const_iterator itr = m.begin();
		for (; itr != m.end(); itr++)
		{
			v.push_back(itr->second);
		}
		return v;
	}

	template <typename T>
	std::vector<T> Reverse(const std::vector<T>& v)
	{
		std::vector<T> rv;

		/*typename vector<T>::reverse_iterator itr = v.rbegin();
		for (; itr != v.rend(); itr++)
		{
			rv.push_back(*itr);
		}*/

		typename vector<T>::const_iterator itr = v.end() - 1;
		for (; ; itr--)
		{
			rv.push_back(*itr);
			if (itr == v.begin())
			{
				break;
			}
		}

		return rv;
	}

	template <typename T>
	std::vector<T> operator+(const std::vector<T>& v1, const std::vector<T>& v2)
	{
		std::vector<T> combined;
		combined.reserve(v1.size() + v2.size());
		for (size_t i = 0; i < v1.size(); i++)
		{
			combined.push_back(v1[i]);
		}

		for (size_t i = 0; i < v2.size(); i++)
		{
			combined.push_back(v2[i]);
		}

		sort(combined.begin(), combined.end());
		combined.erase(unique(combined.begin(), combined.end()), combined.end());

		return combined;
	}

	template <typename K, class V>
	std::map<K, V> operator+(const std::map<K, V>& m1, const std::map<K, V>& m2)
	{
		std::map<K, V> combined;
		typename map<K, V>::const_iterator itr1 = m1.begin();
		for (; itr1 != m1.end(); itr1++)
		{
			combined.insert(pair<K, V>(itr1->first, itr1->second));
		}

		typename map<K, V>::const_iterator itr2 = m2.begin();
		for (; itr2 != m2.end(); itr2++)
		{
			combined.insert(pair<K, V>(itr2->first, itr2->second));
		}

		return combined;
	}

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
	{
		for (size_t i = 0; i < v.size(); i++)
		{
			os << v[i] << ", ";
		}
		return os;
	}

	template <typename K, class V>
	std::ostream& operator<<(std::ostream& os, const std::map<K, V>& m)
	{
		typename map<K, V>::const_iterator itr = m.begin();
		for (; itr != m.end(); itr++)
		{
			os << "{ " << itr->first << ", " << itr->second << " }" << endl;
		}
		return os;
	}
}