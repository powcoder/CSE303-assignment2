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
#include <vector>

/// bytevec is a short name for a vector of unsigned chars, so that we don't
/// have to clutter by writing `std::vector<unsigned char>` over and over again.
/// bytevec also serves as a reminder that "vector of char" doesn't mean
/// "string" or even "characters", and most of the code in this application
/// should not be thinking of these vectors as being characters/strings.
typedef std::vector<unsigned char> bytevec;

/// Create a bytevec from the contents of a string
///
/// @param s The string to copy
///
/// @return A bytevec
bytevec bytevec_from_string(const std::string &s);

/// Append the contents of a string to the end of a bytevec
///
/// @param v The bytevec to which we will append
/// @param s The string to append to the end of the bytevec
///
/// @return The bytevec that was passed in as "v"
bytevec append(bytevec &v, const std::string &s);

/// Append the contents of one bytevec to another bytevec
///
/// @param to   The bytevec into which we should copy
/// @param from The bytevec from which to copy
///
/// @return The bytevec that was passed in as "to"
bytevec append(bytevec &to, const bytevec &from);

/// Append a binary representation of an integer to the end of a bytevec
///
/// @param v The bytevec into which we should append
/// @param i The integer to put into the bytevec
///
/// @return The bytevec that was passed in as "v"
bytevec append(bytevec &v, int i);
