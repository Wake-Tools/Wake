#include <stddef.h>
#include <stdio.h>

static inline const char* fileutil_get_path(const char* filename, char* buf, size_t buf_size) {
    snprintf(buf, buf_size, "%s", filename);
    return buf;
}

