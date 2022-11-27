# Build a client and server from the reference solution, but use the student's
# concurrenthashtable and server/storage.cc.

# The executables will have the suffix p2.nopool.exe
EXESUFFIX = p2.nopool.exe

# Names for building the client
CLIENT_MAIN     = client
CLIENT_CXX      = # no client/*.cc files needed for this build
CLIENT_COMMON   = # no common/*.cc files needed for this build
CLIENT_PROVIDED = client crypto err file net pool bytevec requests

# Names for building the server
SERVER_MAIN     = server
SERVER_CXX      = concurrenthashtable storage
SERVER_COMMON   = # no common/*.cc files needed for this build
SERVER_PROVIDED = server responses crypto err file net bytevec parsing pool

# Names for building the benchmark executable
BENCH_MAIN = # No benchmarks are built by this build
BENCH_CXX  = # No benchmarks are built by this build

# Names for building shared objects (one .so per SO_CXX)
SO_CXX    = # No shared objects are built by this build
SO_COMMON = # No shared objects are built by this build

# All warnings should be treated as errors
CXXEXTRA = -Werror -Wextra

# Pull in the common build rules
include common.mk
