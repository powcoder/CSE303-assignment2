https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder
https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder
#include <iostream> // this shouldn't be needed once everything is implemented
#include <mutex>

#include "concurrenthashtable.h"

/// A bucket_t is a lockable unordered_map of key/value pairs
template <typename K, typename V> struct ConcurrentHashTable<K, V>::bucket_t {
  // INSTRUCTOR NOTE: YOU WILL NEED TO ADD FIELDS TO THIS STRUCT
};

/// Construct a concurrent hash table by specifying the number of buckets it
/// should have
///
/// @param _buckets The number of buckets in the concurrent hash table
template <typename K, typename V>
ConcurrentHashTable<K, V>::ConcurrentHashTable(size_t _buckets)
    : num_buckets(_buckets) {
  std::cout << "ConcurrentHashTable constructor is not implemented"
            << std::endl;
}

/// Clear the Concurrent Hash Table.  This operation needs to use 2pl
template <typename K, typename V> void ConcurrentHashTable<K, V>::clear() {
  std::cout << "clear is not implemented" << std::endl;
}

/// Insert the provided key/value pair only if there is no mapping for the key
/// yet.
///
/// @param key The key to insert
/// @param val The value to insert
///
/// @return true if the key/value was inserted, false if the key already
///         existed in the table
template <typename K, typename V>
bool ConcurrentHashTable<K, V>::insert(K key, V val) {
  std::cout << "insert is not implemented" << std::endl;
  return false;
}

/// Insert the provided key/value pair if there is no mapping for the key yet.
/// If there is a key, then update the mapping by replacing the old value with
/// the provided value
///
/// @param key The key to upsert
/// @param val The value to upsert
///
/// @return true if the key/value was inserted, false if the key already
///         existed in the table and was thus updated instead
template <typename K, typename V>
bool ConcurrentHashTable<K, V>::upsert(K key, V val) {
  std::cout << "upsert is not implemented" << std::endl;
  return false;
}

/// Apply a function to the value associated with a given key.  The function
/// is allowed to modify the value.
///
/// @param key The key whose value will be modified
/// @param f   The function to apply to the key's value
///
/// @return true if the key existed and the function was applied, false
///         otherwise
template <typename K, typename V>
bool ConcurrentHashTable<K, V>::do_with(K key, std::function<void(V &)> f) {
  std::cout << "do_with is not implemented" << std::endl;
  return false;
}

/// Apply a function to the value associated with a given key.  The function
/// is not allowed to modify the value.
///
/// @param key The key whose value will be modified
/// @param f   The function to apply to the key's value
///
/// @return true if the key existed and the function was applied, false
///         otherwise
template <typename K, typename V>
bool ConcurrentHashTable<K, V>::do_with_readonly(
    K key, std::function<void(const V &)> f) {
  std::cout << "do_with_readonly is not implemented" << std::endl;
  return false;
}

/// Remove the mapping from a key to its value
///
/// @param key The key whose mapping should be removed
///
/// @return true if the key was found and the value unmapped, false otherwise
template <typename K, typename V>
bool ConcurrentHashTable<K, V>::remove(K key) {
  std::cout << "remove is not implemented" << std::endl;
  return false;
}

/// Apply a function to every key/value pair in the ConcurrentHashTable.  Note
/// that the function is not allowed to modify keys or values.
///
/// @param f    The function to apply to each key/value pair
/// @param then A function to run when this is done, but before unlocking...
///             useful for 2pl
template <typename K, typename V>
void ConcurrentHashTable<K, V>::do_all_readonly(
    std::function<void(const K, const V &)> f, std::function<void()> then) {
  std::cout << "do_all_readonly is not implemented" << std::endl;
}
