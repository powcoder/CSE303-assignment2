https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder
https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder
#pragma once

#include <functional>
#include <vector>

/// ConcurrentHashTable is a concurrent hash table (a Key/Value store).  It is
/// implemented as a vector of buckets, with one lock per bucket.  Since the
/// number of buckets is fixed, performance can suffer if the thread count is
/// high relative to the number of buckets.  Furthermore, the asymptotic
/// guarantees of this hashtable are dependent on the quality of the bucket
/// implementation.  If a vector is used within the bucket to store key/value
/// pairs, then the guarantees will be poor if the key range is large relative
/// to the number of buckets.  If an unordered_map is used, then the asymptotic
/// guarantees should be strong.
///
/// The ConcurrentHashTable is templated on the Key and Value types.
///
/// This hash table uses std::hash to map keys to positions in the vector.  A
/// production hash table should use something better.
///
/// This hash table provides strong consistency guarantees: every operation uses
/// two-phase locking (2PL), and the lambda parameters to methods enable nesting
/// of 2PL operations across hashtables.
///
/// @param K The type of the keys in this hash table
/// @param V The type of the values in this hash table
template <typename K, typename V> class ConcurrentHashTable {
  /// A lockable container of key/value pairs
  struct bucket_t;

  /// The number of buckets
  const size_t num_buckets;

  /// The vector of buckets.  Note that we store pointers to bucket_t, not
  /// bucket_t's themselves, so that locks are less likely to be on the same
  /// cache line.
  std::vector<bucket_t *> buckets;

public:
  /// Construct a concurrent hash table by specifying the number of buckets it
  /// should have
  ///
  /// @param _buckets The number of buckets in the concurrent hash table
  ConcurrentHashTable(size_t _buckets);

  /// Clear the Concurrent Hash Table.  This operation needs to use 2pl
  void clear();

  /// Insert the provided key/value pair only if there is no mapping for the key
  /// yet.
  ///
  /// @param key The key to insert
  /// @param val The value to insert
  ///
  /// @return true if the key/value was inserted, false if the key already
  ///         existed in the table
  bool insert(K key, V val);

  /// Insert the provided key/value pair if there is no mapping for the key yet.
  /// If there is a key, then update the mapping by replacing the old value with
  /// the provided value
  ///
  /// @param key The key to upsert
  /// @param val The value to upsert
  ///
  /// @return true if the key/value was inserted, false if the key already
  ///         existed in the table and was thus updated instead
  bool upsert(K key, V val);

  /// Apply a function to the value associated with a given key.  The function
  /// is allowed to modify the value.
  ///
  /// @param key The key whose value will be modified
  /// @param f   The function to apply to the key's value
  ///
  /// @return true if the key existed and the function was applied, false
  ///         otherwise
  bool do_with(K key, std::function<void(V &)> f);

  /// Apply a function to the value associated with a given key.  The function
  /// is not allowed to modify the value.
  ///
  /// @param key The key whose value will be modified
  /// @param f   The function to apply to the key's value
  ///
  /// @return true if the key existed and the function was applied, false
  ///         otherwise
  bool do_with_readonly(K key, std::function<void(const V &)> f);

  /// Remove the mapping from a key to its value
  ///
  /// @param key The key whose mapping should be removed
  ///
  /// @return true if the key was found and the value unmapped, false otherwise
  bool remove(K key);

  /// Apply a function to every key/value pair in the ConcurrentHashTable.  Note
  /// that the function is not allowed to modify keys or values.
  ///
  /// @param f    The function to apply to each key/value pair
  /// @param then A function to run when this is done, but before unlocking...
  ///             useful for 2pl
  void do_all_readonly(std::function<void(const K, const V &)> f,
                       std::function<void()> then);
};
