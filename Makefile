# Build a client and server using the student's files

# The executables will have the suffix .exe
EXESUFFIX = exe

# Names for building the client:
CLIENT_MAIN     = 
CLIENT_CXX      = 
CLIENT_COMMON   = 
CLIENT_PROVIDED = client requests crypto err file net bytevec

# Names for building the server
SERVER_MAIN     = server
SERVER_CXX      = server storage concurrenthashtable
SERVER_COMMON   = pool 
SERVER_PROVIDED = responses crypto err file net bytevec parsing

# Names for building the benchmark executable
BENCH_MAIN   = bench
BENCH_CXX    = bench bench_hashtable

# Names for building shared objects
SO_CXX    = # No shared objects are built by this build
SO_COMMON = # No shared objects are built by this build

# NB: This Makefile does not add extra CXXFLAGS

# Pull in the common build rules
include common.mk