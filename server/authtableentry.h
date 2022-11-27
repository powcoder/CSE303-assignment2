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

#include "../common/bytevec.h"

/// AuthTableEntry represents one user stored in the authentication table
struct AuthTableEntry {
  std::string username; // The name of the user
  bytevec salt;         // The salt to use with the password
  bytevec pass_hash;    // The hashed password
  bytevec content;      // The user's content
};
