#ifndef XXD_H
#define XXD_H

#include <map>
#include <memory>
#include <string>
#include <vector>

// Container for embedded content that shall be
// loaded and persist in memory during the server lifetime.
extern std::unique_ptr<std::map<std::string, std::pair<const char*, size_t> > > xxd;

// Container for embedded content MIME.
extern std::unique_ptr<std::map<std::string, std::string> > xxd_mime;

#endif // XXD_H

