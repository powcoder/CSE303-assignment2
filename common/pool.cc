https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder
https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder
#include <atomic>
#include <condition_variable>
#include <functional>
#include <iostream> // Shouldn't be needed once everything is working
#include <queue>
#include <thread>
#include <unistd.h>

#include "pool.h"

using namespace std;

/// thread_pool::Internal is the class that stores all the members of a
/// thread_pool object. To avoid pulling too much into the .h file, we are using
/// the PIMPL pattern
/// (https://www.geeksforgeeks.org/pimpl-idiom-in-c-with-examples/)
struct thread_pool::Internal {

  // INSTRUCTOR NOTE: YOU WILL NEED TO ADD FIELDS TO THIS STRUCT

  /// construct the Internal object by setting the fields that are
  /// user-specified
  ///
  /// @param handler The code to run whenever something arrives in the pool
  Internal(function<bool(int)> handler) {}

  /// Each thread in the pool runs thread_task() to get new sockets from the
  /// queue and run the handler on them.  When threads can't get something, they
  /// wait on a condvar.
  void thread_task() {}
};

/// construct a thread pool by providing a size and the function to run on
/// each element that arrives in the queue
///
/// @param size    The number of threads in the pool
/// @param handler The code to run whenever something arrives in the pool
thread_pool::thread_pool(int size, function<bool(int)> handler)
    : fields(new Internal(handler)) {
  cout << "thread pool constructor is not implemented" << endl;
}

/// destruct a thread pool
thread_pool::~thread_pool() = default;

/// Allow a user of the pool to provide some code to run when the pool decides
/// it needs to shut down.
///
/// @param func The code that should be run when the pool shuts down
void thread_pool::set_shutdown_handler(function<void()> func) {
  cout << "set_shutdown_handler is not implemented" << endl;
}

/// Allow a user of the pool to see if the pool has been shut down
bool thread_pool::check_active() {
  cout << "check_active is not implemented" << endl;
  return false;
}

/// Shutting down the pool can take some time.  await_shutdown() lets a user
/// of the pool wait until the threads are all done servicing clients.
void thread_pool::await_shutdown() {
  cout << "await_shutdown is not implemented" << endl;
}

/// When a new connection arrives at the server, it calls this to pass the
/// connection to the pool for processing.
///
/// @param sd The socket descriptor for the new connection
void thread_pool::service_connection(int sd) {
  cout << "service_connection is not implemented" << endl;
}
