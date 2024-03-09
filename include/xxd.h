#ifndef XXD_H
#define XXD_H

#ifdef _WIN32
#ifdef libxxd_EXPORTS
#define XXD_EMBED_API __declspec(dllexport)
#else
#define XXD_EMBED_API __declspec(dllimport)
#endif
#else
#define XXD_EMBED_API
#endif

#include <string>

namespace xxd {

// Add an entry to the index of embedded resources (internal).
XXD_EMBED_API void add(const std::string& name, const char* content, size_t size, const std::string& mime);

// Get an entry from the index of embedded resources.
XXD_EMBED_API const char* get(const std::string& name, size_t* size = nullptr, std::string* mime = nullptr);

} // namespace xxd

#endif // XXD_H

