https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder
https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder
#include <string>

#include "../common/bytevec.h"

#include "authtableentry.h"
#include "concurrenthashtable_impl.h"

using namespace std;

// instantiate the hash table in each of the three ways that is needed for this
// assignment
template class ConcurrentHashTable<string, AuthTableEntry>;
template class ConcurrentHashTable<string, bytevec>;