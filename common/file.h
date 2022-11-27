https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder
https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder
#pragma once

#include <string>

#include "bytevec.h"

/// Determine if a file exists.  Note that using this is not a good way to avoid
/// TOCTOU bugs, but it is acceptable for this class project.
///
/// @param filename The name of the file whose existence is being checked
///
/// @return true if the file exists, false otherwise
bool file_exists(const std::string &filename);

/// Load a file and return its contents
///
/// @param filename The name of the file to open
///
/// @return A bytevec with the file contents.  On error, returns an empty
///         bytevec
bytevec load_entire_file(const std::string &filename);

/// Create or truncate a file and populate it with the provided data
///
/// @param filename The name of the file to create/truncate
/// @param data     The data to write
/// @param bytes    The number of bytes of data to write
///
/// @return false on error, true if the file was written in full
bool write_file(const std::string &filename, const char *data, size_t bytes);
