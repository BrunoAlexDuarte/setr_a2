# Set the source files that make up the library
set(UNITY_SRCS
   unity.h unity.c
   unity_internals.h
)

# Set the library type (can be static or dynamic)
SET (LIB_TYPE STATIC)

# Create the library
add_library (UnityLib ${LIB_TYPE} ${UNITY_SRCS})
