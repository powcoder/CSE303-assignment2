https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder
https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <openssl/rand.h>
#include <openssl/sha.h>
#include <string>
#include <sys/wait.h>
#include <unistd.h>

#include "../common/contextmanager.h"
#include "../common/err.h"
#include "../common/protocol.h"

#include "authtableentry.h"
#include "concurrenthashtable.h"
#include "format.h"
#include "storage.h"

using namespace std;

/// Append a salt to a password, hash it, and return the result
///
/// @param pass The plain-text password to hash
/// @param salt The salt to use with the password
///
/// @return The hash of the salted password
bytevec hash_pass(string pass, bytevec salt) {
  cout << "hash_pass is not implemented" << endl;
  return {};
}

/// Storage::Internal is the private struct that holds all of the fields of the
/// Storage object.  Organizing the fields as an Internal is part of the PIMPL
/// pattern.
struct Storage::Internal {
  /// The map of authentication information, indexed by username
  ConcurrentHashTable<string, AuthTableEntry> auth_table;

  /// The map of key/value pairs
  ConcurrentHashTable<string, bytevec> kv_store;

  /// The name of the file from which the Storage object was loaded, and to
  /// which we persist the Storage object every time it changes
  string filename = "";

  /// Construct the Storage::Internal object by setting the filename and bucket
  /// count
  ///
  /// @param fname   The name of the file to use for persistence
  /// @param buckets The number of buckets in the hash table
  Internal(string fname, size_t buckets)
      : auth_table(buckets), kv_store(buckets), filename(fname) {}
};

/// Construct an empty object and specify the file from which it should be
/// loaded.  To avoid exceptions and errors in the constructor, the act of
/// loading data is separate from construction.
///
/// @param fname   The name of the file to use for persistence
/// @param buckets The number of buckets in the hash table
Storage::Storage(const string &fname, size_t num_buckets)
    : fields(new Internal(fname, num_buckets)) {
  cout << "Storage constructor is not implemented" << endl;
}

/// Destructor for the storage object.
///
/// NB: The compiler doesn't know that it can create the default destructor in
///     the .h file, because PIMPL prevents it from knowing the size of
///     Storage::Internal.  Now that we have reified Storage::Internal, the
///     compiler can make a destructor for us.
Storage::~Storage() = default;

/// Create a new entry in the Auth table.  If the user already exists, return an
/// error.  Otherwise, create a salt, hash the password, and then save an entry
/// with the username, salt, hashed password, and a zero-byte content.
///
/// @param user The user name to register
/// @param pass The password to associate with that user name
///
/// @return A result tuple, as described in storage.h
Storage::result_t Storage::add_user(const string &user, const string &pass) {
  cout << "add_user is not implemented" << endl;
  return {false, RES_ERR_UNIMPLEMENTED};
}

/// Set the data bytes for a user, but do so if and only if the password
/// matches
///
/// @param user    The name of the user whose content is being set
/// @param pass    The password for the user, used to authenticate
/// @param content The data to set for this user
///
/// @return A result tuple, as described in storage.h
Storage::result_t Storage::set_user_data(const string &user, const string &pass,
                                         const bytevec &content) {
  cout << "set_user_data is not implemented" << endl;
  return {false, RES_ERR_UNIMPLEMENTED};
}

/// Return a copy of the user data for a user, but do so only if the password
/// matches
///
/// @param user The name of the user who made the request
/// @param pass The password for the user, used to authenticate
/// @param who  The name of the user whose content is being fetched
///
/// @return A result tuple, as described in storage.h.  Note that "no data" is
///         an error
Storage::result_t Storage::get_user_data(const string &user, const string &pass,
                                         const string &who) {
  cout << "get_user_data is not implemented" << endl;
  return {false, RES_ERR_UNIMPLEMENTED};
}

/// Return a newline-delimited string containing all of the usernames in the
/// auth table
///
/// @param user The name of the user who made the request
/// @param pass The password for the user, used to authenticate
///
/// @return A result tuple, as described in storage.h
Storage::result_t Storage::get_all_users(const string &user,
                                         const string &pass) {
  cout << "get_all_users is not implemented" << endl;
  return {false, RES_ERR_UNIMPLEMENTED};
}

