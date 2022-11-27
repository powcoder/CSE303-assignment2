https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder
https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder
#pragma once

#include <openssl/pem.h>

#include "bytevec.h"

/// size of an RSA key
const int RSA_KEYSIZE = 2048;

/// size of an AES key
const int AES_KEYSIZE = 32;

/// size of an AES initialization vector
const int AES_IVSIZE = 16;

/// Size of blocks that get encrypted
const int AES_BLOCKSIZE = 1024;

/// Load an RSA public key from the given filename
///
/// @param filename The name of the file that has the public key in it
///
/// @return An RSA context for encrypting with the provided public key, or
///         nullptr on error
RSA *load_pub(const char *filename);

/// Run the AES symmetric encryption/decryption algorithm on a bytevec.  Note
/// that this will do either encryption or decryption, depending on how the
/// provided CTX has been configured.  After calling, the CTX cannot be used
/// again until it is reset.
///
/// @param ctx The pre-configured AES context to use for this operation
/// @param msg A bytevec to encrypt/decrypt
///
/// @return A bytevec with the encrypted or decrypted result, or an empty
///         bytevec if there was an error
bytevec aes_crypt_msg(EVP_CIPHER_CTX *ctx, const bytevec &msg);

/// Run the AES symmetric encryption/decryption algorithm on a string. Note that
/// this will do either encryption or decryption, depending on how the provided
/// CTX has been configured.  After calling, the CTX cannot be used again until
/// it is reset.
///
/// @param ctx The pre-configured AES context to use for this operation
/// @param msg A string to encrypt/decrypt
///
/// @return A bytevec with the encrypted or decrypted result, or an empty
///         bytevec if there was an error
bytevec aes_crypt_msg(EVP_CIPHER_CTX *ctx, const std::string &msg);

/// Create an AES key.  A key is two parts, the key itself, and the
/// initialization vector.  Each is just random bits.  Our key will be a stream
/// of random bits, long enough to be split into the actual key and the iv.
///
/// @return A bytevec holding the key and iv bits, or an empty bytevec on error
bytevec create_aes_key();

/// Create an aes context for doing a single encryption or decryption.  The
/// context must be reset after each full encrypt/decrypt.
///
/// @param key     A bytevec holding the bits of the key and iv
/// @param encrypt true to encrypt, false to decrypt
///
/// @return An AES context for doing encryption.  Note that the context can be
///         reset in order to re-use this object for another encryption.
EVP_CIPHER_CTX *create_aes_context(const bytevec &key, bool encrypt);

/// Reset an existing AES context, so that we can use it for another
/// encryption/decryption
///
/// @param ctx     The AES context to reset
/// @param key     A vector holding the bits of the key and iv.  Should be
///                generated by create_aes_key().
/// @param encrypt true to create an encryption context, false to create a
///                decryption context
///
/// @return false on error, true if the context is reset and ready to use again
bool reset_aes_context(EVP_CIPHER_CTX *ctx, bytevec &key, bool encrypt);

/// When an AES context is done being used, call this to reclaim its memory
///
/// @param ctx The context to reclaim
void reclaim_aes_context(EVP_CIPHER_CTX *ctx);

/// If the given basename resolves to basename.pri and basename.pub, then load
/// basename.pri and return it.  If one or the other doesn't exist, then there's
/// an error.  If both don't exist, create them and then load basename.pri.
///
/// @param basename The basename of the .pri and .pub files for RSA
///
/// @return The RSA context from loading the private file, or nullptr on error
RSA *init_RSA(const std::string &basename);