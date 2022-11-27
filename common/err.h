https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder
https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder
#pragma once

#include <iostream>
#include <string>

#include "bytevec.h"

/// Create a string representation of the error message associated with the
/// given errno
///
/// @param err The error number to use when producing an error message
///
/// @return A string representing the error message
std::string msg_from_errno(int err);

/// A helper function for printing an error and returning nullptr
///
/// @param msg1 The message to print
/// @param msg2 More of the message to print
/// @param msg3 More of the message to print
///
/// @return A nullptr of type T*
template <typename T>
__attribute__((warn_unused_result)) T *
ptrErr(const char *msg1, const char *msg2 = "", const char *msg3 = "") {
  std::cout << msg1 << msg2 << msg3 << std::endl;
  return nullptr;
}

/// A helper function for printing an error and returning false
///
/// @param msg1 The message to print
/// @param msg2 More of the message to print
/// @param msg3 More of the message to print
///
/// @return false
__attribute__((warn_unused_result)) bool
falseErr(const char *msg1, const char *msg2 = "", const char *msg3 = "");

/// A helper function for printing an error and returning an empty bytevec
///
/// @param msg1 The message to print
/// @param msg2 More of the message to print
/// @param msg3 More of the message to print
///
/// @return an empty bytevec
__attribute__((warn_unused_result)) bytevec
bytevecErr(const char *msg1, const char *msg2 = "", const char *msg3 = "");

/// A helper function for printing an error and returning an integer
///
/// @param num  The integer number to return
/// @param msg1 The message to print
/// @param msg2 More of the message to print
/// @param msg3 More of the message to print
///
/// @return the given integer
__attribute__((warn_unused_result)) int
intErr(int num, const char *msg1, const char *msg2 = "", const char *msg3 = "");

/// A helper function for printing a string and returning an integer
///
/// @param s    The string to return
/// @param msg1 The message to print
/// @param msg2 More of the message to print
/// @param msg3 More of the message to print
///
/// @return the given integer
__attribute__((warn_unused_result)) std::string strError(std::string s,
                                                         const char *msg1,
                                                         const char *msg2 = "",
                                                         const char *msg3 = "");