/// Authenticate a user
///
/// @param user The name of the user who made the request
/// @param pass The password for the user, used to authenticate
///
/// @return A result tuple, as described in storage.h
Storage::result_t Storage::auth(const string &user, const string &pass) {
  cout << "auth is not implemented" << endl;
  return {false, RES_ERR_UNIMPLEMENTED};
}

/// Create a new key/value mapping in the table
///
/// @param user The name of the user who made the request
/// @param pass The password for the user, used to authenticate
/// @param key  The key whose mapping is being created
/// @param val  The value to copy into the map
///
/// @return A result tuple, as described in storage.h
Storage::result_t Storage::kv_insert(const string &user, const string &pass,
                                     const string &key, const bytevec &val) {
  cout << "kv_insert is not implemented" << endl;
  return {false, RES_ERR_UNIMPLEMENTED};
};

/// Get a copy of the value to which a key is mapped
///
/// @param user The name of the user who made the request
/// @param pass The password for the user, used to authenticate
/// @param key  The key whose value is being fetched
///
/// @return A result tuple, as described in storage.h
Storage::result_t Storage::kv_get(const string &user, const string &pass,
                                  const string &key) {
  cout << "kv_get is not implemented" << endl;
  return {false, RES_ERR_UNIMPLEMENTED};
};

/// Delete a key/value mapping
///
/// @param user The name of the user who made the request
/// @param pass The password for the user, used to authenticate
/// @param key  The key whose value is being deleted
///
/// @return A result tuple, as described in storage.h
Storage::result_t Storage::kv_delete(const string &user, const string &pass,
                                     const string &key) {
  cout << "kv_delete is not implemented" << endl;
  return {false, RES_ERR_UNIMPLEMENTED};
};

/// Insert or update, so that the given key is mapped to the give value
///
/// @param user The name of the user who made the request
/// @param pass The password for the user, used to authenticate
/// @param key  The key whose mapping is being upserted
/// @param val  The value to copy into the map
///
/// @return A result tuple, as described in storage.h.  Note that there are two
///         "OK" messages, depending on whether we get an insert or an update.
Storage::result_t Storage::kv_upsert(const string &user, const string &pass,
                                     const string &key, const bytevec &val) {
  cout << "kv_upsert is not implemented" << endl;
  return {false, RES_ERR_UNIMPLEMENTED};
};

/// Return all of the keys in the kv_store, as a "\n"-delimited string
///
/// @param user The name of the user who made the request
/// @param pass The password for the user, used to authenticate
///
/// @return A result tuple, as described in storage.h
Storage::result_t Storage::kv_all(const string &user, const string &pass) {
  cout << "kv_all is not implemented" << endl;
  return {false, RES_ERR_UNIMPLEMENTED};
};

/// Shut down the storage when the server stops.  This method needs to close
/// any open files related to incremental persistence.  It also needs to clean
/// up any state related to .so files.  This is only called when all threads
/// have stopped accessing the Storage object.
void Storage::shutdown() { cout << "shutdown is not implemented" << endl; }

/// Write the entire Storage object to the file specified by this.filename. To
/// ensure durability, Storage must be persisted in two steps.  First, it must
/// be written to a temporary file (this.filename.tmp).  Then the temporary file
/// can be renamed to replace the older version of the Storage object.
///
/// @return A result tuple, as described in storage.h
Storage::result_t Storage::save_file() {
  cout << "save_file is not implemented" << endl;
  return {false, RES_ERR_UNIMPLEMENTED};
}

/// Populate the Storage object by loading this.filename.  Note that load()
/// begins by clearing the maps, so that when the call is complete, exactly and
/// only the contents of the file are in the Storage object.
///
/// @return A result tuple, as described in storage.h.  Note that a non-existent
///         file is not an error.
Storage::result_t Storage::load_file() {
  cout << "load_file is not implemented" << endl;
  return {false, RES_ERR_UNIMPLEMENTED};
}
