#ifndef XXD_H
#define XXD_H

#include <string>

namespace xxd {

// Add an entry to the index of embedded resources (internal).
void add(const std::string& filename, const char* content, size_t size, const std::string& mime);

// Get an entry from the index of embedded resources.
const char* get(const std::string& filename, size_t* size = nullptr, std::string* mime = nullptr);

} // namespace xxd

#endif // XXD_H

