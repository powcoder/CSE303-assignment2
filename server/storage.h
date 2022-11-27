https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder
https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder
#pragma once

#include <memory>
#include <string>
#include <utility>

#include "../common/bytevec.h"

/// Storage is the main object managed by the server.  It provides access to two
/// concurrent maps.  The first is an authentication table.  The authentication
/// table holds user names, salts, and hashed passwords, as well as a single
/// bytevec of content per user.  The second is a key/value store that can be
/// accessed by all threads.
///
/// The public interface of Storage provides functions that correspond 1:1 with
/// the data requests that a client can make.  In that manner, the server
/// command handlers need only parse a request, send its parts to the Storage
/// object, and then format and return the result.
///
/// Note that the functions that correspond to client requests all return a
/// tuple, consisting of a bool, a string, and a bytevec.  When the bool is
/// *false*, it means that the operation did not succeed, and the string is an
/// error message that can be sent to the client.  When the bool is *true*, it
/// means that the operation succeeded.  In this case the string is mostlikely
/// RES_OK, and the bytevec, if not empty, is additional data to send to the
/// client.
class Storage {
  /// Internal is the class that stores all the members of a Storage object.  To
  /// avoid pulling too much into the .h file, we are using the PIMPL pattern
  /// (https://www.geeksforgeeks.org/pimpl-idiom-in-c-with-examples/)
  struct Internal;

  /// A reference to the internal fields of the Storage object
  std::unique_ptr<Internal> fields;

public:
  /// Result_t is the tuple that is sent to the caller after any operation
  /// requested by a client.
  struct result_t {
    bool succeeded;  // True if the operation succeeded, false otherwise
    std::string msg; // The message to send to the client
    bytevec data;    // Optional additional content to return to the client
  };

  /// Construct an empty object and specify the file from which it should be
  /// loaded.  To avoid exceptions and errors in the constructor, the act of
  /// loading data is separate from construction.
  ///
  /// @param fname   The name of the file to use for persistence
  /// @param buckets The number of buckets in the hash table
  Storage(const std::string &fname, size_t buckets);

  /// Destructor for the storage object.
  ~Storage();

  /// Populate the Storage object by loading this.filename.  Note that
  /// load_file() begins by clearing the maps, so that when the call is
  /// complete, exactly and only the contents of the file are in the Storage
  /// object.
  ///
  /// @return A result tuple, as described above.  Note that a non-existent file
  ///         is not an error.
  result_t load_file();

  /// Create a new entry in the Auth table.  If the user already exists, return
  /// an error.  Otherwise, create a salt, hash the password, and then save an
  /// entry with the username, salt, hashed password, and a zero-byte content.
  ///
  /// @param user The user name to register
  /// @param pass The password to associate with that user name
  ///
  /// @return A result tuple, as described above
  result_t add_user(const std::string &user, const std::string &pass);

  /// Set the data bytes for a user, but do so if and only if the password
  /// matches
  ///
  /// @param user    The name of the user whose content is being set
  /// @param pass    The password for the user, used to authenticate
  /// @param content The data to set for this user
  ///
  /// @return A result tuple, as described above
  result_t set_user_data(const std::string &user, const std::string &pass,
                         const bytevec &content);

  /// Return a copy of the user data for a user, but do so only if the password
  /// matches
  ///
  /// @param user The name of the user who made the request
  /// @param pass The password for the user, used to authenticate
  /// @param who  The name of the user whose content is being fetched
  ///
  /// @return A result tuple, as described above.  Note that "no data" is an
  ///         error
  result_t get_user_data(const std::string &user, const std::string &pass,
                         const std::string &who);

  /// Return a newline-delimited string containing all of the usernames in the
  /// auth table
  ///
  /// @param user The name of the user who made the request
  /// @param pass The password for the user, used to authenticate
  ///
  /// @return A result tuple, as described above
  result_t get_all_users(const std::string &user, const std::string &pass);

  /// Authenticate a user
  ///
  /// @param user The name of the user who made the request
  /// @param pass The password for the user, used to authenticate
  ///
  /// @return A result tuple, as described above
  result_t auth(const std::string &user, const std::string &pass);

  /// Write the entire Storage object to the file specified by this.filename.
  /// To ensure durability, Storage must be persisted in two steps.  First, it
  /// must be written to a temporary file (this.filename.tmp).  Then the
  /// temporary file can be renamed to replace the older version of the Storage
  /// object.
  ///
  /// @return A result tuple, as described above
  result_t save_file();

  /// Create a new key/value mapping in the table
  ///
  /// @param user The name of the user who made the request
  /// @param pass The password for the user, used to authenticate
  /// @param key  The key whose mapping is being created
  /// @param val  The value to copy into the map
  ///
  /// @return A result tuple, as described above
  result_t kv_insert(const std::string &user, const std::string &pass,
                     const std::string &key, const bytevec &val);

  /// Get a copy of the value to which a key is mapped
  ///
  /// @param user The name of the user who made the request
  /// @param pass The password for the user, used to authenticate
  /// @param key  The key whose value is being fetched
  ///
  /// @return A result tuple, as described above
  result_t kv_get(const std::string &user, const std::string &pass,
                  const std::string &key);

  /// Delete a key/value mapping
  ///
  /// @param user The name of the user who made the request
  /// @param pass The password for the user, used to authenticate
  /// @param key  The key whose value is being deleted
  ///
  /// @return A result tuple, as described above
  result_t kv_delete(const std::string &user, const std::string &pass,
                     const std::string &key);

  /// Insert or update, so that the given key is mapped to the give value
  ///
  /// @param user The name of the user who made the request
  /// @param pass The password for the user, used to authenticate
  /// @param key  The key whose mapping is being upserted
  /// @param val  The value to copy into the map
  ///
  /// @return A result tuple, as described above.  Note that there are two "OK"
  ///         messages, depending on whether we get an insert or an update.
  result_t kv_upsert(const std::string &user, const std::string &pass,
                     const std::string &key, const bytevec &val);

  /// Return all of the keys in the kv_store, as a "\n"-delimited string
  ///
  /// @param user The name of the user who made the request
  /// @param pass The password for the user, used to authenticate
  ///
  /// @return A result tuple, as described above
  result_t kv_all(const std::string &user, const std::string &pass);

  /// Shut down the storage when the server stops.  This method needs to close
  /// any open files related to incremental persistence.  It also needs to clean
  /// up any state related to .so files.  This is only called when all threads
  /// have stopped accessing the Storage object.
  void shutdown();
};
